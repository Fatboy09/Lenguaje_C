#include <stdio.h>
#include "cQueue.h"

int main() {

    queueC* q;
    empty_Cqueue(&q);
    print_Cqueue(q);
    printf("\nsize: %d\n",size_Cqueue(q->head,q));
    for(int i = 0; i < 5; ++i) {
        enqueueCQ(&q,i);
    }
    print_Cqueue(q);
    printf("\nsize: %d\n",size_Cqueue(q->head,q));
    printf("peek: %d\n",peek_Cqueue(q)->e);
    print_CqueueRef(q,q->head);

    dequeueCQ(&q);
    print_Cqueue(q);
    printf("\nsize: %d\n",size_Cqueue(q->head,q));
    printf("peek: %d\n",peek_Cqueue(q)->e);
    print_CqueueRef(q,q->head);

    clear_Cqueue(&q);
    print_Cqueue(q);
    printf("\nsize: %d\n",size_Cqueue(q->head,q));
    print_CqueueRef(q,q->head);
    printf("\n");

    return 0;
}