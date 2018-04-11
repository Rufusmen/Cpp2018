//
// Created by rufus on 09.04.18.
//

#ifndef CPP2018_DIV_H
#define CPP2018_DIV_H


#include "Binary.h"

class Div : public Binary{
public:
    Div(Wyrazenie *op1, Wyrazenie *op2);

    double oblicz() override;

    string toString() override;

};


#endif //CPP2018_DIV_H
