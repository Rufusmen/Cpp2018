//
// Created by rufus on 26.03.18.
//

#include "timePoint.h"

int timePoint::getHours() const {
    return hours;
}

int timePoint::getMinutes() const {
    return minutes;
}

int timePoint::getSeconds() const {
    return seconds;
}

timePoint::timePoint(int year, int month, int day, int hours, int minutes, int seconds) : date(year, month, day),
                                                                                          hours(hours),
                                                                                          minutes(minutes),
                                                                                          seconds(seconds) {
    check();
}

timePoint::timePoint() {
    date d;
    auto now = time(nullptr);
    auto time = gmtime(&now);
    *this = timePoint(d.getYear(), d.getMonth(), d.getDay(), time->tm_hour, time->tm_min, time->tm_sec);
    check();
}

timePoint::timePoint(date d) : date(d), hours(0), minutes(0), seconds(0) {}

void timePoint::check() const {
    if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59 || seconds < 0 || seconds > 59)
        throw std::invalid_argument("Wrong time");
}

long long timePoint::operator-(const timePoint &rhs) {
    return (toDays(*this) - toDays(rhs))* 86400LL + timeDifference(rhs);
}

long long timePoint::timeDifference(timePoint d) const {
    return (hours - d.hours) * 3600 + (minutes - d.minutes) * 60 + seconds - d.seconds;
}

bool timePoint::operator==(const timePoint &rhs) const {
    return year == rhs.year && month == rhs.month && day == rhs.day && hours == rhs.hours && minutes == rhs.minutes &&  seconds == rhs.seconds;
}

bool timePoint::operator<(const timePoint &rhs) const {
    return toDays(*this) < toDays(rhs) || (toDays(*this) == toDays(rhs) && toSec(*this) < toSec(rhs));
}

long long timePoint::toSec(timePoint p) {
    return p.hours*3600 + p.minutes*60 + p.seconds;
}

timePoint &timePoint::operator--() {
    if (--seconds == -1) {
        if (--minutes == -1) {
            if (--hours == -1) {
                date::operator--();
                hours = 23;
            }
            minutes = 59;
        }
        seconds = 59;
    }
    return *this;
}

timePoint timePoint::operator--(int) {
    timePoint tmp(*this);
    operator--();
    return tmp;
}

timePoint &timePoint::operator++() {
    if (++seconds == 60) {
        if (++minutes == 60) {
            if (++hours == 24) {
                date::operator++();
                hours = 0;
            }
            minutes = 0;
        }
        seconds = 0;
    }
    return *this;
}

timePoint timePoint::operator++(int) {
    timePoint tmp(*this);
    operator++();
    return tmp;
}

timePoint &timePoint::operator+=(int s) {
    seconds+=s;
    minutes+=s/60;
    seconds%=60;
    if(seconds<0){
        minutes--;
        seconds+=60;
    }
    hours+=minutes/60;
    minutes%=60;
    if(minutes<0){
        hours--;
        minutes+=60;
    }
    long long days = toDays(*this) + hours/24;
    hours%=24;
    if(hours<0){
        days--;
        hours+=24;
    }
    date tmp = toDate(days);
    day = tmp.getDay();
    month = tmp.getMonth();
    year = tmp.getYear();
    check();
    return *this;
}

timePoint &timePoint::operator-=(int s) {
    return operator+=(-s);
}
