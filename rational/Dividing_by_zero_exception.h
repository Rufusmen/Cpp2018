//
// Created by rufus on 24.04.18.
//

#ifndef CPP2018_DIVIDING_BY_ZERO_EXCEPTION_H
#define CPP2018_DIVIDING_BY_ZERO_EXCEPTION_H


#include "Rational_exception.h"

class Dividing_by_zero_exception : public Rational_exception{
public:
    explicit Dividing_by_zero_exception(const char *details) : Rational_exception(details) {}

    Dividing_by_zero_exception() : Dividing_by_zero_exception("Zero in denominator"){}

};


#endif //CPP2018_DIVIDING_BY_ZERO_EXCEPTION_H
