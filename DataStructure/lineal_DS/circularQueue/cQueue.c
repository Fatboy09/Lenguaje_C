#include <stdio.h>
#include <stdlib.h>
#include "cQueue.h"

void empty_Cqueue(queueC** q) {
    (*q)->head = (*q)->tail = NULL;
}

int is_emptyCqueue(queueC* q) {
    return q->head == NULL? 1:0;
}

int size_Cqueue(nodo* list, queueC* q) {
    if(is_emptyCqueue(q))
        return 0;

    if(list->sig == q->head)
        return 1;
    
    return 1 + size_Cqueue(list->sig,q);
}

nodo* crear_nodo(elem e) {
    nodo* new_nodo = (nodo*) malloc(sizeof(nodo));

    if(new_nodo == NULL) {
        fprintf(stderr,"Error. No se reservo espacio en memoria\n");
        exit(EXIT_FAILURE);
    }

    new_nodo->e = e;
    new_nodo->sig = NULL;

    return new_nodo;   
}

void enqueueCQ(queueC** q, elem e) {
    nodo* new_nodo = crear_nodo(e);
    
    if(is_emptyCqueue(*q)) {
        (*q)->head = new_nodo;
        new_nodo->sig = new_nodo;
    } else {
        nodo* aux = (*q)->head;
        while(aux->sig != (*q)->head) {
            aux = aux->sig;
        }
        aux->sig = new_nodo;
        new_nodo->sig = (*q)->head;
        (*q)->tail = new_nodo;
    }
}

void dequeueCQ(queueC** q) {
    if(is_emptyCqueue(*q)) {
        fprintf(stderr,"Queue is empty\n");
        return;
    }

    if((*q)->head == (*q)->tail) {
        free((*q)->head);
        (*q)->head = (*q)->tail = NULL;
    } else {
        nodo* aux = (*q)->head;
        (*q)->head = aux->sig;
        (*q)->tail->sig = aux->sig;
        free(aux);
    }
}

void clear_Cqueue(queueC** q) {
    if(is_emptyCqueue(*q))
        return;
    
    while((*q)->head != (*q)->tail) {
        dequeueCQ(q);
    }
    free((*q)->head);
    (*q)->head = (*q)->tail = NULL;
}

void print_elem(elem e) {
    printf("%d ", e);
}

void print_Cqueue(queueC* q) {
    printf("[ ");

    if(!is_emptyCqueue(q)) {
        nodo* aux = q->head;

        while(aux->sig != q->head) {
            print_elem(aux->e);
            aux = aux->sig;
        }
        print_elem(aux->e);
    }
    printf("]");
}

void print_CqueueRef(queueC* q, nodo* list) {
    if(is_emptyCqueue(q))
        return;
    
    if(list->sig == q->head) {
        printf("%d [%p] -> %p\n",list->e,(void*) list,(void*) list->sig);
        return;
    }
    
    printf("%d [%p] -> %p\n",list->e,(void*) list,(void*) list->sig);
    print_CqueueRef(q,list->sig);
}

nodo* peek_Cqueue(queueC* q) {
    return q->head;
}