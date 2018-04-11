//
// Created by rufus on 09.04.18.
//

#ifndef CPP2018_SIN_H
#define CPP2018_SIN_H


#include "Unary.h"

class Sin : public Unary {
public:


    explicit Sin(Wyrazenie *op1);

    double oblicz() override;

    string toString() override;
};


#endif //CPP2018_SIN_H
