//
// Created by gosha on 12.05.19.
//

#include "Component.h"


Component::Component(Node *a)
{
    start = a;
    finish = a;
}


Component::Component(Node *start, Node *finish)
{
    this->start = start;
    this->finish = finish;
}


Node *Component::get_start()
{
    return start;
}

Node *Component::get_finish()
{
    return finish;
}


void Component::replace(Node *was, Node *will)
{
    for (Node* child : was->get_child())
    {
        child->remove_parent(was);
        was->remove_child(child);
        will->make_edge(child);
    }
    for (Node* parent : was->get_parent())
    {
        was->remove_parent(parent);
        parent->remove_child(was);
        parent->make_edge(will);
    }
    delete was;
}

void Component::add_component(string operation, Component component)
{
    Node* comp_start = component.get_start();
    Node* comp_finish = component.get_finish();
    if (operation == "X")
    {
        if (comp_start->get_shape() == "circle")
        {
            replace(comp_start, start);
        }
        else
            start->make_edge(comp_start);
        if (comp_finish->get_shape() == "circle")
        {
            replace(comp_finish, finish);
        }
        else
            comp_finish->make_edge(finish);
    }
    if (operation == ">")
    {
        if (finish->get_shape() == comp_start->get_shape())
        {
            if (finish->get_shape() == "square" && !finish->is_empty() && !comp_start->is_empty())
            {
                Node* proxy = new Node();
                finish->make_edge(proxy);
                proxy->make_edge(comp_start);
            }
            else if (finish->get_shape() == "square" && finish->is_empty())
            {
                replace(finish, comp_start);
            }
            else
            {
                replace(comp_start, finish);
            }
        }
        else
        {
            finish->make_edge(comp_start);
        }
        finish = comp_finish;
    }
    if (operation == "^")
    {
        if (comp_start->get_shape() == "square")
        {
            Node* proxy = new Node();
            start->make_edge(proxy);
            proxy->make_edge(comp_start);
        }
        else
            start->make_edge(comp_start);
        if (comp_finish->get_shape() == "square")
        {
            Node* proxy = new Node();
            proxy->make_edge(finish);
            comp_finish->make_edge(proxy);
        }
        else
            comp_finish->make_edge(finish);
    }
    if (operation == "@")
    {
        if (start->get_child().empty())
        {
            if (comp_start->get_shape() == "circle")
            {
                replace(comp_start, start);
            }
            else
                start->make_edge(comp_start);
            if (comp_finish->get_shape() == "circle")
            {
                replace(comp_finish, finish);
            }
            else
                comp_finish->make_edge(finish);
        }
        else
        {
            if (comp_start->get_shape() == "circle")
            {
                replace(comp_start, start);
            }
            else
                finish->make_edge(comp_start);
            if (comp_finish->get_shape() == "circle")
            {
                replace(comp_finish, finish);
            }
            else
                comp_finish->make_edge(start);
        }
    }
}


