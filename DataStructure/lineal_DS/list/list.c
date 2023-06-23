#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/***
 * @brief valida si la lista esta o no vacía
 * @param lst puntero de tipo nodo que representa a la DE lista
 * @returns Devuelve un valor entero, 1 o 0
 ***/
int isEmpty_linkedList(lista lst) {
    return lst == NULL? TRUE:FALSE;
}

/***
 * @brief calcula el total de elementos que contiene la lista
 * @param lst puntero de tipo nodo que representa a la DE lista
 * @returns Devuelve un valor entero
 ***/
int size_list(lista lst) {
    int tam = 0;
    while(!isEmpty_linkedList(lst)) {
        tam++;
        lst = lst->sig;
    }
    return tam;
}

/***
 * @brief reserva en memoria dinamica una estructura de tipo nodo
 * @param e tipo de dato que se guarda en la lista
 * @returns Devuelve una estructura de tipo de nodo guardado en memoria dinámica
 ***/
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

/***
 * @brief Inserta un elemento nuevo al final de la lista
 * @param lst puntero doble de tipo nodo que representa a la DE lista
 * @param value representa el valor que se almacenara en la lista
 ***/
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

/***
 * @brief Inserta un elemento nuevo al inicio de la lista
 * @param lst puntero doble de tipo nodo que representa a la DE lista
 * @param value representa el valor que se almacenara en la lista
 ***/
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

/***
 * @brief Inserta un elemento nuevo en la lista en la posicion en el que se desea insertar
 * @param lst puntero doble de tipo nodo que representa a la DE lista
 * @param pos representa el indice de la posición de la lista, es un valor entero cuyo rango esta entre 0 hasta el total de elementos - 1
 * @param value representa el valor que se almacenara en la lista
 ***/
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

/***
 * @brief Elimina el primer elemento de la lista
 * @param lst puntero doble de tipo nodo que representa a la DE lista
 * @returns valor del dato en el nodo a eliminar
 ***/
type_data linkedList_remove_node(lista* lst) {
    type_data value = -1;
    if(isEmpty_linkedList(*lst)) {
        fprintf(stderr,"Error. List is empty\n");
    } else {
        lista aux = *lst;
        value = aux->elem;
        *lst = aux->sig;
        free(aux);
    }
    return value;
}

/***
 * @brief Elimina el último elemento de la lista
 * @param lst puntero doble de tipo nodo que representa a la DE lista
 * @returns valor del dato en el nodo a eliminar
 ***/
type_data linkedList_remove_last_node(lista* lst) {
    type_data value = -1;
    if(isEmpty_linkedList(*lst)) {
        fprintf(stderr,"Error. List is empty\n");
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
        value = aux2->elem;
        free(aux2);
    }
    return value;
}

/***
 * @brief Elimina un elemento ubicada en una posición valida de la lista
 * @param lst puntero doble de tipo nodo que representa a la DE lista
 * @param pos representa el indice de la posición de la lista, es un valor entero cuyo rango esta entre 0 hasta el total de elementos - 1
 * @returns valor del dato en el nodo a eliminar
 ***/
type_data linkedList_remove_node_at(lista* lst,int pos) {
    type_data value = -1;
    if(isEmpty_linkedList(*lst)) {
        fprintf(stderr,"Error. List is empty\n");
    } else {
        int lpos = size_list(*lst) - 1;
        if((pos < 0) || (pos > lpos)) {
            fprintf(stderr,"Error. Index out of range\n");
        }
        else {
            if(pos == 0) {
                value = linkedList_remove_node(lst);
            }
            else if(pos == lpos) {
                value = linkedList_remove_last_node(lst);
            } else {
                lista aux = *lst;
                lista aux2 = NULL;
                int indice;
                for(indice = 0; indice < pos - 1; ++indice) {
                    aux = aux->sig;
                }
                aux2 = aux->sig;
                aux->sig = aux2->sig;
                value = aux2->elem;
                free(aux2);
            }
        }
    }
    return value;
}

/***
 * @brief Obtiene el nodo que se ubica en la posición de la lista
 * @param lst puntero de tipo nodo que representa a la DE lista
 * @param pos representa el indice de la posición de la lista, es un valor entero cuyo rango esta entre 0 hasta el total de elementos - 1
 * @returns regresa el valor del dato
 ***/
type_data linkedList_get_element_at(lista lst, int pos) {
    type_data value = -1;
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

/***
 * @brief valida si el dato existe dentro de la lista
 * @param lst puntero de tipo nodo que representa a la DE lista
 * @param value representa el dato a buscar dentro de la lista
 * @returns retorna 1 o 0 dependiendo del resultado del proceso
 ***/
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

/***
 * @brief imprime en consola el valor del dato
 * @param x representa el dato a imprimir su valor
 ***/
void print_dato(type_data x) {
    printf("%d ", x);
}

/***
 * @brief imprime en consola los datos de la lista
 * @param lst puntero de tipo nodo que representa a la DE lista
 ***/
void print_linkedList(lista lst) {
    printf("[ ");
    while(lst != NULL) {
        print_dato(lst->elem);
        lst = lst->sig;
    }
    printf("]\n");
}

/***
 * @brief limpia todo el contenido de la lista
 * @param lst puntero doble de tipo nodo que representa a la DE lista
 ***/
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
