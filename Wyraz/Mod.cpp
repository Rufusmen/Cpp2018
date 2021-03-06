//
// Created by rufus on 09.04.18.
//

#include "Mod.h"

Mod::Mod(Wyrazenie *op1, Wyrazenie *op2) : Binary(op1, op2) {
    priority = 1;
}

double Mod::oblicz() {
    return fmod(op1->oblicz(),op2->oblicz());
}

string Mod::toString() {
    string s1 = op1->toString() , s2 = op2->toString();
    if(op1->priority>1) s1 = "(" + s1 + ")";
    if(op2->priority>=1) s2 = "(" + s2 + ")";
    return s1 + "%" + s2;
}
