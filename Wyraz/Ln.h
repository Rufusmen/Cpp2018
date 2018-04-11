//
// Created by rufus on 09.04.18.
//

#ifndef CPP2018_LN_H
#define CPP2018_LN_H


#include "Unary.h"

class Ln : public Unary{
public:
    explicit Ln(Wyrazenie *op1);

    double oblicz() override;

    string toString() override;
};


#endif //CPP2018_LN_H
