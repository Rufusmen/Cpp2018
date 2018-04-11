//
// Created by rufus on 09.04.18.
//

#include "Ln.h"

Ln::Ln(Wyrazenie *op1) : Unary(op1) {}

double Ln::oblicz() {
    return log(op1->oblicz());
}

string Ln::toString() {
    return "ln(" + op1->toString() +")";
}
