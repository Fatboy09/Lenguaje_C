#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define N 10

int main()
{

    queue* q;
    empty(&q);
    for(int i = 0; i < N; i++) {
        enqueue(&q,i+1);
    }

    print_queue(q);
    printf("size queue: %d\n", size_queue(q));
    printf("El primer elemento en la cola es: %d\n",peek(q)->elem);
    dequeue(&q);
    dequeue(&q);
    print_queue(q);
    printf("size queue: %d\n", size_queue(q));
    printf("El primer elemento en la cola es: %d\n",peek(q)->elem);
    clear_queue(&q);
    print_queue(q);
    printf("size queue: %d\n", size_queue(q));/**/

    return 0;
}
