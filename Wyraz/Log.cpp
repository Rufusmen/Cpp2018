//
// Created by rufus on 09.04.18.
//

#include "Log.h"

Log::Log(Wyrazenie *op1, Wyrazenie *op2) : Binary(op1, op2) {

}

double Log::oblicz() {
    return log(op2->oblicz())/log(op1->oblicz());
}

string Log::toString() {
    return "log(" + op1->toString() +"," + op2->toString() + ")";
}
