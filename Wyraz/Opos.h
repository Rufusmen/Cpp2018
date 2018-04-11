//
// Created by rufus on 09.04.18.
//

#ifndef CPP2018_OPOS_H
#define CPP2018_OPOS_H


#include "Unary.h"

class Opos : public Unary{
public:
    explicit Opos(Wyrazenie *op1);

    double oblicz() override;

    string toString() override;

};


#endif //CPP2018_OPOS_H
