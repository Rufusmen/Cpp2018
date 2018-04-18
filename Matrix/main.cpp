#include <iostream>
#include "Matrix.h"

//
// Created by rufus on 17.04.18.
//

int main(){
    int n,m;
    std::cin >> n >> m;
    calc::Matrix matrix(n,m);
    std::cin >> matrix;
    std::cout << matrix.det()
              << "\n"
              << matrix.rev();
}