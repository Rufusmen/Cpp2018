//
// Created by rufus on 26.03.18.
//

#include "date.h"

constexpr int date::daysInMonths[2][13];
constexpr int date::daysFromYearStart[2][13];

date::date(int year, int month, int day) : day(day), month(month), year(year) {
    check();
}

date::date() {
    auto now = time(nullptr);
    auto time = gmtime(&now);
    year = time->tm_year + 1900;
    month = time->tm_mon + 1;
    day = time->tm_mday;
}

int date::getYear() const {
    return year;
}

int date::getMonth() const {
    return month;
}

int date::getDay() const {
    return day;
}

void date::check() const {
    if ((year < 1582) || (year == 1582 && month < 10) || (year == 1582 && month == 10 && day < 15)
        || (month > 12) || (day > daysInMonths[isLeapYear(*this)][month])
        || (month < 1) || (day < 0))
        throw invalid_argument("Wrong date");
}

int date::timeDifference(date d) const {
    return d.year * 365 + d.year / 4 - d.year / 100 + d.year / 400 - isLeapYear(d) +
           daysFromYearStart[isLeapYear(d)][d.month - 1] + d.day
           - year * 365 - year / 4 + year / 100 - year / 400 + isLeapYear(*this) -
           daysFromYearStart[isLeapYear(*this)][month - 1] - day;
}

bool date::isLeapYear(date d) {
    return d.year % 400 == 0 || (d.year % 4 == 0 && d.year % 100 != 0);
}

date date::toDate(long long int days){
    date tmp;
    long long x = 5 * ((((4 * (days + 1401 + (((4 * days + 274277) / 146097) * 3) / 4 - 38) + 3) + 1461) % 1461) / 4) + 2;
    tmp.day = static_cast<int>(((x + 153) % 153) / 5 + 1);
    tmp.month = static_cast<int>((x / 153 + 2) % 12 + 1);
    tmp.year = static_cast<int>(((4 * (days + 1401 + (((4 * days + 274277) / 146097) * 3) / 4 - 38) + 3) / 1461) - 4716 + (12 + 2 - tmp.month) / 12);
    tmp.check();
    return tmp;
}

long long int date::toDays(date d){
    return (1461 * (d.year + 4800 + (d.month - 14) / 12)) / 4 +
           (367 * (d.month - 2 - 12 * ((d.month - 14) / 12))) / 12 -
           (3 * ((d.year + 4900 + (d.month - 14) / 12) / 100)) / 4 + d.day - 32075;
}

int date::operator-(const date &rhs) {
    return this->timeDifference(rhs);
}

date &date::operator--() {
    if (--day == 0) {
        if (--month == 0) {
            --year;
            check();
            month = 12;
        }
        day = daysInMonths[isLeapYear(*this)][month];
    }
    return *this;
}

date date::operator--(int) {
    date tmp(*this);
    operator--();
    return tmp;
}

date &date::operator++() {
    if (++day == daysInMonths[isLeapYear(*this)][month]) {
        if (++month == 13) {
            ++year;
            check();
            month = 1;
        }
        day = 1;
    }
    return *this;
}

date date::operator++(int) {
    date tmp(*this);
    operator++();
    return tmp;
}

date &date::operator+=(int days) {
    *this = toDate(toDays(*this) + days);
    return *this;
}

date &date::operator-=(int days) {
    *this = toDate(toDays(*this) - days);
}








