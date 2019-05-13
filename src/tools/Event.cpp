//
// Created by gosha on 20.04.19.
//

#include "Event.h"


Event::Event()
{

}

Event::Event(std::string event)
{
    set_event(event);
}

void Event::set_event(std::string event)
{
    this->event = event;
}

std::string Event::get_event() const
{
    return event;
}


bool Event::operator<(const Event *event1)
{
    return event < event1->event;
}
