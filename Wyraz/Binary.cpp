//
// Created by rufus on 09.04.18.
//

#include "Binary.h"

Binary::Binary(Wyrazenie *op1, Wyrazenie *op2) : Unary(op1), op2(op2) {}

Binary::~Binary() {
    delete op2;
    delete op1;
}
