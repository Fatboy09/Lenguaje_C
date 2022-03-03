#include <stdio.h>
#include <stdlib.h>
#include "queueC.h"

int main(int argc, char const *argv[])
{
	Nodo* q;
	q = empty(&q);
	register int i;

	printQueue(q);
	printf("size's list: %d\n", length(q));
	enqueue(&q,100);
	printQueue(q);
	printf("size's list: %d\n", length(q));

	for(i = 0; i <= 10; i++)
	{
		enqueue(&q,i);
	}
	printQueue(q);
	printf("size's list: %d\n", length(q));
	for(i = 0; i < 5; i++)
	{
		printf("%d\n",dequeue(&q));
	}
	printQueue(q);
	printf("size's list: %d\n", length(q));
	delete(q);
	q = NULL;
	printQueue(q);
	printf("size's list: %d\n", length(q));
	free(q);
	return 0;
}