#include <stdio.h>
#include <stdlib.h>
#include "listDE.h"

int isEmpty(lista lst) {
    return lst == NULL? TRUE:FALSE;
}

int size_list(lista lst) {
    if(lst == NULL)
        return 0;
    
    return 1 + size_list(lst->sig);
}

nodo* crear_nodo(type_data e) {
    nodo* new_nodo = (nodo*) malloc(sizeof(nodo));
    if(new_nodo == NULL) {
        fprintf(stderr,"Error. No se reservo espacio en memoria\n");
        exit(EXIT_FAILURE);
    }
    new_nodo->elem = e;
    new_nodo->sig = NULL;
    new_nodo->ant = NULL;
    return new_nodo;
}

void insert_nodo(lista* lst, type_data value) {
    nodo* new_nodo = crear_nodo(value);
    if(isEmpty(*lst)) {
        *lst = new_nodo;
    } else {
        lista aux = *lst;
        while(aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = new_nodo;
        new_nodo->ant = aux;
    }
}

void insert_at_begin(lista* lst,type_data value) {
    nodo* new_nodo = crear_nodo(value);
    if(isEmpty(*lst)) {
        *lst = new_nodo;
        return;
    }
    lista aux = *lst;
    new_nodo->sig = aux;
    aux->ant = new_nodo;
    *lst = new_nodo;
}

void insert_nodo_at(lista* lst,int pos, type_data value) {
    if(isEmpty(*lst)) {
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
        /*new_nodo->sig = aux;
        *lst = new_nodo;*/
        insert_at_begin(lst,value);
    }
    else if(pos == (tam - 1)) {
        insert_nodo(lst,value);
    } else {
        nodo* new_nodo = crear_nodo(value);
        lista aux = *lst;
        while(index < (pos - 1)) {
            ++index;
            aux = aux->sig;
        }
        new_nodo->sig = aux->sig;
        new_nodo->ant = aux;
        aux->sig = new_nodo;
    }
}

type_data remove_nodo(lista* lst) {
    type_data value = -1;
    if(isEmpty(*lst)) {
        fprintf(stderr,"Error. List is empty\n");
    } else {
        lista aux = *lst;
        value = aux->elem;
        aux->sig->ant = NULL;
        *lst = aux->sig;
        free(aux);
    }
    return value;
}

type_data remove_last_nodo(lista* lst) {
    type_data value = -1;
    if(isEmpty(*lst)) {
        fprintf(stderr,"Error. List is empty\n");
    } else {
        lista aux = *lst;
        lista aux2 = NULL;
        int indice;
        int pos = size_list(*lst) - 1;
        for(indice = 0; indice < pos - 1; ++indice) {
            aux = aux->sig;
        }
        aux2 = aux->sig;
        aux->sig = NULL;
        value = aux2->elem;
        free(aux2);
    }
    return value;
}

type_data remove_at(lista* lst,int pos) {
    type_data value = -1;
    if(isEmpty(*lst)) {
        fprintf(stderr,"Error. List is empty\n");
    } else {
        int lpos = size_list(*lst)-1;
        if((pos < 0) || (pos > lpos)) {
            fprintf(stderr,"Error. Index out of range\n");
        }
        else {
            if(pos == 0) {
                value = remove_nodo(lst);
            }
            else if(pos == lpos) {
                value = remove_last_nodo(lst);
            } else {
                lista aux = *lst;
                lista aux2 = NULL;
                int indice;
                for(indice = 0; indice < pos - 1; ++indice) {
                    aux = aux->sig;
                }
                aux2 = aux->sig;
                aux->sig = aux2->sig;
                aux2->sig->ant = aux;
                value = aux2->elem;
                free(aux2);
            }
        }
    }
    return value;
}

type_data get_element_at(lista lst, int pos) {
    type_data value = -1;
    if(isEmpty(lst)) {
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

int find_elem(lista lst, type_data value) {
    if(isEmpty(lst)) {
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

void print_list(lista lst) {
    printf("[ ");
    while(lst != NULL) {
        print_dato(lst->elem);
        lst = lst->sig;
    }
    printf("]\n");
}

void print_listReference(lista list) {
    if(list == NULL)
        return;
    printf("%p <- %d [%p]-> %p\n",(void*)list->ant,list->elem,(void*)list,(void*)list->sig);
    print_listReference(list->sig);
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