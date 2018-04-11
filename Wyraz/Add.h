//
// Created by rufus on 09.04.18.
//

#ifndef CPP2018_ADD_H
#define CPP2018_ADD_H


#include "Binary.h"

class Add : public Binary{
public:
    Add(Wyrazenie *op1, Wyrazenie *op2);

    double oblicz() override;

    string toString() override;

};


#endif //CPP2018_ADD_H
