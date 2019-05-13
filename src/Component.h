//
// Created by gosha on 12.05.19.
//

#ifndef KURSACH_COMPONENT_H
#define KURSACH_COMPONENT_H


#include "Node.h"

class Component
{
public:
    Component(Node* a);
    Component(Node* start, Node* finish);
    Node* get_start();
    Node* get_finish();
    void add_component(string operation, Component component);
private:
    Node* start;
    Node* finish;
};


#endif //KURSACH_COMPONENT_H
