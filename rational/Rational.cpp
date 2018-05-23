//
// Created by rufus on 21.04.18.
//
#include <algorithm>
#include <climits>
#include <stdexcept>
#include <iostream>
#include "Rational.h"
#include "Dividing_by_zero_exception.h"
#include "Out_of_int_range_exception.h"
namespace ratio {

    Rational::Rational(int n, int d) : d(d), n(n) {
        if (d == 0)throw Dividing_by_zero_exception();
        int gcd = std::__gcd(std::abs(d), std::abs(n));
        this->d /= gcd;
        this->n /= gcd;
    }

    std::ostream &operator<<(std::ostream &wy, const Rational &rational) {
        std::string s;
        bool vis[1000];
        for (bool &vi : vis)vi = false;
        int den = rational.d;
        int num = rational.n;
        if (num < 0) {
            s += "-";
            num = std::abs(num);
        }
        s += std::to_string(num / den) + ".";
        num %= den;
        vis[num] = true;
        while (true) {
            num *= 10;
            s += std::to_string(num / den);
            num %= den;
            if (vis[num]) {
                s += "(";
                while (vis[num]) {
                    s += std::to_string((num * 10) / den);
                    vis[num] = false;
                    num = (10 * num) % den;
                }
                s += ")";
                break;
            }
            vis[num] = true;
        }
        wy << s;
        return wy;
    }

    int Rational::getDen() const {
        return d;
    }

    int Rational::getNum() const {
        return n;
    }

    Rational Rational::operator-() const {
        return Rational(-n, d);
    }

    Rational Rational::operator!() const {
        return Rational(d, n);
    }

    Rational::operator int() const {
        return n / d;
    }

    Rational::operator double() const {
        return (double) n / (double) d;
    }

    Rational &Rational::operator+=(const Rational &rational) {
        ll gcd = std::__gcd(d, rational.d);
        ll num = (ll) n * ((ll) rational.d / gcd) + (ll) rational.n * ((ll) d / gcd);
        ll den = (ll) d * ((ll) rational.d / gcd);
        if (std::abs(num) > INT_MAX || den > INT_MAX) throw Out_of_int_range_exception();
        d = static_cast<int>(den);
        n = static_cast<int>(num);
        return *this;
    }

    Rational &Rational::operator*=(const Rational &rational) {
        ll num = (ll) n * (ll) rational.n;
        ll den = (ll) d * (ll) rational.d;
        ll gcd = std::__gcd(std::abs(num), std::abs(den));
        num /= gcd;
        den /= gcd;
        if (std::abs(num) > INT_MAX || den > INT_MAX) throw Out_of_int_range_exception();
        d = static_cast<int>(den);
        n = static_cast<int>(num);
        return *this;
    }

    Rational &Rational::operator-=(const Rational &rational) {
        return *this += -rational;
    }

    Rational &Rational::operator/=(const Rational &rational) {
        return *this *= !rational;
    }

    Rational operator+(const Rational &r1, const Rational &r2) {
        Rational tmp(0);
        tmp += r1;
        tmp += r2;
        return tmp;
    }

    Rational operator-(const Rational &r1, const Rational &r2) {
        return r1 + -r2;
    }

    Rational operator*(const Rational &r1, const Rational &r2) {
        Rational tmp(1);
        tmp *= r1;
        tmp *= r2;
        return tmp;
    }

    Rational operator/(const Rational &r1, const Rational &r2) {
        return r1 * !r2;
    }

}