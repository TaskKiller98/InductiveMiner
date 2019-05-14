//
// Created by gosha on 13.05.19.
//

#include "Inductive_miner_algorithm.h"


pair<string, vector<set<Trace *, myClassComp> > >
Inductive_miner_algorithm::b_select(const set<Trace *, myClassComp> &Log, Footprint *graph,
                                    const set<Event *, myClassComp> &first_events,
                                    const set<Event *, myClassComp> &last_events)
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
        bool next;
        Event* before;
        Event* after;
        set < Event*, myClassComp > already;
        for (set < Event*, myClassComp > comp : cut)
        {
            new_log.clear();
            next = false;
            for (Trace *trace : Log)
            {
                int n = trace->get_size();
                for (int l = 0; l < n; l++)
                {
                    if (l)
                        before = trace->get_event(l - 1);
                    else
                        before = nullptr;
                    for (int r = l + 1; r < n; r++)
                    {
                        if (r < n)
                            after = trace->get_event(r);
                        else
                            after = nullptr;
                        tr->reset();
                        for (int i = l; i < r; i++)
                        {
                            if (comp.find(trace->get_event(i)) != comp.end())
                                tr->add_event(trace->get_event(i));
                        }
                        if (tr->get_size() == r - l && (before == nullptr || comp.find(before) == comp.end()) && (after == nullptr || comp.find(after) == comp.end()))
                        {
                            new_log.insert(new Trace(*tr));
                        }
                    }
                }
            }
            new_logs.push_back(new_log);
        }
        tr->reset();
        delete tr;
        return {"@", new_logs};
    }
    return {"o", new_logs};
}

string Inductive_miner_algorithm::algorithm_B(const set<Trace *, myClassComp> &Log)
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
            return  "Incorrect!";
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

Component *Inductive_miner_algorithm::algorithm_B_graph(const set<Trace *, myClassComp> &Log)
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
