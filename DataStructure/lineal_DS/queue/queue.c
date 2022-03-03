#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

nodo* crear_nodo(type_data x) {
    nodo* new_nodo = (nodo*) malloc(sizeof(nodo));
    if(new_nodo == NULL) {
        fprintf(stderr,"Error. No se reservo memoria\n");
        exit(EXIT_FAILURE);
    }
    new_nodo->elem = x;
    new_nodo->sig = NULL;
    return new_nodo;
}

void empty(queue** q) {
    (*q)->head = (*q)->tail = NULL;
}

int isEmpty_queue(queue* q) {
    return ((q->head == NULL) && (q->tail == NULL))? TRUE:FALSE;
}

int size_queue(queue* q) {
    int tam = 0;
    nodo* aux = q->head;
    while(aux != NULL) {
        ++tam;
        aux = aux->sig;
    }
    return tam;
}

void enqueue(queue** q,type_data x) {
    nodo* new_nodo = crear_nodo(x);
    if(((*q)->head == NULL) && ((*q)->tail == NULL)) {
        (*q)->head = (*q)->tail = new_nodo;
    } else {
        nodo* aux = (*q)->head;
        while(aux != (*q)->tail) {
            aux = aux->sig;
        }
        aux->sig = new_nodo;
        (*q)->tail = new_nodo;
    }
}

void dequeue(queue** q) {

    if(isEmpty_queue(*q)) {
        fprintf(stderr,"Error. Queue is empty\n");
    }
    else{
        nodo* aux = (*q)->head;
        if(aux->sig == NULL){
            (*q)->head = (*q)->tail = NULL;
        } else {
            (*q)->head = aux->sig;
        }
        free(aux);
    }
}

nodo* peek(queue* q) {
    if(isEmpty_queue(q)){
        fprintf(stderr,"Error. Queue is empty\n");
        return NULL;
    }
    return q->head;
}

void clear_queue(queue** q) {
    if(isEmpty_queue(*q)) {
        printf("Queue is empty\n");
    } else {
        while((*q)->head != NULL) {
            dequeue(q);
        }
    }
}

void print_dato(type_data x) {
    printf("%d ",x);
}

void print_queue(queue* q) {
    printf("\n[ ");
    nodo* aux = q->head;
    while(aux != NULL) {
        print_dato(aux->elem);
        aux = aux->sig;
    }
    //printf("%d ",aux->elem);
    printf("]\n");
}
