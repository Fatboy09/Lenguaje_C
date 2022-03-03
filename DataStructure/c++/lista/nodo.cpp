#include <iostream>
#include "nodo.hpp"

template<typename T>
Nodo<T>::Nodo() {}

template<typename T>
Nodo<T>::Nodo(const Nodo<T>& ptr) {}

template<typename T>
Nodo<T>::Nodo(T e) {
    this->data = e;
    this->next = nullptr;
}

template<typename T>
Nodo<T>::~Nodo() {}

template<typename T>
void Nodo<T>::delete_all() {
    if(this->next)
        this->next->delete_all();
    delete this;
}

template<typename T>
void Nodo<T>::print() {
    std::cout << ' ' << this->data << ' ';
}