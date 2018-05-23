//
// Created by rufus on 21.04.18.
//

#ifndef CPP2018_RATIONAL_H
#define CPP2018_RATIONAL_H
namespace ratio {

    typedef long long ll;

    class Rational {
    private:
        int d, n;
    public:
        explicit Rational(int n, int d = 1);

        Rational(const Rational &rational) = default;

        Rational &operator=(const Rational &rational) = default;

        ~Rational() = default;

        friend std::ostream &operator<<(std::ostream &wy, const Rational &rational);

        Rational operator-() const;

        Rational operator!() const;

        explicit operator int() const;

        explicit operator double() const;

        Rational &operator+=(const Rational &rational);

        Rational &operator*=(const Rational &rational);

        Rational &operator-=(const Rational &rational);

        Rational &operator/=(const Rational &rational);

        friend Rational operator+(const Rational &r1, const Rational &r2);

        friend Rational operator-(const Rational &r1, const Rational &r2);

        friend Rational operator*(const Rational &r1, const Rational &r2);

        friend Rational operator/(const Rational &r1, const Rational &r2);

        int getDen() const;

        int getNum() const;
    };
}

#endif //CPP2018_RATIONAL_H
