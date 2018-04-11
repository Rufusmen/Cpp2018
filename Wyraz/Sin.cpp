//
// Created by rufus on 09.04.18.
//

#include "Sin.h"

double Sin::oblicz() {
    return sin(op1->oblicz());
}

string Sin::toString() {
    return "sin(" + op1->toString() + ")";
}

Sin::Sin(Wyrazenie *op1) : Unary(op1) {}
