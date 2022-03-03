#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <limits.h>

#define TRUE 1
#define FALSE 0
#define ERROR UINT_MAX
typedef struct NODO {
    unsigned elem;
    struct NODO* sig;
}nodo;

typedef unsigned type_data;
typedef nodo* lista;

int isEmpty(lista);
int size_list(lista);
void insert_nodo(lista*,type_data);
void insert_nodo_at(lista*,int,type_data);
void insert_at_begin(lista*,type_data);
type_data remove_at(lista*, int);
type_data remove_nodo(lista*);
type_data remove_last_nodo(lista*);
void clear_list(lista*);
int find_elem(lista,type_data);
type_data get_element_at(lista,int);
void print_list(lista);

#endif // LIST_H_INCLUDED
