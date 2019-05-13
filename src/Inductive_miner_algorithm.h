//
// Created by gosha on 13.05.19.
//

#ifndef KURSACH_INDUCTIVE_MINER_ALGORITHM_H
#define KURSACH_INDUCTIVE_MINER_ALGORITHM_H


#include "tools/Trace.h"
#include "tools/Footprint.h"
#include "components/Component.h"

class Inductive_miner_algorithm
{
public:
    Inductive_miner_algorithm(){empty = new Event("#");}
    string algorithm_B(const set < Trace*, myClassComp >& Log);
    Component* algorithm_B_graph(const set < Trace*, myClassComp >& Log);
    pair < string, vector < set < Trace*, myClassComp > > > b_select(const set <Trace*, myClassComp > &Log, Footprint* graph,
                                                                     const set < Event*, myClassComp  >& first_events, const set < Event*, myClassComp  >& last_events);
    ~Inductive_miner_algorithm(){delete empty;}
private:
    Event* empty;
};


#endif //KURSACH_INDUCTIVE_MINER_ALGORITHM_H
