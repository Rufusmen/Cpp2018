//
// Created by rufus on 09.04.18.
//

#ifndef CPP2018_COS_H
#define CPP2018_COS_H


#include "Unary.h"

class Cos : public Unary{
public:
    explicit Cos(Wyrazenie *op1);

private:
    double oblicz() override;

    string toString() override;
};


#endif //CPP2018_COS_H
