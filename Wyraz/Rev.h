//
// Created by rufus on 09.04.18.
//

#ifndef CPP2018_REV_H
#define CPP2018_REV_H


#include "Unary.h"

class Rev : public Unary{
public:
    explicit Rev(Wyrazenie *op1);

    double oblicz() override;

    string toString() override;

};


#endif //CPP2018_REV_H
