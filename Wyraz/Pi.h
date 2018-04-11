//
// Created by rufus on 09.04.18.
//

#ifndef CPP2018_PI_H
#define CPP2018_PI_H


#include "Const.h"

class Pi : public Const{
    double oblicz() override;

    std::string toString() override;
};


#endif //CPP2018_PI_H
