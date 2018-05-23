//
// Created by rufus on 23.05.18.
//

#ifndef CPP2018_BstCSTR_H
#define CPP2018_BstCSTR_H

#include "Bst.h"
#include <cstring>
#include <string>

template<class C>
class Bst<const char *, C> : Bst<std::string, C> {
    using Cstr = const char *;
public:
    Bst():Bst<std::string,C>(){}

    Bst(std::initializer_list<const char *> list) : Bst<std::string, C>() {
        for (auto elem : list)
            insert(elem);
    }

    void insert(Cstr elem) {
        Bst<std::string, C>::insert(std::string(elem));
    }

    void remove(Cstr elem) {
        Bst<std::string, C>::remove(std::string(elem));
    }

    bool find(Cstr elem) {
        return Bst<std::string, C>::find(std::string(elem));
    }

    friend std::ostream &operator<<(std::ostream &out, const Bst<Cstr, C> &bst) {
        out << dynamic_cast<const Bst<std::string, C>&>(bst);
        return out;
    }
};


struct DefaultCStrC {
    bool operator()(const std::string &s1, const std::string &s2) { // <=
        return s1 <= s2;
    }
};

template<>
class Bst<const char *> : public Bst<const char *, DefaultCStrC> {
public:
    Bst() : Bst<const char *, DefaultCStrC>() {};

    Bst(std::initializer_list<const char *> list) : Bst<const char *, DefaultCStrC>(list) {}
};


#endif //CPP2018_BstCSTR_H
