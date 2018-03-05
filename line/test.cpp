//
// Created by rufus on 05.03.18.
//

#include <iostream>
#include <cassert>
#include "Straight.h"

int main(){
    auto *p1 = new Point(1,1);
    auto *p2 = new Point(2,2);
    auto *v1 = new Vector(3,3);
    auto *v2 = new Vector(5,7);
    auto *v5 = new Vector(4,2);
    auto v3 = Vector::submission(*v1,*v2);
    std::cout << v3.dx << " " << v3.dy << std::endl;
    try{
        auto *s4 = new Straight(*v5);
        std::cout << s4->getA() << " " << s4->getB() << " " << s4->getC() << std::endl;
        assert(s4->perpendicular(*v5));
        auto *s1 = new Straight(0, 2, 0);
        auto *s2 = new Straight(*s1,*v1);
        assert(Straight::parallel(*s1,*s2));
        std::cout << s2->getA() << " " << s2->getB() << " " << s2->getC() << std::endl;
        std::cout << s1->distance(*p1) << std::endl;
        assert(s1->onStraight(Point(0,0)));
        auto *s3 = new Straight(*p1,*p2);
        Point p3 = Straight::cross(*s2,*s3);
        std::cout << p3.x << " " << p3.y << std::endl;
        assert(s3->parallel(*v1));
        auto *v4 = new Vector(1,-1);
        assert(s3->perpendicular(*v4));
    }catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
    }
}