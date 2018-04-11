//
// Created by rufus on 09.04.18.
//

#include "Sub.h"

Sub::Sub(Wyrazenie *op1, Wyrazenie *op2) : Binary(op1, op2) {
priority = 3;
}

double Sub::oblicz() {
    return op1->oblicz() - op2->oblicz();
}

string Sub::toString() {
    string s = op2->toString();
    if(op2->priority == 3) s = "(" + s + ")";
    return op1->toString() +"-"+s;
}
