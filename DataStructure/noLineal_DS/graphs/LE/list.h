#ifndef LISTGPH_H
#define LISTGPH_H

#include <stdbool.h>

typedef struct NODO_L {
    unsigned dest;
    int weight;
    struct NODO_L* sig;
}nodoL;

typedef nodoL* lista;

bool isEmpty(lista);
int size_list(lista);
void insert_nodo(lista*,unsigned,int);
void remove_nodo(lista*);
void clear_list(lista*);
void print_list(lista);

#endif // LISTGPH_H
