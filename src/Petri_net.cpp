//
// Created by gosha on 10.05.19.
//

#include "Petri_net.h"


Petri_net::Petri_net(Component component)
{
    if (component.get_finish()->get_shape() == "square" || !component.get_finish()->get_child().empty())
    {
        if (component.get_finish()->get_shape() != "square")
            component.add_component(">", Component(new Node(std::to_string(rand()), "square", "black")));
        component.add_component(">", Component(new Node()));
    }
    if (component.get_start()->get_shape() == "square" || !component.get_start()->get_parent().empty())
    {
        Component component1(new Node());
        if (component.get_start()->get_shape() != "square")
            component1.add_component(">", Component(new Node(std::to_string(rand()), "square", "black")));
        component1.add_component(">", component);
        component1.get_start()->set_start();
        component1.get_finish()->set_end();
        dfs(component1.get_start());
    }
    else
    {
        component.get_start()->set_start();
        component.get_finish()->set_end();
        dfs(component.get_start());
    }
}

void Petri_net::dfs(Node *v)
{
    v->set_used();
    all_nodes.insert(v);
    for (Node* to : v->get_child())
    {
        edges.insert({v, to});
        if (!to->is_used())
            dfs(to);
    }
}

string Petri_net::to_string()
{
    string res = "digraph G {\n";
    for (Node *node : all_nodes)
    {
        if (node->get_color() != "")
            res += node->get_event() + "[shape=" + node->get_shape() + ",style=filled,color=black];\n";
        else
            res += node->get_event() + "[shape=" + node->get_shape() + "];\n";
    }
    for (pair <Node*, Node* > p : edges)
    {
        res += p.first->get_event() + " -> " + p.second->get_event() + ";\n";
    }
    res += "}";
    return res;
}
