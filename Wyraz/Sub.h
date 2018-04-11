//
// Created by rufus on 09.04.18.
//

#ifndef CPP2018_SUB_H
#define CPP2018_SUB_H


#include "Binary.h"

class Sub : public Binary{
public:
    Sub(Wyrazenie *op1, Wyrazenie *op2);

    double oblicz() override;

    string toString() override;

};


#endif //CPP2018_SUB_H
