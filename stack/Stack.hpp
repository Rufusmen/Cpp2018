//
// Created by rufus on 13.03.18.
//

#ifndef CPP2018_STACK_H
#define CPP2018_STACK_H

#include <iostream>

class Stack {
private:
    std::string *stack;
    int capacity = 1;
    int size = 0;
public:
    Stack();

    explicit Stack(int capacity);

    Stack(std::initializer_list<std::string> list);

    Stack(const Stack &s);

    Stack(Stack &&s) noexcept;

    Stack &operator=(const Stack &s);

    Stack &operator=(Stack &&s) noexcept;

    ~Stack() = default;

    int getSize() const;

    void push(const std::string &s);

    std::string top();

    std::string pop();
};

#endif //CPP2018_STACK_H
