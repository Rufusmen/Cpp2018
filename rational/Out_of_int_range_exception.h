//
// Created by rufus on 24.04.18.
//

#ifndef CPP2018_OUT_OF_INT_RANGE_EXCEPTION_H
#define CPP2018_OUT_OF_INT_RANGE_EXCEPTION_H


#include "Rational_exception.h"

class Out_of_int_range_exception : public Rational_exception{
public:
    explicit Out_of_int_range_exception(const char *details) : Rational_exception(details) {}
    Out_of_int_range_exception() : Out_of_int_range_exception("Out of int range"){}
};


#endif //CPP2018_OUT_OF_INT_RANGE_EXCEPTION_H
