//
// Created by gosha on 20.04.19.
//

#ifndef KURSACH_EVENT_H
#define KURSACH_EVENT_H


#include <string>
#include <iostream>



class Event
{
public:
    Event();
    Event(std::string event);
    void set_event(std::string event);
    bool operator < (const Event* event1);
    std::string get_event() const;
    ~Event(){/*std::cout << "rempve\n";*/}

private:
    std::string event;
};



#endif //KURSACH_EVENT_H



