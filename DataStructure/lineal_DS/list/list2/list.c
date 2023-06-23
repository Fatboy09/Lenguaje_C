#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int isEmpty_linkedList(lista lst) {
    return lst == NULL? TRUE:FALSE;
}

int size_list(lista lst) {
    int tam = 0;
    while(!isEmpty_linkedList(lst)) {
        tam++;
        lst = lst->sig;
    }
    return tam;
}

nodo* crear_nodo(type_data e) {
    nodo* new_nodo = (nodo*) malloc(sizeof(nodo));
    if(new_nodo == NULL) {
        fprintf(stderr,"No se reservo espacio en memoria\n");
        exit(EXIT_FAILURE);
    }
    new_nodo->elem = e;
    new_nodo->sig = NULL;
    return new_nodo;
}

void linkedList_insert_node(lista* lst, type_data value) {
    nodo* new_nodo = crear_nodo(value);
    if(isEmpty_linkedList(*lst)) {
        *lst = new_nodo;
    } else {
        lista aux = *lst;
        while(aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = new_nodo;
    }
}

void linkedList_insert_at_begin(lista* lst,type_data value) {
    nodo* new_nodo = crear_nodo(value);
    if(isEmpty_linkedList(*lst)) {
        *lst = new_nodo;
        return;
    }
    lista aux = *lst;
    new_nodo->sig = aux;
    *lst = new_nodo;
}

void linkedList_insert_node_at(lista* lst,int pos, type_data value) {
    if(isEmpty_linkedList(*lst)) {
        fprintf(stderr,"List is empty\n");
        return;
    }
    int tam = size_list(*lst);
    if((pos >= tam) || (pos < 0)) {
        fprintf(stderr,"Error. Index out of range\n");
        return;
    }
    int index = 0;
    if(pos == 0){
        linkedList_insert_at_begin(lst,value);
    }
    else if(pos == (tam-1)) {
        linkedList_insert_node(lst,value);
    } else {
        nodo* new_nodo = crear_nodo(value);
        lista aux = *lst;
        while(index < (pos-1)) {
            ++index;
            aux = aux->sig;
        }
        new_nodo->sig = aux->sig;
        aux->sig = new_nodo;
    }
}

nodo linkedList_remove_node(lista* lst) {
	nodo node;
    if(isEmpty_linkedList(*lst)) {
        fprintf(stderr,"Error. List is empty\n");
        exit(EXIT_FAILURE);
    } else {
        lista aux = *lst;
        *lst = aux->sig;
        node.elem = aux->elem;
        node.sig = aux->sig;
        free(aux);
    }
    return node;
}

nodo linkedList_remove_last_node(lista* lst) {
	
	nodo node;
	
    if(isEmpty_linkedList(*lst)) {
        fprintf(stderr,"Error. List is empty\n");
        exit(EXIT_FAILURE);
    } else {
        lista aux = *lst;
        lista aux2 = NULL;
        int indice;
        int pos = size_list(*lst)-1;
        for(indice = 0; indice < pos-1; ++indice) {
            aux = aux->sig;
        }
        aux2 = aux->sig;
        aux->sig = NULL;
        node.elem = aux2->elem;
        node.sig = aux2->sig;
        free(aux2);
    }
    return node;
}

nodo linkedList_remove_node_at(lista* lst,int pos) {
    
    nodo node;
    
    if(isEmpty_linkedList(*lst)) {
        fprintf(stderr,"Error. List is empty\n");
        exit(EXIT_FAILURE);
    } else {
        int lpos = size_list(*lst)-1;
        if((pos < 0) || (pos > lpos)) {
            fprintf(stderr,"Error. Index out of range\n");
            exit(EXIT_FAILURE);
        }
        else {
            if(pos == 0) {
                node = linkedList_remove_node(lst);
            }
            else if(pos == lpos) {
                node = linkedList_remove_last_node(lst);
            } else {
                lista aux = *lst;
                lista aux2 = NULL;
                int indice;
                for(indice = 0; indice < pos-1; ++indice) {
                    aux = aux->sig;
                }
                aux2 = aux->sig;
                aux->sig = aux2->sig;
                node.elem = aux2->elem;
                node.sig = aux2->sig;
                free(aux2);
            }
        }
    }
    return node;
}

type_data linkedList_get_element_at(lista lst, int pos) {
    type_data value = ERROR;
    if(isEmpty_linkedList(lst)) {
        fprintf(stderr,"Error. List is empty\n");
    } else {
        int lpos = size_list(lst)-1;
        if((pos < 0) || (pos > lpos)) {
            fprintf(stderr,"Error. Index out of range\n");
        } else {
            for(int i = 0; i < pos; ++i) {
                lst = lst->sig;
            }
            value = lst->elem;
        }
    }
    return value;
}

int is_element_at_linkedList(lista lst, type_data value) {
    if(isEmpty_linkedList(lst)) {
        fprintf(stderr,"Error. List is empty\n");
        return -1;
    }
    int flag = FALSE;
    while(lst != NULL) {
        if(lst->elem == value) {
            flag = TRUE;
            break;
        }
        lst = lst->sig;
    }
    return flag;
}

void print_dato(type_data x) {
    printf("%d ", x);
}

void print_linkedList(lista lst) {
    printf("[ ");
    while(lst != NULL) {
        print_dato(lst->elem);
        lst = lst->sig;
    }
    printf("]\n");
}

void clear_list(lista* lst) {
    if(isEmpty_linkedList(*lst))
        return;
        
    int size = size_list(*lst);
    
    if(size == 1) {
        free(*lst);
        *lst = NULL;
        return;
    }
    linkedList_remove_node(lst);
    clear_list(lst);
}
