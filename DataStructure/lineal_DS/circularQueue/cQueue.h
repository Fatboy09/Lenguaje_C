#ifndef CQUEUE_H
#define CQUEUE_H

typedef int elem;

typedef struct nodo {
    elem e;
    struct nodo* sig;
}nodo;

typedef struct queueC{
    nodo* head;
    nodo* tail;
}queueC;

void empty_Cqueue(queueC** q);
int is_emptyCqueue(queueC* q);
int size_Cqueue(nodo* list,queueC* q);
void enqueueCQ(queueC** q, elem e);
void dequeueCQ(queueC** q);
void clear_Cqueue(queueC** q);
void print_Cqueue(queueC* q);
void print_CqueueRef(queueC* q,nodo* list);
nodo* peek_Cqueue(queueC* q);

#endif //CQUEUE_H