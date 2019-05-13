//
// Created by gosha on 20.04.19.
//

#include "Trace.h"

Trace::Trace()
{
    size = 0;
}


Trace::Trace(std::string log)
{
    size = 0;
    val = log;
    convert_from_string(log);
}

Trace::Trace(const Trace &trace)
{
    size = trace.size;
    val = trace.val;
    for (int i = 0; i < size; i++)
        events.push_back(trace.get_event(i));
}

void Trace::set_events(std::vector<Event *> &events)
{
    size = 0;
    for (int i = 0; i < size; i++)
        add_event(events[i]);
}

void Trace::set_event(Event* event, int i)
{
    if (i >= size)
        throw std::out_of_range("trying to set event in position" + std::to_string(i) +
        ", but trace size = " + std::to_string(size));
    events[i] = event;
}

Event *Trace::get_event(int i) const
{
    return events[i];
}

void Trace::add_event(Event* event)
{
    events.push_back(event);
    size++;
}

size_t Trace::get_size() const
{
    return size;
}

Trace::~Trace()
{
    for (Event* ev : events)
        delete ev;
}


void Trace::convert_from_string(std::string log)
{
    std::string ev_str = "";
    for (int i = 0 ; i < log.size(); i++)
    {
        if (log[i] == ',')
        {
            add_event(new Event(ev_str));
            ev_str = "";
        }
        else
            ev_str += log[i];
    }
    if (ev_str != "")
        add_event(new Event(ev_str));
}

bool Trace::has_event(Event *event)
{
    for (int i = 0; i < size; i++)
        if (events[i]->get_event() == event->get_event())
            return true;
    return false;
}

void Trace::reset()
{
    size = 0;
    events.clear();
}

std::vector<Event *> Trace::get_events() const
{
    return events;
}

Event *Trace::get_last_event() const
{
    return get_event(size - 1);
}

Event *Trace::get_first_event() const
{
    return get_event(0);
}

std::string Trace::get_string() const
{
    std::string res;
    for (Event* event : events)
        res = res + event->get_event() + ",";
    return res;
}
