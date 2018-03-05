//
// Created by rufus on 04.03.18.
//

#ifndef CPP2018_WEKTOR_H
#define CPP2018_WEKTOR_H


class Vector {
public:
    const double dx = 0, dy = 0;

    Vector() = default;

    Vector(const double &dx, const double &dy);

    Vector(const Vector &) = default;

    Vector &operator=(const Vector &) = delete; 

    static Vector submission(const Vector &a, const Vector &b);
};


#endif //CPP2018_WEKTOR_H
