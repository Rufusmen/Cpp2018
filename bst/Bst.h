//
// Created by rufus on 20.05.18.
//

#ifndef CPP2018_BST_H
#define CPP2018_BST_H

#include <initializer_list>
#include <functional>
#include <iostream>

template <typename T, class C = std::less_equal<T> >
class Bst {
private:
    class Node{
    public:
        Node *parent,*left,*right;
        T data;

        Node(Node *parent, T data);

        Node() = default;
        ~Node();

        friend std::ostream& operator<<(std::ostream& out, Node* node) {
            if (node->left != nullptr)out << "(" <<node->left << ")";
            out << node->data;
            if (node->right != nullptr) out <<  "(" << node->right << ")";

            return out;
        }
    };

    Node *root;
    int cnt;
public:
    Bst();
    Bst(std::initializer_list<T> list);
    ~Bst();
    void insert(T t);
    void remove(T t);
    bool find(T t);
    Bst(const Bst &s);

    Bst(Bst &&s) noexcept;

    Bst &operator=(const Bst &s);

    Bst &operator=(Bst &&s) noexcept;

    int size();

    friend std::ostream& operator<<(std::ostream& out, const Bst<T, C>& bst) {
        if (bst.root) {
            out << bst.root;
        }

        return out;
    }
private:
    bool comp(const T& e1, const T& e2);
    Node* _insert(T t, Node *node,Node *parent);
    Node* _remove(T t, Node *node);
    bool _find(T t,Node *node);
    T _min(Node *node);

};

template<typename T, class C>
bool Bst<T, C>::comp(const T &e1, const T &e2) {
    return C()(e1,e2);
}

template<typename T,class C>
Bst<T, C>::Node::Node(Bst::Node *parent,  T data):parent(parent),data(data) {
    left = nullptr;
    right = nullptr;
}


template<typename T, class C>
Bst<T, C>::Node::~Node() {
    if(left!= nullptr){
        delete(left);
    }
    if(right!= nullptr){
        delete(right);
    }
}

template<typename T, class C>
int Bst<T, C>::size() {
    return cnt;
}

template<typename T, class C>
Bst<T, C>::Bst() :root(nullptr), cnt(0) {
}

template<typename T, class C>
Bst<T, C>::Bst(std::initializer_list<T> list): root(nullptr), cnt(static_cast<int>(list.size())){
    for (auto& elem : list)
        insert(elem);
}

template<typename T, class C>
void Bst<T, C>::insert(T t) {
    cnt++;
    root = _insert(t,root, nullptr);
}

template<typename T, class C>
void Bst<T, C>::remove(T t) {
    if(root== nullptr||!_find(t,root)) return;
    cnt--;
    root = _remove(t,root);
}

template<typename T, class C>
bool Bst<T, C>::find(T t) {
    return _find(t,root);
}

template<typename T, class C>
Bst<T, C>::Bst(const Bst &s) {
//TODO
}

template<typename T, class C>
Bst<T, C>::Bst(Bst &&s) noexcept {
    root = s.root;
    cnt = s.cnt;
    s.cnt = 0;
    s.root = nullptr;
}

template<typename T, class C>
Bst<T,C> &Bst<T, C>::operator=(Bst &&s) noexcept {
    if(&s == this)
        return *this;
    this->~Bst();
    cnt = s.cnt;
    root = s.root;
    s.root = nullptr;
    s.cnt = 0;
    return  *this;
}

template<typename T, class C>
Bst<T, C>::~Bst() {
    if(root!= nullptr){
        root->~Node();
    }
    cnt = 0;
}

template<typename T, class C>
Bst<T,C> &Bst<T, C>::operator=(const Bst &s) {
    Bst<T,C> tmp(s);
    *this = std::move(tmp);
    return *this;
}

template<typename T, class C>
typename Bst<T,C>::Node *Bst<T, C>::_insert(T t, Bst::Node *node, Bst::Node *parent) {
        if(node == nullptr){
            node = new Node(parent,t);
            return node;
        }
        else{
            if(comp(t,node->data)){
                node->left = _insert(t,node->left,node);
            }
            else {
                node->right = _insert(t,node->right,node);
            }
        }
        return node;
}

template<typename T, class C>
typename Bst<T, C>::Node *Bst<T, C>::_remove(T t, Bst::Node *node) {
    if(node == nullptr)return nullptr;
    if(comp(t,node->data)&&(!comp(node->data,t)))node->left = _remove(t,node->left);
    else if(comp(node->data,t)&&(!comp(t,node->data)))node->right = _remove(t,node->right);
    else{
        if(node->left == nullptr)return node->right;
        else if(node->right == nullptr)return node->left;
        else{
            T value = _min(node);
            node->data = value;
            node->left = _remove(value,node->left);
        }
    }
    return node;
}

template<typename T, class C>
T Bst<T, C>::_min(Bst::Node *node) {
    if(node->left==nullptr)return node->data;
    return _min(node->left);
}

template<typename T, class C>
bool Bst<T, C>::_find(T t, Bst::Node *node) {
    if(node == nullptr)return false;
    if(comp(t,node->data)&&comp(node->data,t))return true;
    if(comp(t,node->data))return _find(t,node->left);
    else return _find(t,node->right);
}


#endif //CPP2018_BST_H
