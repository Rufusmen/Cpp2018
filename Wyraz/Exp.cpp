//
// Created by rufus on 09.04.18.
//

#include "Exp.h"

Exp::Exp(Wyrazenie *op1) : Unary(op1) {}

double Exp::oblicz() {
    return exp(op1->oblicz());
}

string Exp::toString() {
    return "exp(" + op1->toString() + ")";
}
