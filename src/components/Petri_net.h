//
// Created by gosha on 10.05.19.
//

#ifndef KURSACH_PETRI_NET_H
#define KURSACH_PETRI_NET_H


#include <set>
#include "Node.h"
#include "../tools/Footprint.h"
#include "Component.h"

class Petri_net
{
public:
    Petri_net(Component component);
    void dfs(Node* v);
    set < pair < Node* , Node* > > edges;
    set <Node*, myClassComp> all_nodes;
};


#endif //KURSACH_PETRI_NET_H
