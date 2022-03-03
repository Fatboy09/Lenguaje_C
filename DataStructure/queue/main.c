#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int main(int argc, char const *argv[])
{
	queue *cola;
	empty(&cola);
	int i;

	printQueue(cola);
	printf("size's queue: %d\n", length(cola));


	enqueue(&cola,-1);
	printQueue(cola);
	printf("size's queue: %d\n", length(cola));

	for(i = 0; i <= 10; i++)
	{
		enqueue(&cola,i);
	}
	printQueue(cola);
	printf("size's queue: %d\n", length(cola));

	for(i = 0; i < 5; i++)
	{
		dequeue(&cola);
	}
	printQueue(cola);
	printf("size's queue: %d\n", length(cola));

	printf("The front's queue is %d\n", front(cola));

	delete(&cola);
	printQueue(cola);
	printf("size's queue: %d\n", length(cola));
	cola = NULL;
	free(cola);
	return 0;
}