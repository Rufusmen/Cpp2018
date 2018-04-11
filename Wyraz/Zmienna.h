//
// Created by rufus on 09.04.18.
//

#ifndef CPP2018_ZMIENNA_H
#define CPP2018_ZMIENNA_H


#include <vector>
#include "Wyrazenie.h"

class Zmienna : public Wyrazenie{
private:
    static vector<pair<string,double> > vec;
    string name;
public:
    Zmienna(string);
    static double find(string);
    static void add(string, double);
    static void remove(string);

    double oblicz() override;

    string toString() override;
};


#endif //CPP2018_ZMIENNA_H
