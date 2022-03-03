#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define TRUE 1
#define FALSE 0

typedef struct NODO {
    int elem;
    struct NODO* sig;
} nodo;

typedef int type_data;
typedef nodo* stack;

//prototipos de las funciones de las operaciones
int isEmpty(stack);
int size_stack(stack);
void push(stack*, type_data);
type_data pop(stack*);
nodo* peek(stack);
void clear_stack(stack*);
void print_stack(stack);

#endif // STACK_H_INCLUDED
