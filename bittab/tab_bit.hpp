//
// Created by rufus on 20.03.18.
//

#ifndef CPP2018_TAB_BIT_H
#define CPP2018_TAB_BIT_H

#include <iostream>

using namespace std;

class tab_bit {
    typedef unsigned long long slowo; // komorka w tablicy
    static const int rozmiarSlowa = sizeof(slowo)*8; // rozmiar slowa w bitach

    class ref {
        tab_bit *_ptr;
        int _idx;
    public:
        ref(tab_bit *tb, int i);

        ref &operator=(bool b);

        ref &operator=(const ref &val);
        operator bool() const;
    }; // klasa pomocnicza do adresowania bitów
protected:
    int dl; // liczba bitów
    slowo *tab; // tablica bitów
public:
    explicit tab_bit(int rozm); // wyzerowana tablica bitow [0...rozm]
    explicit tab_bit(slowo tb); // tablica bitów [0...rozmiarSlowa]
// zainicjalizowana wzorcem
    tab_bit(initializer_list<bool> l);

    tab_bit(const tab_bit &tb); // konstruktor kopiujący
    tab_bit(tab_bit &&tb) noexcept; // konstruktor przenoszący
    tab_bit &operator=(const tab_bit &tb); // przypisanie kopiujące
    tab_bit &operator=(tab_bit &&tb) noexcept; // przypisanie przenoszące
    ~tab_bit(); // destruktor
private:
    bool czytaj(int i) const; // metoda pomocnicza do odczytu bitu
    bool pisz(int i, bool b); // metoda pomocnicza do zapisu bitu
public:
    bool operator[](int i) const; // indeksowanie dla stałych tablic bitowych
    ref operator[](int i); // indeksowanie dla zwykłych tablic bitowych
    inline int rozmiar() const; // rozmiar tablicy w bitach
public:
    friend tab_bit operator|(tab_bit tb, const tab_bit &other);

    tab_bit& operator|=(const tab_bit &other);

    friend tab_bit operator&(tab_bit tb, const tab_bit &other);

    tab_bit& operator&=(const tab_bit &other);

    friend tab_bit operator^(tab_bit tb, const tab_bit &other);

    tab_bit& operator^=(const tab_bit &other);

    tab_bit& operator~();

// operatory bitowe: | i |=, & i &=, ^ i ^= oraz !
public:
    friend istream &operator>>(istream &we, tab_bit &tb);

    friend ostream &operator<<(ostream &wy, const tab_bit &tb);
// zaprzyjaźnione operatory strumieniowe: << i >>
};

#endif //CPP2018_TAB_BIT_H
