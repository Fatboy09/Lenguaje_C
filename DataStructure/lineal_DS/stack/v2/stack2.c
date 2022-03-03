#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

static int tamanio = 0;

nodo* crear_Nodo(int z) {
    nodo* new_nodo = (nodo*) malloc(sizeof(nodo));
    if(new_nodo == NULL) {
        fprintf(stderr,"Error. No se pudo reservar memoria.\n");
        exit(EXIT_FAILURE);
    }
    new_nodo->elem = z;
    new_nodo->sig = NULL;
    tamanio++;
    return new_nodo;
}

int isEmpty(nodo* top) {
    return top == NULL? TRUE:FALSE;
}

int size_stack(nodo* top) {
    return tamanio;
}

void push(stack top, int x) {
    nodo* new_nodo = crear_Nodo(x);
    if(isEmpty(*top)) {
        *top = new_nodo;
    } else {
        new_nodo->sig = *top;
        *top = new_nodo;
    }
}

int pop(stack top) {
    int x = -1;
    if(isEmpty(*top)){
        fprintf(stderr,"Stack is empty.\n");
    } else {
        nodo* aux = *top;
        x = aux->elem;
        *top = aux->sig;
        tamanio--;
        free(aux);
    }
    return x;
}

nodo* peek(nodo* top) {
    if(isEmpty(top)) {
        fprintf(stderr,"Stack is empty.\n");
        return NULL;
    } else {
        return top;
    }
}

void clear_stack(stack top) {
    nodo* aux = NULL;
    while(*top != NULL) {
        aux = *top;
        *top = aux->sig;
        free(aux);
        tamanio--;
    }
}

void print_stack(nodo* top) {
    printf("\n[");
    while(top != NULL) {
        printf("% d ",top->elem);
        top = top->sig;
    }
    printf("]\n");
}
