//
// Created by gosha on 10.05.19.
//

#include "Node.h"

using namespace chrono;
int num = 0;
Node::Node()
{

    nanoseconds ms = duration_cast< nanoseconds >(
            system_clock::now().time_since_epoch()
    );
    event = "p" + to_string(++num);
    shape = "circle";
    used = false;
}

Node::Node(string event, string shape, string color)
{
    this->event = event;
    this->color = color;
    this->shape = shape;
}

Node::Node(string event)
{
    this->event = event;
    this->shape = "square";
    used = false;
}

Node::Node(string event, string shape)
{
    this->event = event;
    this->shape = shape;
    used = false;
}


void Node::add_child(Node *a)
{
    child.insert(a);
}


void Node::add_parent(Node *a)
{
    parent.insert(a);
}

void Node::make_edge(Node *child)
{
    child->parent.insert(this);
    add_child(child);
}

void Node::remove_child(Node *child)
{
    this->child.erase(child);
}

void Node::remove_parent(Node *parent)
{
    this->parent.erase(parent);
}
