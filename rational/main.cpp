//
// Created by rufus on 21.04.18.
//

#include <iostream>
#include "Rational.h"

using namespace ratio;

int main(){
    Rational r(2,3);
    std::cout << r << std::endl;
    Rational r2(7,15);
    std::cout << r + r2 << std::endl;
    std::cout << r - r2 << std::endl;
    std::cout << r * r2 << std::endl;
    std::cout << r / r2 << std::endl;
    std::cout << -r << std::endl;
    std::cout << !r2 << std::endl;
    std::cout << (double)r << std::endl;
    std::cout << (int)!r2 << std::endl;
}