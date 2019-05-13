//
// Created by gosha on 20.04.19.
//

#ifndef KURSACH_TRACE_H
#define KURSACH_TRACE_H


#include <vector>
#include "Event.h"
#include <stdexcept>

class Trace
{
public:
    Trace();
    Trace(std::string log);
    Trace(const Trace& trace);
    //Trace(std::vector < Event* > events);
    void set_events(std::vector < Event* > &events);
    void set_event(Event* event, int i);
    Event* get_event(int i) const;
    std:: vector < Event* > get_events() const;
    bool operator < (const Trace* rhs) {
        return this->get_string() < rhs->get_string();
    }
    Event* get_last_event() const;
    Event* get_first_event() const;
    void add_event(Event* event);
    bool has_event(Event* event);
    size_t get_size() const;
    void convert_from_string(std::string log);
    void reset();
    ~Trace();
    std::string get_string() const;


private:
    std::vector < Event* > events;
    std::string val;
    size_t size;
};


#endif //KURSACH_TRACE_H
