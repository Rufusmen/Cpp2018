//
// Created by rufus on 09.04.18.
//

#include "Add.h"

Add::Add(Wyrazenie *op1, Wyrazenie *op2) : Binary(op1, op2) {
    priority=3;
}

double Add::oblicz() {
    return op1->oblicz()+op2->oblicz();
}

string Add::toString() {
    return op1->toString() + "+" + op2->toString();
}
