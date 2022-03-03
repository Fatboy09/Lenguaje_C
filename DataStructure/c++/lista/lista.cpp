#include <iostream>
#include <cassert>
#include "lista.hpp"

template<typename T>
Lista<T>::~Lista() {}

template<typename T>
bool Lista<T>::is_empty() { return this->head == nullptr? true:false; }

template<typename T>
int Lista<T>::size(){
    return this->nNodos;
}

template<typename T>
void Lista<T>::insert_head(T e) {
    Nodo<T> *new_nodo = new Nodo<T>(e);
    if(this->is_empty())
        this->head = new_nodo;
    else {
        Nodo<T> *aux = this->head;
        new_nodo->next = aux;
        this->head = new_nodo;
    }
    this->nNodos++;
}

template<typename T>
void Lista<T>::insert_end(T e) {
    Nodo<T> *new_nodo = new Nodo<T>(e);
    if(this->is_empty())
        this->head = new_nodo;
    else {
        Nodo<T> *aux = this->head;
        while(aux->next != nullptr) {
            aux = aux->next;
        }
        aux->next = new_nodo;
    }
    this->nNodos++;
}

template<typename T>
void Lista<T>::insert_at(T e, const int& pos) {
    if(this->is_empty()) {
        std::cerr << "List is empty\n";
        return;
    }
    if((pos >= this->size()) || (pos < 0)) {
        std::cerr << "Error. Index out of range\n";
        return;
    }
    int idx = 0;
    if(pos == 0)
        this->insert_head(e);
    else if(pos == this->size() - 1)
        this->insert_end(e);
    else {
        Nodo<T> *new_nodo = new Nodo<T>(e);
        Nodo<T> *aux_head = this->head;
        while(idx < (pos-1)) {
            ++idx;
            aux_head = aux_head->next;
        }
        new_nodo->next = aux_head->next;
        aux_head->next = new_nodo;
        this->nNodos++;
    }
}

template<typename T>
void Lista<T>::remove_first() {
    if(this->is_empty())
        std::cerr << "List is empty\n";
    else {
        Nodo<T> *aux = this->head;
        this->head = aux->next;
        delete aux;
        this->nNodos--;
    }
}

template<typename T>
void Lista<T>::remove_last() {
    if(this->is_empty())
        std::cerr << "List is empty\n";
    else {
        int pos = this->size() - 2;
        Nodo<T> *aux_nodo = this->head;
        Nodo<T> *nodo_del = nullptr;
        for(int i = 0; i < pos; i++) {
            aux_nodo = aux_nodo->next;
        }
        nodo_del = aux_nodo->next;
        aux_nodo->next = nodo_del->next;
        delete nodo_del;
        this->nNodos--;
    }
}

template<typename T>
void Lista<T>::remove_at(const int& pos) {
    if(this->is_empty())
        std::cerr << "List is empty\n";
    else {
        int pos_max = this->size() - 1;
        if(pos < 0 || pos > pos_max)
            std::cerr << "Error. Index out of range\n";
        else {
            if(pos == 0)
                this->remove_first();
            else if(pos == pos_max)
                this->remove_last();
            else {
                Nodo<T> *aux_nodoH = this->head;
                Nodo<T> *nodo_del = nullptr;
                for(int i = 0; i < pos-1; i++) {
                    aux_nodoH = aux_nodoH->next;
                }
                nodo_del = aux_nodoH->next;
                aux_nodoH->next = nodo_del->next;
                delete nodo_del;
                this->nNodos--;
            }
        }
    }
}

template<typename T>
void Lista<T>::clear() {
    assert(!this->is_empty());
    this->head->delete_all();
    this->head = nullptr;
    this->nNodos = 0;
}

template<typename T>
int Lista<T>::search(const T& e) {
    int idx{-1};
    int cont{0};
    if(this->is_empty()) {
        std::cerr << "List is empty\n";
        return idx;
    }
    Nodo<T> *aux_head = this->head;
    while(aux_head) {
        if(aux_head->data == e) {
            idx = cont;
            break;
        }
        aux_head = aux_head->next;
        cont++;
    }
    return idx;
}

template<typename T>
T Lista<T>::get_element_at(const int& pos) {
    int pos_max = this->size() - 1;
    assert(!this->is_empty() && (pos >= 0 && pos <= pos_max));
    Nodo<T> *aux_nodo = this->head;
    for(int i = 0; i < pos; ++i)
        aux_nodo = aux_nodo->next;
    return aux_nodo->data;
}

template<typename T>
void Lista<T>::print() {
    Nodo<T> *aux = this->head;
    std::cout << "[";
    while(aux) {
        aux->print();
        aux = aux->next;
    }
    std::cout << "]\n";
}