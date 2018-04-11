//
// Created by rufus on 09.04.18.
//

#include "Opos.h"

Opos::Opos(Wyrazenie *op1) : Unary(op1) {
priority =2;
}

double Opos::oblicz() {
    return -1.0 * op1->oblicz();
}

string Opos::toString() {
    string s1 = op1->toString();
    if(op1->priority>2) s1 = "(" + s1 + ")";
    return "-" + s1;
}
