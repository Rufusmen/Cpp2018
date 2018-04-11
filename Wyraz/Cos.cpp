//
// Created by rufus on 09.04.18.
//

#include "Cos.h"

Cos::Cos(Wyrazenie *op1) : Unary(op1) {}

double Cos::oblicz() {
    return cos(op1->oblicz());
}

string Cos::toString() {
    return "cos(" + op1->toString() + ")";
}
