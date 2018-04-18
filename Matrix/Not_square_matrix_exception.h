//
// Created by rufus on 18.04.18.
//

#ifndef CPP2018_NOT_SQUARE_MATRIX_EXCEPTION_H
#define CPP2018_NOT_SQUARE_MATRIX_EXCEPTION_H


#include <exception>
#include "Matrix_exception.h"

class Not_square_matrix_exception : public Matrix_exception{
public:

    virtual const char* what() const throw()
    {
        return "Matrix is not square";
    }
};


#endif //CPP2018_NOT_SQUARE_MATRIX_EXCEPTION_H
