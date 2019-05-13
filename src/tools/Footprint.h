//
// Created by gosha on 20.04.19.
//

#ifndef KURSACH_FOOTPRINT_H
#define KURSACH_FOOTPRINT_H


#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include "Trace.h"
#include "../components/Node.h"


struct myClassComp {
    bool operator() (const Trace* lhs, const Trace* rhs) {
        return lhs->get_string() < rhs->get_string();
    }
    bool operator() (const Event* lhs, const Event* rhs) {
        return lhs->get_event() < rhs->get_event();
    }
    bool operator() (const Node* lhs, const Node* rhs) {
        return lhs->get_event() < rhs->get_event();
    }
};


class Footprint
{
public:
    Footprint();
    Footprint( const std::set<Event*, myClassComp>& allEvents, const std::set<Trace*, myClassComp>& eventLog);
    ~Footprint() = default;
    void dfs(int v, std::vector < bool > &used, std::set < Event * , myClassComp> &comp);
    std::vector < std::set < Event*, myClassComp >  > get_component( std::set<Event *, myClassComp> starts, std::set<Event *, myClassComp> ends);
    std::vector < std::set < Event*, myClassComp >  > get_sequence_component();
    std::vector < std::set < Event*, myClassComp >  > get_parallel_component(std::set<Event *, myClassComp> starts, std::set<Event *, myClassComp> ends);
    std::vector < std::set < Event*, myClassComp >  > get_loop_component(std::set<Event *, myClassComp> starts, std::set<Event *, myClassComp> ends);
    void dfs_reverse(int v, std::vector <bool > &used, std::vector < int > &rules);
    void dfs_sequence(int v, std::vector <bool > &used, std::set<Event *, myClassComp> &comp);
    void dfs_parallel(int v, std::vector <bool > &used, std::set<Event *, myClassComp> &comp);
    void dfs_loop(int v, std::vector <bool > &used, std::set<Event *, myClassComp> &comp, int start, int finish);
    void has_path(int v, std::vector <bool > &visited, int finish, bool &flag);
private:
    enum RelationType
    {
        PRECEDES = '>',
        // <-
        FOLLOWS = '<',
        // ||
        PARALLEL = '|',
        // #
        NOT_CONNECTED = '#'
    };
    std::vector < std::vector < RelationType > > footprint;
    std::map <std::string, int > event_to_index;
    std::map < int, Event* > index_to_event;
    int n;
};


#endif //KURSACH_FOOTPRINT_H
