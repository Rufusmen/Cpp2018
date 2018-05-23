//
// Created by rufus on 20.05.18.
//

#include "Bst.h"
#include "BstCStr.h"
#include "BstPtr.h"
#include <iostream>

using namespace std;
using Type = const char *;
int main() {
    auto* bst = new Bst<Type>();
    string cmd;
    while (true) {
        cin >> cmd;
        if (cmd == "end")
            break;

        if (cmd == "out") {
            cout << *bst << "\n";
            continue;
        }

        string y;
        cin >> y;
        Type x = y.c_str();

        if (cmd == "ins")
            bst->insert(x);
        else if (cmd == "rem")
            bst->remove(x);
        else if (cmd == "fn")
            cout << "Bool: " << bst->find(x) << "\n";
        else
            cout << "Bad cmd\n";
    }
    bst->~Bst();
    return 0;
}