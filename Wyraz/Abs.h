//
// Created by rufus on 09.04.18.
//

#ifndef CPP2018_ABS_H
#define CPP2018_ABS_H


#include "Unary.h"

class Abs : public Unary {
public:
    explicit Abs(Wyrazenie *op1);

    double oblicz() override;

    string toString() override;
};


#endif //CPP2018_ABS_H
