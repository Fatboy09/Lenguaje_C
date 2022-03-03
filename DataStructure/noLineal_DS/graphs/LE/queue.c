#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

nodoQ* crear_nodoQ(type_data x) {
    nodoQ* new_nodo = (nodoQ*) malloc(sizeof(nodoQ));
    if(new_nodo == NULL) {
        fprintf(stderr,"Error. No se reservo memoria\n");
        exit(EXIT_FAILURE);
    }
    new_nodo->elem = x;
    new_nodo->sig = NULL;
    return new_nodo;
}

queue* newQueue() {
    queue *q = malloc(sizeof(queue));
    if(!q) {
		printf("Error. No se pudo asignar memoria dinamicamente.\n");
		exit(EXIT_FAILURE);
	}
    q->head = q->tail = NULL;
    return q;
}

int isEmpty_queue(queue* q) {
    return ((q->head == NULL) && (q->tail == NULL))? TRUE:FALSE;
}

int size_queue(queue* q) {
    int tam = 0;
    nodoQ* aux = q->head;
    while(aux != NULL) {
        ++tam;
        aux = aux->sig;
    }
    return tam;
}

void enqueue(queue** q,type_data x) {
    nodoQ* new_nodo = crear_nodoQ(x);
    if(((*q)->head == NULL) && ((*q)->tail == NULL)) {
        (*q)->head = (*q)->tail = new_nodo;
    } else {
        nodoQ* aux = (*q)->head;
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
        nodoQ* aux = (*q)->head;
        if(aux->sig == NULL){
            (*q)->head = (*q)->tail = NULL;
        } else {
            (*q)->head = aux->sig;
        }
        free(aux);
    }
}

type_data peek(queue* q) {
    assert(!isEmpty_queue(q));
    return q->head->elem;
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

void print_datoQ(type_data x) {
    printf("%u ",x);
}

void print_queue(queue* q) {
    printf("\n[ ");
    nodoQ* aux = q->head;
    while(aux != NULL) {
        print_datoQ(aux->elem);
        aux = aux->sig;
    }
    //printf("%d ",aux->elem);
    printf("]\n");
}

void destroy_queue(queue** q) {
	if(*q != NULL) {
		free(*q);
		*q = NULL;
	}
}
