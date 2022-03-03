#ifndef _NODOH
#define _NODOH

template<class T>
class Nodo {
    public:
        T data{};
        Nodo* next{};

        Nodo();
        Nodo(T e);
        Nodo(const Nodo<T>&);
        Nodo& operator=(const Nodo<T>& ptr); 
        ~Nodo();
        void delete_all();
        void print();
};

#endif