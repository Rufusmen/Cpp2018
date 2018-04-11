//
// Created by rufus on 09.04.18.
//

#ifndef CPP2018_MOD_H
#define CPP2018_MOD_H


#include "Binary.h"

class Mod : public Binary{
public:
    Mod(Wyrazenie *op1, Wyrazenie *op2);

    double oblicz() override;

    string toString() override;

};


#endif //CPP2018_MOD_H
