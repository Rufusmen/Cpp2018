//
// Created by rufus on 09.04.18.
//

#ifndef CPP2018_WYRAZENIE_H
#define CPP2018_WYRAZENIE_H

#include <iostream>
#include <cmath>
using namespace std;

class Wyrazenie {
public:
    unsigned short int priority = 0;
    virtual double oblicz()= 0;
    virtual string toString() = 0;
};
#endif //CPP2018_WYRAZENIE_H
