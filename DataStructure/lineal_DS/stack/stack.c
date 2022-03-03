#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

nodo* crear_Nodo(type_data z) {
    nodo* new_nodo = (nodo*) malloc(sizeof(nodo));
    if(new_nodo == NULL) {
        fprintf(stderr,"Error. No se pudo reservar memoria.\n");
        exit(EXIT_FAILURE);
    }
    new_nodo->elem = z;
    new_nodo->sig = NULL;
    return new_nodo;
}

int isEmpty(stack top) {
    return top == NULL? TRUE:FALSE;
}

int size_stack(stack top) {
    int tam = 0;
    while(top != NULL) {
        ++tam;
        top = top->sig;
    }
    return tam;
}

void push(stack* top, type_data x) {
    nodo* new_nodo = crear_Nodo(x);
    if(isEmpty(*top)) {
        *top = new_nodo;
    } else {
        new_nodo->sig = *top;
        *top = new_nodo;
    }
}

type_data pop(stack* top) {
    type_data x = -1;
    if(isEmpty(*top)){
        fprintf(stderr,"Stack is empty.\n");
    } else {
        stack aux = *top;
        x = aux->elem;
        *top = aux->sig;
        free(aux);
    }
    return x;
}

nodo* peek(stack top) {
    if(isEmpty(top)) {
        fprintf(stderr,"Stack is empty.\n");
        return NULL;
    } else {
        return top;
    }
}

void clear_stack(stack* top) {
    
    while(*top != NULL) {
        pop(top);
    }
}

void print_dato(type_data x) {
    printf("%d ",x);
}

void print_stack(stack top) {
    printf("\n[ ");
    while(top != NULL) {
        print_dato(top->elem);
        top = top->sig;
    }
    printf("]\n");
}
