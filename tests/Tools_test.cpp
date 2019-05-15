#include <gtest/gtest.h>
#include "tools/Event.h"
#include <string>
#include <map>
#include <tools/Trace.h>
#include <fstream>
#include <tools/Footprint.h>


TEST(ToolsTest, Event)
{
    Event* p = new Event("a");
    EXPECT_EQ("a", p->get_event());
    delete p;
}


TEST(ToolsTest, Trace)
{
    Event* event1 = new Event("a");
    Event* event2 = new Event("b");
    Trace* trace = new Trace();
    trace->add_event(event1);
    trace->add_event(event2);
    EXPECT_EQ("a", trace->get_first_event()->get_event());
    EXPECT_EQ("b", trace->get_last_event()->get_event());
    EXPECT_EQ("a", trace->get_event(0)->get_event());
    EXPECT_TRUE(trace->has_event(event1));
    EXPECT_EQ(2, trace->get_size());
    trace->reset();
    EXPECT_EQ(0, trace->get_size());
    delete trace;
    delete event1;
    delete event2;
}

using namespace std;

set < Trace*, myClassComp > traces;
set < Event*, myClassComp  > first_events, last_events;
Footprint* graph;

void create_footprint(const string& filename)
{
    ifstream fin("../../tests/resource/" + filename);
    set < Event*, myClassComp  > all_events;
    string buff;
    while (fin >> buff)
        traces.insert(new Trace(buff));
    for (Trace* trace : traces)
    {
        first_events.insert(trace->get_first_event());
        last_events.insert(trace->get_last_event());
        for (Event *event : trace->get_events())
            all_events.insert(event);
    }
     graph = new Footprint(all_events, traces);

}

void delete_footprint()
{
    for (Trace* trace : traces)
        delete trace;
    traces.clear();
    first_events.clear();
    last_events.clear();
    delete graph;
}

TEST(ToolsTest, footprint_loop)
{
    create_footprint("loop");
    vector < set < Event*, myClassComp  > > cut = graph->get_loop_component(first_events, last_events);
    EXPECT_EQ(2, cut.size());
    EXPECT_EQ(2, cut[0].size());
    EXPECT_EQ(1, cut[1].size());
    EXPECT_EQ("f", (*cut[1].begin())->get_event());
    delete_footprint();
}


TEST(ToolsTest, footprint_parallel)
{
    create_footprint("parallel");
    vector < set < Event*, myClassComp  > > cut = graph->get_parallel_component(first_events, last_events);
    EXPECT_EQ(2, cut.size());
    EXPECT_EQ(1, cut[0].size());
    EXPECT_EQ(1, cut[1].size());
    EXPECT_EQ("c", (*cut[1].begin())->get_event());
    delete_footprint();
}


TEST(ToolsTest, footprint_sequence)
{
    create_footprint("sequence");
    vector < set < Event*, myClassComp  > > cut = graph->get_sequence_component();
    EXPECT_EQ(2, cut.size());
    EXPECT_EQ(1, cut[0].size());
    EXPECT_EQ(1, cut[1].size());
    EXPECT_EQ("b", (*cut[1].begin())->get_event());
    delete_footprint();
}



TEST(ToolsTest, footprint_exclusive)
{
    create_footprint("exclusive");
    vector < set < Event*, myClassComp  > > cut = graph->get_component(first_events, last_events);
    EXPECT_EQ(2, cut.size());
    EXPECT_EQ(1, cut[0].size());
    EXPECT_EQ(1, cut[1].size());
    EXPECT_EQ("a", (*cut[0].begin())->get_event());
    delete_footprint();
}