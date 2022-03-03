#include <stdio.h>
#include <stdlib.h>
#include "queueC.h"

Nodo* empty()
{
	return NULL;
}

int isEmpty(Nodo* head)
{
	return head == NULL;
}

void enqueue(Nodo** head, int elem)
{
	Nodo* newNodo = (Nodo*) malloc(sizeof(Nodo));
	if (newNodo == NULL)
	{
		perror("--Error-- It can't reserve memory\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		newNodo->valor = elem;
		if(*head == NULL)
		{
			newNodo->sig = newNodo;
		}
		else
		{
			newNodo->sig = (*head)->sig;
			(*head)->sig = newNodo;
		}
		*head = newNodo;
	}
}

int dequeue(Nodo** head)
{
	int elem = (*head)->sig->valor;
	if (*head == (*head)->sig)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		Nodo* aux = (*head)->sig;
		(*head)->sig = aux->sig;
		free(aux);
	}
	return elem;
}

void delete(Nodo* head)
{
	while(head != NULL)
	{	
		printf("%d\n",dequeue(&head));
	}
}

Nodo* front(Nodo* head)
{
	Nodo* aux = head->sig;
	return aux;
}

int length(Nodo* head)
{
	int i = 0;
	if(head != NULL)
	{
		Nodo* aux = head->sig;
		while(aux != head)
		{
			i++;
			aux = aux->sig;
		}
		i++;
	}
	return i;	
}

void printQueue(Nodo* head)
{
	if(isEmpty(head))
		printf("[ ]\n");
	else
	{
		Nodo* aux = head->sig;
		printf("[");
		while(aux != head)
		{
			printf("%d, ", aux->valor);
			aux = aux->sig;
		}
		printf("%d]\n", aux->valor);
	}
}