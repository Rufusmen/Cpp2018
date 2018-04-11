//
// Created by rufus on 09.04.18.
//

#ifndef CPP2018_MUL_H
#define CPP2018_MUL_H


#include "Binary.h"

class Mul : public Binary{
public:
    Mul(Wyrazenie *op1, Wyrazenie *op2);

    double oblicz() override;

    string toString() override;

};


#endif //CPP2018_MUL_H
