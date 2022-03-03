#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#define TRUE 1
#define FALSE 0

typedef struct NODO_Q {
    unsigned elem;
    struct NODO_Q* sig;
}nodoQ;

typedef struct queue
{
    nodoQ *head;
    nodoQ *tail;
}queue;

typedef unsigned type_data;

queue* newQueue();
int isEmpty_queue(queue*);
int size_queue(queue*);
void enqueue(queue**,type_data);
void dequeue(queue**);
type_data peek(queue*);
void clear_queue(queue**);
void print_queue(queue*);
void destroy_queue(queue**);

#endif // QUEUE_H_INCLUDED
