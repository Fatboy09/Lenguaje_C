#ifndef PQUEUE_HEADER
#define PQUEUE_HEADER

typedef int elem;

typedef struct nodo {
    elem e;
    int priority;
    struct nodo* sig;
}nodo;

typedef struct queue {
    nodo* head;
    nodo* tail;
}queue;

void empty_queue(queue** q);
int is_emptyQueue(queue* q);
int size_queue(queue* q);
int queue_size(nodo* node);
void enqueue(queue** q, elem e, int priority);
void dequeue(queue** q);
nodo* peek(queue* q);
nodo* peek_tail(queue* q);
void print_queue(queue* q);
void clear_queue(queue** q);

#endif //PQUEUE_HEADER