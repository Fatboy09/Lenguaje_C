#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#define TRUE 1
#define FALSE 0

typedef struct NODO {
    int elem;
    struct NODO* sig;
}nodo;

typedef struct queue
{
    nodo *head;
    nodo *tail;
}queue;

typedef int type_data;

void empty(queue**);
int isEmpty_queue(queue*);
int size_queue(queue*);
void enqueue(queue**,type_data);
void dequeue(queue**);
nodo* peek(queue*);
void clear_queue(queue**);
void print_queue(queue*);

#endif // QUEUE_H_INCLUDED
