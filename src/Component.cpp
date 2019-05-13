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

void Component::add_component(string operation, Component component)
{
    Node* comp_start = component.get_start();
    Node* comp_finish = component.get_finish();
    if (operation == "X")
    {
        if (comp_start->get_shape() == "circle")
        {
            for (Node* child : comp_start->get_child())
            {
                child->remove_parent(comp_start);
                comp_start->remove_child(child);
                start->make_edge(child);
            }
            for (Node* parent : comp_start->get_parent())
            {
                comp_start->remove_parent(parent);
                parent->remove_child(comp_start);
                parent->make_edge(start);
            }
            delete comp_start;
        }
        else
            start->make_edge(comp_start);
        if (comp_finish->get_shape() == "circle")
        {
            for (Node* child : comp_finish->get_child())
            {
                child->remove_parent(comp_finish);
                comp_finish->remove_child(child);
                finish->make_edge(child);
            }
            for (Node* parent : comp_finish->get_parent())
            {
                parent->remove_child(comp_finish);
                comp_finish->remove_parent(parent);
                parent->make_edge(finish);
            }
            delete comp_finish;
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
            else
            {
                for (Node* child : comp_start->get_child())
                {
                    child->remove_parent(comp_start);
                    comp_start->remove_child(child);
                    finish->make_edge(child);
                }
                for (Node* parent : comp_start->get_parent())
                {
                    comp_start->remove_parent(parent);
                    parent->remove_child(comp_start);
                    parent->make_edge(finish);
                }
                delete comp_start;
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
                for (Node* child : comp_start->get_child())
                {
                    child->remove_parent(comp_start);
                    comp_start->remove_child(child);
                    start->make_edge(child);
                }
                for (Node* parent : comp_start->get_parent())
                {
                    comp_start->remove_parent(parent);
                    parent->remove_child(comp_start);
                    parent->make_edge(start);
                }
                delete comp_start;
            }
            else
                start->make_edge(comp_start);
            if (comp_finish->get_shape() == "circle")
            {
                for (Node* child : comp_finish->get_child())
                {
                    child->remove_parent(comp_finish);
                    comp_finish->remove_child(child);
                    finish->make_edge(child);
                }
                for (Node* parent : comp_finish->get_parent())
                {
                    parent->remove_child(comp_finish);
                    comp_finish->remove_parent(parent);
                    parent->make_edge(finish);
                }
                delete comp_finish;
            }
            else
                comp_finish->make_edge(finish);
        }
        else
        {
            if (comp_start->get_shape() == "circle")
            {
                for (Node* child : comp_start->get_child())
                {
                    child->remove_parent(comp_start);
                    comp_start->remove_child(child);
                    start->make_edge(child);
                }
                for (Node* parent : comp_start->get_parent())
                {
                    comp_start->remove_parent(parent);
                    parent->remove_child(comp_start);
                    parent->make_edge(start);
                }
                delete comp_start;
            }
            else
                finish->make_edge(comp_start);
            if (comp_finish->get_shape() == "circle")
            {
                for (Node* child : comp_finish->get_child())
                {
                    child->remove_parent(comp_finish);
                    comp_finish->remove_child(child);
                    finish->make_edge(child);
                }
                for (Node* parent : comp_finish->get_parent())
                {
                    parent->remove_child(comp_finish);
                    comp_finish->remove_parent(parent);
                    parent->make_edge(finish);
                }
                delete comp_finish;
            }
            else
                comp_finish->make_edge(start);
        }
    }
}


