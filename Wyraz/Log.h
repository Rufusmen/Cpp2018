//
// Created by rufus on 09.04.18.
//

#ifndef CPP2018_LOG_H
#define CPP2018_LOG_H


#include "Binary.h"

class Log : public Binary {
public:
    Log(Wyrazenie *op1, Wyrazenie *op2);

    double oblicz() override;

    string toString() override;

};


#endif //CPP2018_LOG_H
