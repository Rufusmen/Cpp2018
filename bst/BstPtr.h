//
// Created by rufus on 23.05.18.
//

#ifndef CPP2018_BstPTR_H
#define CPP2018_BstPTR_H

#include "Bst.h"

template< typename T, typename C>
class Bst<T*, C> : Bst<T, C> {
public:
    Bst() : Bst<T, C>(){}
    Bst(std::initializer_list<T*> list) : Bst<T, C>() {}

    void insert(T* elem) {
        Bst<T, C>::insert(*elem);
    }

    void remove(T* elem) {
        Bst<T, C>::remove(*elem);
    }

    bool find(T* elem) {
        return Bst<T, C>::find(*elem);
    }

    friend std::ostream& operator<<(std::ostream& out, const Bst<T*, C>& bst) {
        out << dynamic_cast<const Bst<T, C>&>(bst);
        return out;
    }
};

template< typename T>
class Bst<T*> : public Bst<T*, std::less_equal<T> > {
public:
Bst(): Bst<T, std::less_equal<T> >(){}
Bst(std::initializer_list<T*> list) : Bst<T*, std::less_equal<T> >() {}
};
#endif //CPP2018_BstPTR_H
