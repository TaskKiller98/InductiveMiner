#include <iostream>
#include <fstream>
#include <set>
#include <grpcpp/create_channel.h>
#include <grpcpp/server_builder.h>
#include <logs.grpc.pb.h>
#include <mining.grpc.pb.h>
#include "tools/Event.h"
#include "tools/Trace.h"
#include "tools/Footprint.h"
#include "components/Component.h"
#include "components/Petri_net.h"
#include "Inductive_miner_algorithm.h"


using namespace std;

class InductiveMiner : public mining::MiningAlgorithm::Service {
public:
    InductiveMiner(const shared_ptr<grpc::Channel>& channel) {
        this->logs = logs::Logs::NewStub(channel);
    }

    ::grpc::Status AnalyzeOffline(::grpc::ServerContext* context, const ::logs::Project* request, ::petri_net::PetriNet* response) override {
        set < Trace*, myClassComp > traces;

        grpc::ClientContext clientContext;
        logs::Traces projectTraces;
        this->logs->GetTracesOfProject(&clientContext, *request, &projectTraces);

        for (const auto & projectTrace : projectTraces.traces()) {
            Trace* trace = new Trace();
            for (const auto & projectLog : projectTrace.logs()) {
                trace->add_event(new Event(projectLog.action()));
            }
            traces.insert(trace);
        }

        Inductive_miner_algorithm* inductiveMinerAlgorithm = new Inductive_miner_algorithm();
        inductiveMinerAlgorithm->algorithm_B(traces);
        Component* comp = inductiveMinerAlgorithm->algorithm_B_graph(traces);

        Petri_net petriNet(*comp);
        for (auto node : petriNet.all_nodes) {
            if (node->get_shape() == "square")
            {
                auto transition = response->add_transitions();
                transition->set_name(node->get_event());
            } else
            {
                auto place = response->add_places();
                place->set_name(node->get_event());

                for (auto edge : petriNet.edges)
                {
                    if (edge.first->get_event() == node->get_event()) {
                        auto outgoingTransition = place->add_outgoingtransitions();
                        outgoingTransition->set_name(edge.second->get_event());
                    }

                    if (edge.second->get_event() == node->get_event()) {
                        auto incomingTransition = place->add_incomingtransitions();
                        incomingTransition->set_name(edge.first->get_event());
                    }
                }
            }
        }

        for (Trace* trace : traces)
            delete trace;
        delete comp;
        delete inductiveMinerAlgorithm;
        return grpc::Status::OK;
    }

private:
    unique_ptr<logs::Logs::Stub> logs;
};

int main()
{
    shared_ptr<grpc::Channel> channel = grpc::CreateChannel("localhost:8080", grpc::InsecureChannelCredentials());
    unique_ptr<mining::MiningRegistry::Stub> miningRegistry = mining::MiningRegistry::NewStub(channel);

    grpc::ClientContext context;
    mining::AlgorithmRegistration request;
    request.mutable_algorithm()->set_name("Inductive");
    request.set_offline(true);
    request.set_online(false);
    request.set_address("localhost:8082");
    google::protobuf::Empty response;

    InductiveMiner minerService(channel);

    grpc::ServerBuilder serverBuilder;
    serverBuilder.AddListeningPort("localhost:8082", grpc::InsecureServerCredentials());
    serverBuilder.RegisterService(&minerService);
    unique_ptr<grpc::Server> server = serverBuilder.BuildAndStart();

    miningRegistry->RegisterAlgorithm(&context, request, &response);
    server->Wait();

    return 0;
}