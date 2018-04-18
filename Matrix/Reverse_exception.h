//
// Created by rufus on 18.04.18.
//

#ifndef CPP2018_REVERSE_EXCEPTION_H
#define CPP2018_REVERSE_EXCEPTION_H


#include <exception>

class Reverse_exception : public Matrix_exception {
public:
    virtual const char* what() const throw()
    {
        return "Cannot reverse this matrix";
    }
};


#endif //CPP2018_REVERSE_EXCEPTION_H
