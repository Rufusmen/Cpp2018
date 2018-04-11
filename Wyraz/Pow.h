//
// Created by rufus on 09.04.18.
//

#ifndef CPP2018_POW_H
#define CPP2018_POW_H


#include "Binary.h"

class Pow : public Binary{
public:
    Pow(Wyrazenie *op1, Wyrazenie *op2);

    double oblicz() override;

    string toString() override;

};


#endif //CPP2018_POW_H
