//
// Created by rufus on 09.04.18.
//

#ifndef CPP2018_LICZBA_H
#define CPP2018_LICZBA_H


#include "Wyrazenie.h"

class Liczba : public Wyrazenie{
private:

    double val;

public:
    explicit Liczba(double);

    double oblicz() override;

    std::string toString() override;
};


#endif //CPP2018_LICZBA_H
