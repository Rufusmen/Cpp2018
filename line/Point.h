//
// Created by rufus on 04.03.18.
//

#ifndef CPP2018_PUNKT_H
#define CPP2018_PUNKT_H


#include "Vector.h"

class Point {
public:
    const double x = 0, y = 0;

    Point() = default;

    Point(const double &x, const double &y);

    Point(const Point &p, const Vector &v);

    Point(const Point &other) = default;

    Point &operator=(const Point &) = delete;
};


#endif //CPP2018_PUNKT_H
