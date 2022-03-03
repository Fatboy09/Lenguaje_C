#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void empty(queue** q)
{
	(*q)->head = (*q)->tail = NULL;
	(*q)->size = 0;
}

int isEmpty(queue* q)
{
	return (q->head == NULL && q->tail == NULL);
}

void enqueue(queue** q, int elem)
{
	(*q)->size++;
	if (isEmpty(*q))
	{
		(*q)->head = (Nodo*) malloc(sizeof(struct Nodo));
		if ((*q)->head == NULL)
		{
			perror("--Error-- It can't reserve memory\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			(*q)->head->valor = elem;
			(*q)->head->sig = NULL;
			(*q)->tail = (*q)->head;
		}
	}
	else
	{
		(*q)->tail->sig = (Nodo *) malloc(sizeof(struct Nodo));
		(*q)->tail->sig->valor = elem;
		(*q)->tail->sig->sig = NULL;
		(*q)->tail = (*q)->tail->sig;
	}
}

void delete(queue** q)
{
	while((*q)->head != NULL)
	{	
		(*q)->size--;
		Nodo* p = (*q)->head;
		(*q)->head = (*q)->head->sig;
		free(p);
	}
	(*q)->head = (*q)->tail = NULL;
}

void dequeue(queue** q)
{
	(*q)->size--;
	Nodo* p = (*q)->head;
	(*q)->head = (*q)->head->sig;
	free(p);
}

int front(queue* q)
{
	return q->head->valor;
}

int length(queue* q)
{
	return q->size;
}

void printQueue(queue* q)
{
	queue* aux = q;
	Nodo* first = NULL;
	if(isEmpty(aux))
		printf("[ ]\n");
	else
	{
		first = q->head;
		printf("[ ");
		while(aux->head != NULL)
		{
			printf("%d ", aux->head->valor);
			aux->head = aux->head->sig;
		}
		printf("]\n");
		aux->head = first;
	}
}