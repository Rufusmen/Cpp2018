//
// Created by rufus on 20.03.18.
//

#include "tab_bit.hpp"


std::basic_istream<char> &operator>>(istream &we, tab_bit &tb) {
    string str;
    we >> str;
    if(str.size()>tb.dl)throw invalid_argument("za dużo bitów");
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
    ile_slow = (rozm+63)/rozmiarSlowa;
    tab = new slowo[ile_slow];
}

tab_bit::tab_bit(tab_bit::slowo tb) {
    dl = rozmiarSlowa;
    ile_slow =1;
    tab= new slowo(tb);
}

tab_bit::tab_bit(const tab_bit &tb) {
    dl = tb.dl;
    ile_slow = tb.ile_slow;
    tab = new slowo[ile_slow];
    for(int i=0;i<ile_slow;i++)tab[i]=tb.tab[i];
}

tab_bit::tab_bit(tab_bit &&tb) noexcept {
    dl = tb.dl;
    tab = tb.tab;
    ile_slow = tb.ile_slow;
    tb.ile_slow=0;
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
    ile_slow = tb.ile_slow;
    tb.ile_slow = 0;
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
    if(i>=dl)throw invalid_argument("Poza tablicą");
    return tab_bit::ref(this,i);
}

int tab_bit::rozmiar() const {
    return dl;
}

tab_bit::tab_bit(initializer_list<bool> l) {
    dl = static_cast<int>(l.size());
    ile_slow = (dl+63)/rozmiarSlowa;
    tab = new slowo[ile_slow];
    int i=0;
    for(bool b : l){
        pisz(i++,b);
    }
}

tab_bit &tab_bit::operator|=(const tab_bit &other) {
    for(int i=0;i<ile_slow;i++){
        if(i<other.ile_slow)tab[i]|=other.tab[i];
    }
    return *this;
}

tab_bit &tab_bit::operator&=(const tab_bit &other) {
    for(int i=0;i<ile_slow;i++){
        if(i<other.ile_slow)tab[i]&=other.tab[i];
    }
    return *this;
}

tab_bit &tab_bit::operator^=(const tab_bit &other) {
    for(int i=0;i<ile_slow;i++){
        if(i<other.ile_slow)tab[i]^=other.tab[i];
    }
    return *this;
}



tab_bit tab_bit::operator~() {
    tab_bit wyn(dl);
    for(int i=0;i<ile_slow;i++){
        wyn[i]=~tab[i];
    }
    return wyn;
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
