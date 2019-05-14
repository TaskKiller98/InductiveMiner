#include <iostream>
#include <fstream>
#include <set>
#include "tools/Event.h"
#include "tools/Trace.h"
#include "tools/Footprint.h"
#include "components/Component.h"
#include "components/Petri_net.h"
#include "Inductive_miner_algorithm.h"


using namespace std;

//set для удаления

int main()
{
    ifstream fin("../input/input.ind");
    set < Trace*, myClassComp > traces;
    string buff;
    while (fin >> buff)
        traces.insert(new Trace(buff));
    Inductive_miner_algorithm* inductiveMinerAlgorithm = new Inductive_miner_algorithm();
    ofstream fout2("../res/Model.txt");
    fout2 << inductiveMinerAlgorithm->algorithm_B(traces)<< endl;
    Component* comp = inductiveMinerAlgorithm->algorithm_B_graph(traces);
    Petri_net petriNet(*comp);
    ofstream fout("../res/Petri_net.dot");

    fout << petriNet.to_string();
    for (Trace* trace : traces)
        delete trace;
    delete comp;
    delete inductiveMinerAlgorithm;
    fin.close();
    fout.close();
    fout2.close();
    return 0;
}