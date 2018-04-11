//
// Created by rufus on 26.03.18.
//

#ifndef CPP2018_EVENT_H
#define CPP2018_EVENT_H


#include "timePoint.h"

class event {
    timePoint time;
    string info;
public:
    const timePoint &getTime() const;

    const string &getInfo() const;

    event(const timePoint &time, const string &info);

    event(int year,int month=1,int day=1,int hour=0,int minutes=0,int sec=0,const string &info = "No info");

    bool operator<(const event &rhs) const;

    string toString();
};


#endif //CPP2018_EVENT_H
