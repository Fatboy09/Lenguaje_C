#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queue head = NULL;
queue tail = NULL;

static int tamanio = 0;

nodo* crear_nodo(int x) {
    nodo* new_nodo = (nodo*) malloc(sizeof(nodo));
    if(new_nodo == NULL) {
        fprintf(stderr,"Error. No se reservo memoria\n");
        exit(EXIT_FAILURE);
    }
    new_nodo->elem = x;
    new_nodo->sig = NULL;
    return new_nodo;
}

int isEmpty_queue() {
    return ((head == NULL) && (tail == NULL))? TRUE:FALSE;
}

int size_queue() {
    return tamanio;
}

void enqueue(int x) {
    nodo* new_nodo = crear_nodo(x);
    if((head == NULL) && (tail == NULL)) {
        head = tail = new_nodo;
    } else {
        nodo* aux = head;
        while(aux != tail) {
            aux = aux->sig;
        }
        aux->sig = new_nodo;
        tail = new_nodo;
    }
    tamanio++;
}

int dequeue() {
    int x = -1;
    if(isEmpty_queue()) {
        fprintf(stderr,"Queue is empty\n");
    }
    else{
        nodo* aux = head;
        x = aux->elem;
        if(aux->sig == NULL){
            head = tail = NULL;
        } else {
            head = aux->sig;
        }
        tamanio--;
        free(aux);
    }
    return x;
}

nodo* peek() {
    if(isEmpty_queue()){
        fprintf(stderr,"Error. Queue is empty\n");
        return NULL;
    }
    return head;
}

void clear_queue() {
    if(isEmpty_queue()) {
        printf("Queue is empty\n");
    } else {
        while(head != NULL) {
            dequeue();
        }
    }
}

void print_queue() {
    printf("\n[ ");
    nodo* aux = head;
    while(aux != NULL) {
        printf("%d " ,aux->elem);
        aux = aux->sig;
    }
    //printf("%d ",aux->elem);
    printf("]\n");
}
