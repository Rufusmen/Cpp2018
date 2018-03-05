//
// Created by rufus on 04.03.18.
//

#ifndef CPP2018_PROSTA_H
#define CPP2018_PROSTA_H


#include "Vector.h"
#include "Point.h"

class Straight {
private:
    double a, b, c;
public:
    Straight() = default;

    Straight(const Point &a, const Point &b);

    explicit Straight(const Vector &v);

    Straight(double a, double b, double c);

    Straight(const Straight &p, const Vector &v);

    Straight(Straight const &) = delete;

    void operator=(Straight const &) = delete;

    double getB() const;

    double getC() const;

    double getA() const;

    static bool parallel(const Straight &a, const Straight &b);

    static bool perpendicular(const Straight &a, const Straight &b);

    static Point cross(const Straight &a, const Straight &b);

    bool parallel(const Vector &v);

    bool perpendicular(const Vector &v);

    double distance(const Point &p);

    bool onStraight(const Point &p);
};


#endif //CPP2018_PROSTA_H
