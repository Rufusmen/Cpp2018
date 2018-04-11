//
// Created by rufus on 09.04.18.
//

#include "Rev.h"
#include "Binary.h"

Rev::Rev(Wyrazenie *op1) : Unary(op1) {
priority = 2;
}

double Rev::oblicz() {
    return 1.0/op1->oblicz();
}

string Rev::toString() {
    string s = op1->toString();
    if(op1->priority >= 2) s = "("+s +")";
    return "1/"+s;
}
