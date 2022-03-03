#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define N 10

int main()
{
    nodo* pila = NULL;
    for(int i = 0; i < N; i++) {
        push(&pila,i+1);
    }
    print_stack(pila);
    printf("stack size: %d\n",size_stack(pila));

    printf("Se elimino el elemento: %d\n",pop(&pila));
    print_stack(pila);
    printf("stack size: %d\n",size_stack(pila));
    printf("Top stack is: %d\n", peek(pila)->elem);
    clear_stack(&pila);
    print_stack(pila);
    printf("stack size: %d\n", size_stack(pila));

    return 0;
}
