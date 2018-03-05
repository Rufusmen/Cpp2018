//
// Created by rufus on 04.03.18.
//

#include <stdexcept>
#include <cmath>
#include "Straight.h"

Straight::Straight(const Point &a, const Point &b) : Straight(a.y - b.y, b.x - a.x,
                                                              a.y * (a.x - b.x) - a.x * (a.y - b.y)) {
    if (a.x == b.x && a.y == b.y)throw std::invalid_argument("Same points");
}

Straight::Straight(const Vector &v) : Straight(Straight(Point(0,0),Point(-v.dy,v.dx)),v) {
    if (v.dx == 0 && v.dy == 0)throw std::invalid_argument("Vector {0,0}");
}

Straight::Straight(double a, double b, double c) {
    if (a == 0 && b == 0)throw std::invalid_argument("A = B = 0");
    double k = std::sqrt(a * a + b * b);
    this->a = a / k;
    this->b = b / k;
    this->c = c / k;

}

Straight::Straight(const Straight &p, const Vector &v) : Straight(p.a, p.b, p.c - (v.dx * p.a + v.dy * p.b)) {
}

double Straight::getA() const {
    return a;
}

double Straight::getB() const {
    return b;
}

double Straight::getC() const {
    return c;
}

bool Straight::parallel(const Straight &a, const Straight &b) {
    return std::abs(a.a * b.b - b.a * a.b) < 1e-5;
}

bool Straight::perpendicular(const Straight &a, const Straight &b) {
    return std::abs(a.a * b.a + a.b * b.b) < 1e-5;
}

Point Straight::cross(const Straight &a, const Straight &b) {
    if (parallel(a, b)) throw std::invalid_argument("Parallel straights");
    double w = a.a * b.b - b.a * a.b;
    return Point((b.c * a.b - b.b * a.c) / w, (b.a * a.c - a.a * b.c) / w);
}

bool Straight::parallel(const Vector &v) {
    return parallel(Straight(Point(0,0),Point(v.dx,v.dy)), *this);
}

bool Straight::perpendicular(const Vector &v) {
    return perpendicular(Straight(Point(0,0),Point(v.dx,v.dy)), *this);
}

double Straight::distance(const Point &p) {
    return std::abs(a*p.x + b*p.y + c);
}

bool Straight::onStraight(const Point &p) {
    return distance(p) < 1e-5;
}
