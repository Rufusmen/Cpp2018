//
// Created by rufus on 09.04.18.
//

#ifndef CPP2018_EXP_H
#define CPP2018_EXP_H


#include "Unary.h"

class Exp : public Unary {
public:
    explicit Exp(Wyrazenie *op1);

private:
    double oblicz() override;

    string toString() override;

};


#endif //CPP2018_EXP_H
