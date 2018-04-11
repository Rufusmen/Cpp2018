//
// Created by rufus on 09.04.18.
//

#include "Wyrazenie.h"
#include "Pi.h"
#include "Sin.h"
#include "Cos.h"
#include "Sub.h"
#include "Liczba.h"
#include "Add.h"
#include "Mul.h"
#include "Div.h"
#include "Zmienna.h"
#include "Pow.h"
#include "E.h"
#include "Mod.h"
#include "Opos.h"
#include "Fi.h"
#include "Rev.h"
#include "Ln.h"
#include "Exp.h"
#include "Log.h"

int main(){
    Wyrazenie *w1 = new Div(
            new Mul(
                    new Sub(
                            new Zmienna("x"),
                            new Liczba(1)
                    ),
                    new Zmienna("x")
            ),
            new Liczba(2)
    );
    cout << w1->toString() << endl;
    for(int i=0;i<=100;i++){
        Zmienna::add("x",(double)i/100.0);
        cout << w1->oblicz() << endl;
    }
    Wyrazenie *w2 = new Div(
            new Add(
                    new Liczba(3),
                    new Liczba(5)
            ),
            new Add(
                    new Liczba(2),
                    new Mul(
                            new Zmienna("x"),
                            new Liczba(7)
                    )
            )
    );
    cout << w2->toString() << endl;
    for(int i=0;i<=100;i++){
        Zmienna::add("x",(double)i/100.0);
        cout << w2->oblicz() << endl;
    }
    auto w3 = new Sub(
            new Add(
                    new Liczba(2),
                    new Mul(
                            new Zmienna("x"),
                            new Liczba(7))),
            new Add(
                    new Mul(
                            new Zmienna("x"),
                            new Liczba(3)),
                    new Liczba(5)));
    cout << w3->toString() << endl;
    for(int i=0;i<=100;i++){
        Zmienna::add("x",(double)i/100.0);
        cout << w3->oblicz() << endl;
    }
    auto w4 = new Div(
            new Cos(
                    new Mul(
                            new Add(
                                    new Zmienna("x"),
                                    new Liczba(1)
                            ),
                            new Zmienna("x")
                    )
            ),
            new Pow(
                    new E(),
                    new Pow(
                            new Zmienna("x"),
                            new Liczba(2)
                    )
            )
    );
    cout << w4->toString() << endl;
    for(int i=0;i<=100;i++){
        Zmienna::add("x",(double)i/100.0);
        cout << w4->oblicz() << endl;
    }
    Wyrazenie *w = new Sub(
            new Pi(),
            new Add(
                    new Rev(new Opos(new Fi())),
                    new Mul(
                            new Add(
                                    new Mod(
                                            new Liczba(2),
                                            new Zmienna("y")
                                    ),
                                    new Ln(new Exp(new Liczba(1)))
                            ),
                            new Log(new Liczba(2),new Liczba(4))
                    )
            )
    );
    Zmienna::add("y",5);
    cout << w->oblicz() << endl;
    cout << w->toString();
}