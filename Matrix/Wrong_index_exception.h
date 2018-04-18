//
// Created by rufus on 18.04.18.
//

#ifndef CPP2018_WRONG_INDEX_H
#define CPP2018_WRONG_INDEX_H


#include <exception>

class Wrong_index_exception : public Matrix_exception {
public:
    virtual const char *what() const throw() {
        return "Wrong index";
    }
};


#endif //CPP2018_WRONG_INDEX_H
