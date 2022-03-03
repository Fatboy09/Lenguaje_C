#include <stdio.h>
#include "pQueue.h"

int main() {
    queue* queue_priority;
    empty_queue(&queue_priority);

    for(int i = 0; i < 5; ++i) {
        enqueue(&queue_priority,i+2,i);
    }

    print_queue(queue_priority);
    //printf("\nsize: %d\n",size_queue(queue_priority));
    printf("\nsize: %d\n",queue_size(queue_priority->head));
    printf("head: %d\n", peek(queue_priority)->e);
    printf("tail: %d\n", peek_tail(queue_priority)->e);
    dequeue(&queue_priority);
    print_queue(queue_priority);
    //printf("\nsize: %d\n",size_queue(queue_priority));
    printf("\nsize: %d\n",queue_size(queue_priority->head));
    printf("head: %d\n", peek(queue_priority)->e);

    enqueue(&queue_priority,100,0);
    enqueue(&queue_priority,150,3);
    enqueue(&queue_priority,160,8);
    enqueue(&queue_priority,170,4);
    enqueue(&queue_priority,35,0);
    print_queue(queue_priority);
    //printf("\nsize: %d\n",size_queue(queue_priority));
    printf("\nsize: %d\n",queue_size(queue_priority->head));
    printf("head: %d\n", peek(queue_priority)->e);
    printf("tail: %d\n", peek_tail(queue_priority)->e);
    clear_queue(&queue_priority);
    print_queue(queue_priority);
    printf("\nsize: %d\n",queue_size(queue_priority->head));

    printf("\n");
    return 0;
}