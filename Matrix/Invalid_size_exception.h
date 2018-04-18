//
// Created by rufus on 18.04.18.
//

#ifndef CPP2018_INVALID_SIZE_EXCEPTION_H
#define CPP2018_INVALID_SIZE_EXCEPTION_H


#include <exception>
#include "Matrix_exception.h"

class Invalid_size_exception : public Matrix_exception{
public:
    virtual const char* what() const throw()
    {
        return "Invalid matrix size";
    }
};


#endif //CPP2018_INVALID_SIZE_EXCEPTION_H
