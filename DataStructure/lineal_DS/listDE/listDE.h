#ifndef LISTDE_H_INCLUDED
#define LISTDE_H_INCLUDED

#define TRUE 1
#define FALSE 0

typedef int type_data;

typedef struct nodo {
    type_data elem;
    struct nodo* sig;
    struct nodo* ant;
}nodo;

typedef nodo* lista;

int isEmpty(lista list);
int size_list(lista list);
void insert_nodo(lista* list,type_data e);
void insert_nodo_at(lista* list,int,type_data e);
void insert_at_begin(lista* list,type_data e);
type_data remove_at(lista* list, int idx);
type_data remove_nodo(lista* list);
type_data remove_last_nodo(lista* list);
void clear_list(lista* list);
int find_elem(lista list,type_data e);
type_data get_element_at(lista list,int idx);
void print_list(lista list);
void print_listReference(lista list);

#endif // LIST_H_INCLUDED
