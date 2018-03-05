//
// Created by rufus on 04.03.18.
//

#include "Point.h"

Point::Point(const double &x, const double &y) : x(x), y(y) {}

Point::Point(const Point &p, const Vector &v) : x(p.x + v.dx), y(p.y + v.dy) {}
