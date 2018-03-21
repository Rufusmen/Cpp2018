//
// Created by rufus on 20.03.18.
//

#include "tab_bit.hpp"


int main() {
    tab_bit t(46);         // tablica 46-bitowa (zainicjalizowana zerami)
    tab_bit u(45ull);      // tablica 64-bitowa (sizeof(uint64_t)*8)
    tab_bit v(t);          // tablica 46-bitowa (skopiowana z t)
    tab_bit w(tab_bit { 1, 0, 1, 1, 0, 0, 0, 1 }); // tablica 8-bitowa (przeniesiona)
    v[0] = 1;              // ustawienie bitu 0-go bitu na 1
    t[45] = true;          // ustawienie bitu 45-go bitu na 1
    bool b = v[1];         // odczytanie bitu 1-go
    u[63] = 1;
    u[45] = u[46] = u[63]; // przepisanie bitu 63-go do bitow 45-go i 46-go
    cout << t << endl;// wysietlenie zawartości tablicy bitów na ekranie
    cout << u << endl;
    cout << w << endl;
    tab_bit t1(0xff00ff00ull);
    tab_bit t2(0x55555555ull);
    cout << t1 << "\n" << t2 << endl;
    tab_bit t3 = (t1 & t2);
    cout << t3 << endl;
    t3 = (t1 | t2);
    cout << t3 << endl;
    t3 = (t1 ^ t2);
    cout << t3 << endl;
    t3 = ~t1;
    cout << t3 << endl;
    t3|=t1;
    cout << t3 << endl;
    tab_bit t4(8);
    cin >> t4;
    cout << t4 << endl;
    auto t5 = new tab_bit(128);
    cout << *t5;
    delete(t5);
}