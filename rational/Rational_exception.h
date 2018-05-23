//
// Created by rufus on 24.04.18.
//

#ifndef CPP2018_RATIONAL_EXCEPTION_H
#define CPP2018_RATIONAL_EXCEPTION_H

#include <iostream>
#include <exception>

class Rational_exception : public std::exception {

    std::string details;
public:
    explicit Rational_exception(const char *details) : std::exception() , details(details){
    }

    const char *what() const noexcept override { return details.c_str(); }

};


#endif //CPP2018_RATIONAL_EXCEPTION_H
