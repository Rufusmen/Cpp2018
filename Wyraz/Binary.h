//
// Created by rufus on 09.04.18.
//

#ifndef CPP2018_BINARY_H
#define CPP2018_BINARY_H


#include "Unary.h"

class Binary : public Unary{
protected:
    Wyrazenie *op2;
public:
    Binary(Wyrazenie *op1, Wyrazenie *op2);
    ~Binary()
};


#endif //CPP2018_BINARY_H
