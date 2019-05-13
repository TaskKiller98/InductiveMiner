//
// Created by gosha on 10.05.19.
//

#ifndef KURSACH_NODE_H
#define KURSACH_NODE_H

#include <vector>
#include <string>
#include "Event.h"


using namespace std;

#include <set>
#include <stdio.h>
#include <time.h>
#include <chrono>


class Node
{
    struct myClassComp1 {
        bool operator() (const Node* lhs, const Node* rhs) {
            return lhs->get_event() < rhs->get_event();
        }
    };

public:
    Node();
    Node(string event);
    Node(string event, string shape);
    Node(string event, string shape, string color);
    void add_child(Node* a);
    void add_parent(Node* a);
    string get_shape() { return shape;}
    bool is_empty() { return color == "black";}
    string get_event() const { return event;}
    set < Node* , myClassComp1> get_child(){ return child;}
    set < Node* , myClassComp1 > get_parent(){ return parent;}
    bool is_used() { return used;}
    void set_used() {used = true;}
    void make_edge(Node* child);
    void remove_child(Node* child);
    void remove_parent(Node* parent);
    void set_start(){event = "start";}
    void set_end(){event = "end";}
    string get_color(){ return color;}
private:
    string shape;
    string event;
    string color;
    set < Node* , myClassComp1> child;
    set < Node*, myClassComp1 > parent;
    bool used;
};

#endif //KURSACH_NODE_H
