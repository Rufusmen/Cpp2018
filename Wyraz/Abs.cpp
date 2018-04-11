//
// Created by rufus on 09.04.18.
//

#include "Abs.h"

Abs::Abs(Wyrazenie *op1) : Unary(op1) {

}

double Abs::oblicz() {
    return abs(op1->oblicz());
}

string Abs::toString() {
    return "abs(" + op1->toString() + ")";
}
