//
// Created by rufus on 04.03.18.
//

#include "Vector.h"

Vector::Vector(const double &dx, const double &dy) : dx(dx), dy(dy) {

}

Vector Vector::submission(const Vector &a, const Vector &b) {
    return Vector(a.dx + b.dx, a.dy + b.dy);
}
