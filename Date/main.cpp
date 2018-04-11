//
// Created by rufus on 26.03.18.
//

#include <vector>
#include <algorithm>
#include "event.h"

int main(){
    timePoint p(1998,3,27,17,30,0);
    vector<event> vec;
    vec.emplace_back(event(timePoint(),"Now"));
    vec.emplace_back(event(p,"Birthday"));
    p+=3600;
    vec.emplace_back(event(p,"Meet Dad"));
    vec.emplace_back(event(timePoint(2019),"2019"));
    sort(vec.begin(),vec.end());
    for (auto v:vec)cout << v.toString() << endl;
    p-=3600;
    cout << "Seconds on this cruel world: " << timePoint()-p << endl;
}
