//
// Created by rufus on 09.04.18.
//

#include "Liczba.h"

double Liczba::oblicz() {
    return val;
}

std::string Liczba::toString() {
    return std::to_string(val);
}

Liczba::Liczba(double x) : val(x){

}
