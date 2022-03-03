#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#define TRUE 1
#define FALSE 0

typedef struct NODO {
    int elem;
    struct NODO* sig;
}nodo;

typedef nodo* queue;

int isEmpty_queue();
int size_queue();
void enqueue(int);
int dequeue();
nodo* peek();
void clear_queue();
void print_queue();

#endif // QUEUE_H_INCLUDED
