#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

bool isEmpty(lista lst) {
    return lst == NULL? true:false;
}

int size_list(lista lst) {
    int tam = 0;
    while(!isEmpty(lst)) {
        tam++;
        lst = lst->sig;
    }
    return tam;
}

nodoL* crear_nodoL(unsigned d, int w) {
    nodoL* new_nodo = (nodoL*) malloc(sizeof(nodoL));
    if(new_nodo == NULL) {
        fprintf(stderr,"No se reservo espacio en memoria\n");
        exit(EXIT_FAILURE);
    }
    new_nodo->dest = d;
    new_nodo->weight = w;
    new_nodo->sig = NULL;
    return new_nodo;
}

void insert_nodo(lista* lst, unsigned d, int w) {
    nodoL* new_nodo = crear_nodoL(d,w);
    if(isEmpty(*lst)) {
        *lst = new_nodo;
    } else {
        lista aux = *lst;
        while(aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = new_nodo;
    }
}

void remove_nodo(lista* lst) {
    assert(!isEmpty(*lst));
	lista aux = *lst;
	*lst = aux->sig;
	free(aux);
}

void print_dato(unsigned x) {
    printf("%u ", x);
}

void print_list(lista lst) {
    printf("[ ");
    while(lst != NULL) {
        print_dato(lst->dest);
        lst = lst->sig;
    }
    printf("]\n");
}

void clear_list(lista* list) {
    if(isEmpty(*list))
        return;
    int size;
    remove_nodo(list);
    size = size_list(*list);
    if(size == 1) {
        free(*list);
        *list = NULL;
        return;
    }
    clear_list(list);
}
