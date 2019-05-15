#include <gtest/gtest.h>
#include <components/Node.h>
#include <components/Component.h>


TEST(CompTest, Node)
{
    Node* p = new Node("a");
    EXPECT_EQ("a", p->get_event());
    EXPECT_EQ("square", p->get_shape());
    delete p;
}


TEST(CompTest, Component_exclusive)
{
    Component* component = new Component(new Node(), new Node());
    Node* p = new Node("a");
    Component*component1 = new Component(p);
    component->add_component("X", *component1);
    Node* p2 = new Node("b");
     component1 = new Component(p2);
    component->add_component("X", *component1);
    EXPECT_EQ(component->get_start()->get_shape(), "circle");
    EXPECT_EQ(component->get_finish()->get_shape(), "circle");
    EXPECT_EQ(2, component->get_start()->get_child().size());
    EXPECT_EQ(2, component->get_finish()->get_parent().size());
    delete component->get_start();
    delete component->get_finish();
    delete p2;
    delete p;
    delete component;
    delete component1;
}


TEST(CompTest, Component_sequence)
{
    Component* component = new Component(new Node());
    Node* p = new Node("a");
    Component*component1 = new Component(p);
    component->add_component(">", *component1);
    Node* p2 = new Node("b");
    component1 = new Component(p2);
    component->add_component(">", *component1);
    EXPECT_EQ(component->get_start()->get_shape(), "circle");
    EXPECT_EQ(component->get_finish()->get_shape(), "square");
    EXPECT_EQ(1, component->get_start()->get_child().size());
    EXPECT_EQ(1, component->get_finish()->get_parent().size());
    delete component->get_start();
    delete p2;
    delete p;
    delete component;
    delete component1;
}


TEST(CompTest, Component_parallel)
{
    Component* component = new Component(new Node(to_string(rand()), "square", "black"), new Node(to_string(rand()), "square", "black"));
    Node* p = new Node("a");
    Component*component1 = new Component(p);
    component->add_component("^", *component1);
    Node* p2 = new Node("b");
    component1 = new Component(p2);
    component->add_component("^", *component1);
    EXPECT_EQ(component->get_start()->get_shape(), "square");
    EXPECT_EQ(component->get_finish()->get_shape(), "square");
    EXPECT_EQ(2, component->get_start()->get_child().size());
    EXPECT_EQ((*component->get_start()->get_child().begin())->get_shape(), "circle");
    EXPECT_EQ(2, component->get_finish()->get_parent().size());
    delete component->get_start();
    delete component->get_finish();
    delete p2;
    delete p;
    delete component;
    delete component1;
}


TEST(CompTest, Component_loop)
{
    Component* component = new Component(new Node(), new Node());
    Node* p = new Node("a");
    Component*component1 = new Component(p);
    component->add_component("@", *component1);
    Node* p2 = new Node("b");
    component1 = new Component(p2);
    component->add_component("@", *component1);
    EXPECT_EQ(component->get_start()->get_shape(), "circle");
    EXPECT_EQ(component->get_finish()->get_shape(), "circle");
    EXPECT_EQ(1, component->get_start()->get_child().size());
    EXPECT_EQ(1, component->get_finish()->get_parent().size());
    delete component->get_start();
    delete component->get_finish();
    delete p2;
    delete p;
    delete component;
    delete component1;
}