//
// Created by rufus on 13.03.18.
//

#include "Stack.hpp"

Stack::Stack(Stack &&s) noexcept {
    size = s.size;
    capacity = s.capacity;
    stack = s.stack;
    s.stack = nullptr;
}


Stack::Stack(int capacity) {
    stack = new std::string[capacity];
    this->capacity = capacity;
    size = 0;
}

Stack::Stack() : Stack(1) {
}

Stack::Stack(std::initializer_list<std::string> list) {
    capacity = static_cast<int>(list.size());
    stack = new std::string[capacity];
    size = 0;
    for (const auto &s : list) {
        stack[size++] = s;
    }
}

int Stack::getSize() const {
    return size;
}

std::string Stack::top() {
    if(size==0)throw std::invalid_argument("Stack is empty");
    return stack[size-1];
}

std::string Stack::pop() {
    if(size==0)throw std::invalid_argument("Stack is empty");
    return stack[--size];
}

void Stack::push(const std::string &s) {
    if (size >= capacity)throw std::invalid_argument("Stack is full");
    stack[size++] = s;
}

Stack &Stack::operator=(const Stack &s) {
    Stack tmp(s);
    *this = std::move(tmp);
    return *this;
}

Stack &Stack::operator=(Stack &&s) noexcept{
    if(&s == this)
        return *this;
    this->~Stack();
    capacity = s.capacity;
    size = s.size;
    stack = s.stack;
    s.stack = nullptr;
    return  *this;
}

Stack::Stack(const Stack &s) {
    size = s.size;
    capacity = s.capacity;
    stack = new std::string[capacity];
    for (int i = 0; i < s.size; i++) {
        stack[i] = s.stack[i];
    }
}
