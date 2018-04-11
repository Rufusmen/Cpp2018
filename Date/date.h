//
// Created by rufus on 26.03.18.
//

#ifndef CPP2018_DATE_H
#define CPP2018_DATE_H

#include <iostream>
using  namespace std;

class date {
protected:
    static constexpr int daysInMonths[2][13] = {
            {0,31,28,31,30,31,30,31,31,30,31,30,31}, // lata zwykłe
            {0,31,29,31,30,31,30,31,31,30,31,30,31} // lata przestępne
    };
    static constexpr int daysFromYearStart[2][13] = {
            {0,31,59,90,120,151,181,212,243,273,304,334,365}, // lata zwykłe
            {0,31,60,91,121,152,182,213,244,274,305,335,366} // lata przestępne
    };
    int day;
    int month;
    int year;
public:

    date();

    date(int year, int month, int day);

    date(const date &other) = default;

    date &operator=(const date &other) = default;

    int getYear() const;

    int getMonth() const;

    int getDay() const;

    virtual int operator-(const date &rhs);

    date &operator--(); // pre
    date operator--(int); // post
    date &operator++(); // pre
    date operator++(int); // post
    date &operator+=(int days);

    date &operator-=(int days);

protected:
    static inline bool isLeapYear(date d);

    static long long int toDays( date d);

    static date toDate(long long int days);

private:
    int timeDifference(date d) const;
    void check() const;
};



#endif //CPP2018_DATE_H
