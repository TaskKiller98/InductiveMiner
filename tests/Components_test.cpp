#include <gtest/gtest.h>
#include <components/Node.h>


TEST(CompTest, Node)
{
    Node* p = new Node("a");
    EXPECT_EQ("a", p->get_event());
    EXPECT_EQ("square", p->get_shape());
    delete p;
}


TEST(CompTest, Component_exclusive)
{
    Node* p = new Node("a");
    EXPECT_EQ("a", p->get_event());
    EXPECT_EQ("square", p->get_shape());
    delete p;
}