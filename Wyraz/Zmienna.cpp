//
// Created by rufus on 09.04.18.
//

#include "Zmienna.h"

#include <utility>

Zmienna::Zmienna(string s) :name(std::move(s)){
}

vector<pair<string,double> > Zmienna::vec;

double Zmienna::find(string s) {
    for (auto &i : vec) {
        if(i.first == s){
            return i.second;
        }
    }
    return NAN;
}

void Zmienna::add(string s, double x) {
    remove(s);
    vec.emplace_back(s,x);
}

void Zmienna::remove(string s) {
    for(int i=0;i<vec.size();i++){
        if(vec[i].first == s){
            vec.erase(vec.begin()+i);
            break;
        }
    }
}

double Zmienna::oblicz() {
    return find(name);
}

string Zmienna::toString() {
    return name;
}
