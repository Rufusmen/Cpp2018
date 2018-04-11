//
// Created by rufus on 09.04.18.
//

#ifndef CPP2018_UNARY_H
#define CPP2018_UNARY_H


#include "Wyrazenie.h"

class Unary : public Wyrazenie {
protected:
    Wyrazenie *op1;
public:
    explicit Unary(Wyrazenie *op1) : op1(op1) {}
    virtual ~Unary() {
        delete op1;
    }
};



#endif //CPP2018_UNARY_H
