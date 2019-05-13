//
// Created by gosha on 20.04.19.
//

#include "Footprint.h"

Footprint::Footprint()
{
}

Footprint::Footprint( const std::set<Event*, myClassComp>& allEvents, const std::set<Trace*, myClassComp>& eventLog)
{
    int index = 0;
    // assign each of the events an index in the matrix
    for (Event* event : allEvents) {
        event_to_index.insert({event->get_event(), index});
        index_to_event[index] = event;
        ++index;
    }

    n = allEvents.size();
    // In the beginning there were no connections
    footprint.resize(n, std::vector < RelationType > (n, NOT_CONNECTED));

    std :: vector < Event *> eventsList;
    for (Trace* singleTrace : eventLog) {
        eventsList.clear();
        eventsList = singleTrace->get_events();
        for (int i = 0; i < eventsList.size() - 1; i++)
        {
                // currentEventNumber is followed by nextEventNumber in some
                // trace
                int currentEventNumber = event_to_index[eventsList[i]->get_event()];
                int nextEventNumber = event_to_index[eventsList[i + 1]->get_event()];
                // if this is the first time these two have been
                // found next to each other
                if (footprint[currentEventNumber][nextEventNumber] == NOT_CONNECTED)
                {
                    footprint[currentEventNumber][nextEventNumber] = PRECEDES;
                    footprint[nextEventNumber][currentEventNumber] = FOLLOWS;
                } else if (footprint[currentEventNumber][nextEventNumber] == FOLLOWS)
                {
                    // if nextEventNumber was before currEventNumber
                    // in some trace
                    footprint[currentEventNumber][nextEventNumber] = PARALLEL;
                    footprint[nextEventNumber][currentEventNumber] = PARALLEL;
                }
                // if some of the other relation types are at this position,
                // they are not changed
        }
    }
}


void Footprint::dfs(int v, std::vector <bool > &used, std::set<Event *, myClassComp> &comp)
{
    used[v] = true;
    comp.insert(index_to_event[v]);
    for (int i = 0; i < n; i++)
    {
        if (!used[i] && footprint[v][i] != NOT_CONNECTED)
            dfs(i, used, comp);
    }
}




void Footprint::dfs_reverse(int v, std::vector <bool > &used, std::vector < int > &rules)
{
    used[v] = true;
    for (int i = 0; i < n; i++)
    {
        if (!used[i] && (footprint[v][i] == FOLLOWS || footprint[v][i] == PARALLEL))
            dfs_reverse(i, used, rules);
    }
    rules.push_back(v);
}


void Footprint::dfs_sequence(int v, std::vector <bool > &used, std::set<Event *, myClassComp> &comp)
{
    used[v] = true;
    comp.insert(index_to_event[v]);
    for (int i = 0; i < n; i++)
    {
        if (!used[i] && (footprint[v][i] == PRECEDES || footprint[v][i] == PARALLEL))
            dfs_sequence(i, used, comp);
    }
}


void Footprint::dfs_parallel(int v, std::vector <bool > &used, std::set<Event *, myClassComp> &comp)
{
    used[v] = true;
    comp.insert(index_to_event[v]);
    for (int i = 0; i < n; i++)
    {
        if (!used[i] && footprint[v][i] != PARALLEL)
            dfs_parallel(i, used, comp);
    }
}


void Footprint::dfs_loop(int v, std::vector <bool > &used, std::set<Event *, myClassComp> &comp, int start, int finish)
{
    used[v] = true;
    comp.insert(index_to_event[v]);
    if (v == finish)
        return;
    for (int i = 0; i < n; i++)
    {
        if (i == start)
            continue;
        if (!used[i] && (footprint[v][i] == PARALLEL || footprint[v][i] == PRECEDES))
            dfs_loop(i, used, comp, start, finish);
    }
}


void Footprint::has_path(int v, std::vector <bool > &visited, int finish, bool &flag)
{
    if (v == finish)
    {
        flag = true;
        return;
    }
    visited[v] = true;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (footprint[v][i] == PARALLEL || footprint[v][i] == PRECEDES))
            has_path(i, visited, finish, flag);
    }
}


std::vector<std::set<Event *, myClassComp> >
Footprint::get_component(std::set<Event *, myClassComp> starts, std::set<Event *, myClassComp> ends)
{
    std::vector < bool > used(n, false);
    std::vector<std::set<Event *, myClassComp> > ans;
    std::set<Event *, myClassComp> comp;
    bool has_start, has_finish;
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            has_finish = has_start = false;
            comp.clear();
            dfs(i, used, comp);
            for (Event* event : comp)
            {
                if (starts.find(event) != starts.end())
                    has_start = true;
                if (ends.find(event) != ends.end())
                    has_finish = true;
            }
            if (has_finish && has_start)
                ans.push_back(comp);
            else
                return std::vector<std::set<Event *, myClassComp> > ();
        }
    }
    return ans;
}


std::vector<std::set<Event *, myClassComp> > Footprint::get_sequence_component()
{

    std::vector < bool > used(n, false);
    std::vector < int > rules;
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
            dfs_reverse(i, used, rules);
    }
    used.clear();
    used.resize(n, false);
    std::vector<std::set<Event *, myClassComp> > ans;
    std::set<Event *, myClassComp> comp;
    std::vector < bool > visited(n, false);
    bool flag, flag1;
    bool new_comp;
    std::reverse(rules.begin(), rules.end());
    for (int i : rules)
    {
        if (!used[i])
        {
            comp.clear();
            dfs_sequence(i, used, comp);
            new_comp = true;
            for (int i = 0; i < ans.size(); i++)
            {
                flag = flag1 = false;
                visited.clear();
                visited.resize(n, false);
                has_path(event_to_index[(*ans[i].begin())->get_event()], visited, event_to_index[(*comp.begin())->get_event()], flag);
                visited.clear();
                visited.resize(n, false);
                has_path(event_to_index[(*comp.begin())->get_event()], visited, event_to_index[(*ans[i].begin())->get_event()], flag1);
                if (!flag && !flag1)
                {
                    new_comp = false;
                    for (Event* event : comp)
                        ans[i].insert(event);
                    break;
                }
            }
            if (new_comp)
                ans.push_back(comp);
        }
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
}

std::vector<std::set<Event *, myClassComp> > Footprint::get_parallel_component( std::set<Event *, myClassComp> starts, std::set<Event *, myClassComp> ends)
{
    std::vector < bool > used(n, false);
    std::vector<std::set<Event *, myClassComp> > ans;
    std::set<Event *, myClassComp> comp;
    bool has_start, has_finish;
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            comp.clear();
            dfs_parallel(i, used, comp);
            has_finish = has_start = false;
            for (Event* event : comp)
            {
                if (starts.find(event) != starts.end())
                    has_start = true;
                if (ends.find(event) != ends.end())
                    has_finish = true;
            }
            if (has_finish && has_start)
                ans.push_back(comp);
            else
                return std::vector<std::set<Event *, myClassComp> > ();
        }
    }
    return ans;
}


//TODO start-finish
std::vector<std::set<Event *, myClassComp> > Footprint::get_loop_component(std::set<Event *, myClassComp> starts, std::set<Event *, myClassComp> ends)
{
    std::vector<std::set<Event *, myClassComp> > res;
    std::vector<bool> used;
    std::vector<std::set<Event *, myClassComp> > ans;
    std::set<Event *, myClassComp> comp;
    bool valid, error;
    Event* st;
    for (Event* start_ev : starts)
    {
        st = start_ev;
        for (Event* end_ev : ends)
        {
            used.clear();
            used.resize(n, false);
            int start = event_to_index[start_ev->get_event()];
            int finish = event_to_index[end_ev->get_event()];
            comp.clear();
            ans.clear();
            valid = false;
            for (int i = 0; i < n; i++)
            {
                if (!used[i])
                {
                    comp.clear();
                    dfs_loop(i, used, comp, start, finish);
                    ans.push_back(comp);
                    error = false;
                    for (Event* start_ev2 : starts)
                    {
                        if (comp.find(start_ev2) == comp.end())
                            error = true;
                    }
                    for (Event *end_ev2 : ends)
                    {
                        if (comp.find(end_ev2) == comp.end())
                            error = true;
                    }
                    if (!error)
                        valid = true;
                }
            }
            if (valid && ans.size() > res.size())
                res = ans;
        }
    }
    for (int i = 0; i < res.size(); i++)
    {
        if (i && res[i].find(st) != res[i].end())
        {
            swap(res[0], res[i]);
            break;
        }
    }
    return res;
}
