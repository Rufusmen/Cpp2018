//
// Created by rufus on 26.03.18.
//

#include "event.h"

event::event(const timePoint &time, const string &info) : time(time), info(info) {}

const timePoint &event::getTime() const {
    return time;
}

const string &event::getInfo() const {
    return info;
}

bool event::operator<(const event &rhs) const {
    return time < rhs.time;
}

event::event(int year, int month, int day, int hour, int minutes, int sec, const string &info):time(year,month,day,hour,minutes,sec),info(info) {}

string event::toString() {
    string s = "[";
    s+=to_string(time.getYear()) + ".";
    s+=(time.getMonth()>9?to_string(time.getMonth()):"0"+to_string(time.getMonth())) + ".";
    s+=(time.getDay()>9?to_string(time.getDay()):"0"+to_string(time.getDay())) + " ";
    s+=(time.getHours()>9?to_string(time.getHours()):"0"+to_string(time.getHours())) + ":";
    s+=(time.getMinutes()>9?to_string(time.getMinutes()):"0"+to_string(time.getMinutes())) + ":";
    s+=(time.getSeconds()>9?to_string(time.getSeconds()):"0"+to_string(time.getSeconds())) + "]  :\"" + info + "\"";
    return s;
}
