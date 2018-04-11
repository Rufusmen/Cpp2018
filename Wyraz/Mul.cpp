//
// Created by rufus on 09.04.18.
//

#include "Mul.h"

Mul::Mul(Wyrazenie *op1, Wyrazenie *op2) : Binary(op1, op2) {
priority = 2;
}

double Mul::oblicz() {
    return op1->oblicz()*op2->oblicz();
}

string Mul::toString() {
    string s1=op1->toString(),s2=op2->toString();
    if(op1->priority>2)s1 = "(" + s1 + ")";
    if(op2->priority>2)s2 = "(" + s2 + ")";
    return s1 + "*" + s2;
}
