//
// Created by rufus on 13.03.18.
//

#include <iostream>
#include "Stack.hpp"

void test(){
    std::cout << "test" << std::endl;
    Stack s = Stack();
    s.push("ala");
    try{s.push("ola");}catch (std::invalid_argument &e){
        std::cerr << e.what();
    }
    Stack s2 = {"a","b","c"};
    std::cout << s2.pop() << std::endl;
    Stack s3 = std::move(s2);
    std::cout << s3.top() << std::endl;
    s3.push("d");
    Stack s4(s3);
    std::cout << s4.pop() << std::endl;
    std::cout << s3.pop() << std::endl;
    std::cout << "test end" << std::endl;
    std::cerr.flush();
}

int main() {
    test();
    std::cout << "Podaj max pojemność kopca" << std::endl;
    int cap;
    std::cin >> cap;
    auto *stack = new Stack(cap);
    std::cout << "e - exit\na <x> - add\nt - top\np - pop" << std::endl;
    char c;
    std::cin >> c;
    while (c != 'e') {
        try {
            switch (c) {
                case 'a': {
                    std::string s;
                    std::cin >> s;
                    stack->push(s);
                    break;
                }
                case 't':
                    std::cout << stack->top() << std::endl;
                    break;
                case 'p':
                    std::cout << stack->pop() << std::endl;
                    break;
                case 's':
                    std::cout << stack->getSize() << std::endl;
                    break;
                default:
                    break;
            }
        }catch (std::invalid_argument &e){
            std::cerr << e.what() << std::endl;
        }
        std::cin >> c;
    }
    delete(stack);
    return 0;
}