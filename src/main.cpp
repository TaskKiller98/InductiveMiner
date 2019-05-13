#include <iostream>
#include <fstream>
#include <set>

#include "Footprint.h"
#include "Petri_net.h"
#include "Component.h"

using namespace std;


/*set < set < Event*, myClassComp >  > split_log(set <Event*, myClassComp > log, Footprint* &graph, vector < Event * > start, vector < Event* > finish)
{
    set < set < Event*, myClassComp >  > res_set;
    vector < Event* > newstart, newfinish;
    if (log.size() == 1)
    {
        res_set.insert(log);
        return res_set;
    }
    set < set < Event*, myClassComp >  > cut = graph->get_component(log);
    if (cut.size() <= 1)
        cut = graph->get_sequence_component(log);
    if (cut.size() <= 1)
        cut = graph->get_parallel_component(log);
    //loop needs start and finish!!!
    if (cut.size() <= 1)
    {
        cut = graph->get_loop_component(log, *start.end(), *finish.end());
    }
    if (cut.size() > 1)
    {
        for (set <Event*, myClassComp > sublog : cut)
        {
            for (set <Event*, myClassComp > sublogans : split_log(sublog, graph))
                res_set.insert(sublogans);
        }
        return res_set                                          ;
    }
    return res_set;
}*/

Event* empty;


pair < string, vector < set < Trace*, myClassComp > > > b_select(const set <Trace*, myClassComp > &Log, Footprint* graph,
        const set < Event*, myClassComp  >& first_events, const set < Event*, myClassComp  >& last_events)
{
    vector < set < Event*, myClassComp >  > cut = graph->get_component(first_events, last_events);
    vector < set < Trace*, myClassComp > > new_logs;
    set < Trace*, myClassComp > new_log;
    if (cut.size() > 1)
    {
        for (const set < Event*, myClassComp >& comp : cut)
        {
            new_log.clear();
            for (Event* event : comp)
            {
                for (Trace* trace : Log)
                {
                    if (trace->has_event(event))
                        new_log.insert(trace);
                }
            }
            new_logs.push_back(new_log);
        }
        return {"X", new_logs};
    }
    cut = graph->get_sequence_component();
    if (cut.size() > 1)
    {
        Trace* tr = new Trace();
        for (set < Event*, myClassComp > comp : cut)
        {
            new_log.clear();
            for (Trace *trace : Log)
            {
                tr->reset();
                for (Event *event : trace->get_events())
                {
                    if (comp.find(event) != comp.end())
                        tr->add_event(event);
                }
                if (!tr->get_size())
                    tr->add_event(empty);
                new_log.insert(new Trace(*tr));
            }
            new_logs.push_back(new_log);
        }
        tr->reset();
        delete tr;
        return {">", new_logs};
    }
    cut = graph->get_parallel_component(first_events, last_events);
    if (cut.size() > 1)
    {
        Trace* tr = new Trace();
        for (set < Event*, myClassComp > comp : cut)
        {
            new_log.clear();
            for (Trace *trace : Log)
            {
                tr->reset();
                for (Event *event : trace->get_events())
                {
                    if (comp.find(event) != comp.end())
                        tr->add_event(event);
                }
                if (!tr->get_size())
                    tr->add_event(empty);
                new_log.insert(new Trace(*tr));
            }
            new_logs.push_back(new_log);
        }
        tr->reset();
        delete tr;
        return {"^", new_logs};
    }
    cut = graph->get_loop_component(first_events, last_events);
    if (cut.size() > 1){
        Trace* tr = new Trace();
        set < Event*, myClassComp > already;
        for (set < Event*, myClassComp > comp : cut)
        {
            new_log.clear();
            for (Trace *trace : Log)
            {
                tr->reset();
                already.clear();
                for (Event *event : trace->get_events())
                {
                    if (comp.find(event) != comp.end() && already.find(event) == already.end())
                    {
                        tr->add_event(event);
                        already.insert(event);
                    }
                }
                if (tr->get_size())
                    new_log.insert(new Trace(*tr));
            }
            new_logs.push_back(new_log);
        }
        tr->reset();
        delete tr;
        return {"@", new_logs};
    }
    return {"o", new_logs};
}


string algorithm_B(const set < Trace*, myClassComp >& Log)
{
    string base;
    if (Log.empty())
        base = "tao";
    else {
        for (Trace* t : Log){
            if (t->get_size() == 1)
                base = t->get_event(0)->get_event();
        }
    }
    set < Event*, myClassComp  > first_events, last_events, all_events;
    for (Trace* trace : Log)
    {
        first_events.insert(trace->get_first_event());
        last_events.insert(trace->get_last_event());
        for (Event *event : trace->get_events())
            all_events.insert(event);
    }
    Footprint* graph = new Footprint(all_events, Log);
    pair < string, vector < set < Trace*, myClassComp > > > p = b_select(Log, graph, first_events, last_events);
    string operation = p.first;
    vector < set < Trace*, myClassComp > > new_logs = p.second;
    if (new_logs.empty())
    {
        if (base.empty())
            return  "Kek!";
        else
            return base;
    }
    string res = operation + "(";
    for (const set < Trace*, myClassComp >& new_log : new_logs)
    {
        res += algorithm_B(new_log) + ",";
    }
    res[res.size() - 1] = ')';
    delete graph;
    return res;
}



Component* algorithm_B_graph(const set < Trace*, myClassComp >& Log)
{
    string base;
    if (Log.empty())
        base = "tao";
    else {
        for (Trace* t : Log){
            if (t->get_size() == 1)
                base = t->get_event(0)->get_event();
        }
    }
    set < Event*, myClassComp  > first_events, last_events, all_events;
    for (Trace* trace : Log)
    {
        first_events.insert(trace->get_first_event());
        last_events.insert(trace->get_last_event());
        for (Event *event : trace->get_events())
            all_events.insert(event);
    }
    Footprint* graph = new Footprint(all_events, Log);
    pair < string, vector < set < Trace*, myClassComp > > > p = b_select(Log, graph, first_events, last_events);
    string operation = p.first;
    vector < set < Trace*, myClassComp > > new_logs = p.second;
    if (new_logs.empty())
    {
        if (base.empty())
            return  new Component(new Node("Incorrect"));
        else
        {
            if (base == "#")
                return new Component(new Node(to_string(rand()), "square", "black"));
            return new Component(new Node(base));
        }
    }
    Node* start;
    Node* finish;
    if (operation == "X")
    {
        start = new Node();
        finish = new Node();
        Component* component = new Component(start, finish);
        for (const set < Trace*, myClassComp >& new_log : new_logs)
        {
            component->add_component(operation, *algorithm_B_graph(new_log));
        }
        return component;
    }
    if (operation == ">")
    {
        start = new Node();
        Component* component = new Component(start);
        for (const set < Trace*, myClassComp >& new_log : new_logs)
        {
            component->add_component(operation, *algorithm_B_graph(new_log));
        }
        return component;
    }
    if (operation == "^")
    {
        start = new Node(to_string(rand()), "square", "black");
        finish = new Node(to_string(rand()), "square", "black");
        Component* component = new Component(start, finish);
        for (const set < Trace*, myClassComp >& new_log : new_logs)
        {
            component->add_component(operation, *algorithm_B_graph(new_log));
        }
        return component;
    }
    if (operation == "@")
    {
        start = new Node();
        finish = new Node();
        Component* component = new Component(start, finish);
        for (const set < Trace*, myClassComp >& new_log : new_logs)
        {
            component->add_component(operation, *algorithm_B_graph(new_log));
        }
        return component;
    }
    delete graph;
    return new Component(start);
}



int main()
{
    ifstream fin("../../resource/input.txt");
    set < Trace*, myClassComp > traces;
    string buff;
    while (fin >> buff)
        traces.insert(new Trace(buff));
  /*  for (Trace* trace : traces)
    {
        first_events.insert(trace->get_first_event());
        last_events.insert(trace->get_last_event());
        for (Event *event : trace->get_events())
            all_events.insert(event);
    }
    Footprint* footprint = new Footprint(all_events, traces);
    set < set < Event*, myClassComp > > kek = powerSet(all_events);*/
    empty = new Event("#");
    cout << algorithm_B(traces)<< endl;
    Component* comp = algorithm_B_graph(traces);
    Petri_net petriNet(*comp);
    cout << petriNet.to_string();
    for (Trace* trace : traces)
        delete trace;
    delete empty;
    delete comp;
    fin.close();
    return 0;
}