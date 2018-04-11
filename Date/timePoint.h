//
// Created by rufus on 26.03.18.
//

#ifndef CPP2018_TIMEPOINT_H
#define CPP2018_TIMEPOINT_H


#include "date.h"

class timePoint final : public date {
protected:
    int hours;
    int minutes;
    int seconds;
public:

    timePoint();

    timePoint(int year, int month=1, int day=1, int hours=0, int minutes=0, int seconds=0);

    timePoint(date d);

    timePoint(const timePoint &other) = default;

    timePoint &operator=(const timePoint &other) = default;

    int getHours() const;

    int getMinutes() const;

    int getSeconds() const;

    long long operator-(const timePoint &rhs);

    bool operator==(const timePoint &rhs) const;

    bool operator<(const timePoint &rhs) const;

    timePoint &operator--(); // pre
    timePoint operator--(int); // post
    timePoint &operator++(); // pre
    timePoint operator++(int); // post
    timePoint &operator+=(int s);

    timePoint &operator-=(int s);

protected:
    static long long toSec(timePoint p);

private:
    long long timeDifference(timePoint d) const;
    void check() const;
};


#endif //CPP2018_TIMEPOINT_H
