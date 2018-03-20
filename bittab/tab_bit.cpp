//
// Created by rufus on 20.03.18.
//

#include "tab_bit.hpp"


std::basic_istream<char> &operator>>(istream &we, tab_bit &tb) {
    string str;
    we >> str;
    for(int i=0;i<str.size();i++)
        tb.pisz(i,str[i]-'0');
    return we;
}

ostream &operator<<(ostream &wy, const tab_bit &tb) {
    for(int i=0;i<tb.dl;i++)
        wy << tb.czytaj(i);
    return wy;
}

tab_bit::tab_bit(int rozm) {
    dl = rozm;
    tab = new slowo[rozm/rozmiarSlowa];
}

tab_bit::tab_bit(tab_bit::slowo tb) {
    dl = rozmiarSlowa;
    tab= new slowo(tb);
}

tab_bit::tab_bit(const tab_bit &tb) {
    dl = tb.dl;
    tab = new slowo[dl/rozmiarSlowa];
    for(int i=0;i<dl/rozmiarSlowa;i++)tab[i]=tb.tab[i];
}

tab_bit::tab_bit(tab_bit &&tb) noexcept {
    dl = tb.dl;
    tab = tb.tab;
    tb.dl = 0;
    tb.tab = nullptr;
}

tab_bit &tab_bit::operator=(const tab_bit &tb) {
    tab_bit tmp(tb);
    *this = move(tmp);
    return *this;
}

tab_bit &tab_bit::operator=(tab_bit &&tb) noexcept {
    if(this == &tb)
        return *this;
    this->~tab_bit();
    dl = tb.dl;
    tab = tb.tab;
    tb.dl = 0;
    tb.tab = nullptr;
    return *this;
}

tab_bit::~tab_bit() {
    delete[]tab;
}

bool tab_bit::czytaj(int i) const {
    return static_cast<bool>(tab[i / rozmiarSlowa] & (1ull << (i % rozmiarSlowa)));
}

bool tab_bit::pisz(int i, bool b) {
    tab[i/rozmiarSlowa] = (tab[i/rozmiarSlowa] & ~(1ull << (i%rozmiarSlowa)))|((slowo)b << (i%rozmiarSlowa));
    return b;
}

bool tab_bit::operator[](int i) const {
    if(i>=dl)throw invalid_argument("Poza tablicą");
    return czytaj(i);
}

tab_bit::ref tab_bit::operator[](int i) {
    return tab_bit::ref(this,i);
}

int tab_bit::rozmiar() const {
    return dl;
}

tab_bit::tab_bit(initializer_list<bool> l) {
    dl = static_cast<int>(l.size());
    tab = new slowo[dl/rozmiarSlowa];
    int i=0;
    for(bool b : l){
        pisz(i++,b);
    }
}

tab_bit &tab_bit::operator|=(const tab_bit &other) {
    for(int i=0;i<dl/rozmiarSlowa;i++){
        if(i<other.dl/rozmiarSlowa)tab[i]|=other.tab[i];
    }
    return *this;
}

tab_bit &tab_bit::operator&=(const tab_bit &other) {
    for(int i=0;i<dl/rozmiarSlowa;i++){
        if(i<other.dl/rozmiarSlowa)tab[i]&=other.tab[i];
    }
    return *this;
}

tab_bit &tab_bit::operator^=(const tab_bit &other) {
    for(int i=0;i<dl/rozmiarSlowa;i++){
        if(i<other.dl/rozmiarSlowa)tab[i]^=other.tab[i];
    }
    return *this;
}



tab_bit &tab_bit::operator~() {
    for(int i=0;i<dl/rozmiarSlowa;i++){
        tab[i]=~tab[i];
    }
    return *this;
}

tab_bit operator|(tab_bit tb, const tab_bit &other) {
    tab_bit tmp(tb);
    return tmp|=other;
}

tab_bit operator&(tab_bit tb, const tab_bit &other) {
    tab_bit tmp(tb);
    return tmp&=other;
}

tab_bit operator^(tab_bit tb, const tab_bit &other) {
    tab_bit tmp(tb);
    return tmp^=other;
}


tab_bit::ref::ref(tab_bit *tb, int i) {
    _ptr = tb;
    _idx = i;
}

tab_bit::ref &tab_bit::ref::operator=(const bool b) {
    _ptr->pisz(_idx,b);
    return *this;
}

tab_bit::ref &tab_bit::ref::operator=(const tab_bit::ref &val) {
    _ptr->pisz(_idx,val);
    return *this;
}

tab_bit::ref::operator bool() const{
    _ptr->czytaj(_idx);
}
