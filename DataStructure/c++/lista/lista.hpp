#ifndef _LISTAH
#define _LISTAH

#include "nodo.hpp"
#include "nodo.cpp"

template<class T>
class Lista {
    public:
        Lista() {}
        Lista(const Lista<T>& ptr) {}
        Lista& operator = (const Lista<T>& ptr);
        ~Lista();
        bool is_empty();
        void insert_head(T);
        void insert_end(T);
        void insert_at(T e, const int& pos);
        void remove_first();
        void remove_last();
        void remove_at(const int& pos);
        void clear();
        T get_element_at(const int& pos);
        int search(const T& e);
        void print();
        int size();

    private:
        Nodo<T> *head{};
        int nNodos{};

};

#endif