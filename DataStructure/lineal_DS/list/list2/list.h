#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <limits.h>

#define TRUE 1
#define FALSE 0
#define ERROR UINT_MAX

typedef unsigned type_data;

typedef struct NODO {
    unsigned elem;
    struct NODO* sig;
} nodo;

typedef nodo* lista;

int isEmpty_linkedList(lista);
int size_list(lista);
void linkedList_insert_node(lista*,type_data);
void linkedList_insert_node_at(lista*,int,type_data);
void linkedList_insert_at_begin(lista*,type_data);
nodo linkedList_remove_node_at(lista*, int);
nodo linkedList_remove_node(lista*);
nodo linkedList_remove_last_node(lista*);
void clear_list(lista*);
int is_element_at_linkedList(lista,type_data);
type_data linkedList_get_element_at(lista,int);
void print_linkedList(lista);

#endif // LIST_H_INCLUDED
