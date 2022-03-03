#include "pQueue.h"
#include <stdio.h>
#include <stdlib.h>

nodo* crear_nodo(elem dato, int p) {
    nodo* newNodo = (nodo*) malloc(sizeof(nodo));

    if(newNodo == NULL) {
        fprintf(stderr,"Error. No se reservo memoria\n");
        exit(EXIT_FAILURE);
    }

    newNodo->e = dato;
    newNodo->priority = p;
    newNodo->sig = NULL;

    return newNodo;
}

void empty_queue(queue** q) {
    (*q)->head = (*q)->tail = NULL;
}

int is_emptyQueue(queue* q) {
    return q->head == NULL && q->tail == NULL? 1:0;
}

int size_queue(queue* q) {
    int size = 0;

    nodo* aux = q->head;
    while(aux != NULL) {
        ++size;
        aux = aux->sig;
    }

    return size;
}

int queue_size(nodo* node) {
    if(node == NULL)
        return 0;
    
    return 1 + queue_size(node->sig);
}

void enqueue(queue** q, elem e, int priority) {
    nodo* newNodo = crear_nodo(e, priority);
    if(!is_emptyQueue(*q)) {
        nodo* start = (*q)->head;
        if(start->priority > priority) {
            //printf("%d@%d :)\n",start->priority,priority);
            newNodo->sig = start;
            (*q)->head = newNodo;
        } else {
            while(start->sig != NULL && start->sig->priority <= priority) {
                start = start->sig;
            }
            newNodo->sig = start->sig;
            start->sig = newNodo;
        }
        if(newNodo->sig == NULL)
            (*q)->tail = newNodo;
    } else {
        (*q)->head = (*q)->tail = newNodo;
    }
}

void dequeue(queue** q) {
    if(is_emptyQueue(*q)) {
        fprintf(stderr,"Error. Queue is empty\n");
    }
    else {
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
    return q->head;
}

nodo* peek_tail(queue* q) {
    return q->tail;
}

void print_elem(elem e) {
    printf("%d ", e);
}

void print_queue(queue* q) {
    printf("[ ");
    nodo* aux = q->head;
    while (aux != NULL) {
        print_elem(aux->e);
        aux = aux->sig;
    }
    printf("]");
}

void clear_queue(queue** q) {
    if(is_emptyQueue(*q)) {
        printf("Queue is empty\n");
    } else {
        while((*q)->head != NULL) {
            dequeue(q);
        }
    }
    //(*q)->head = (*q)->tail = NULL;
} 