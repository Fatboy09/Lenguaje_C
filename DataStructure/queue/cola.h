#ifndef COLA_H
#define COLA_H

typedef struct Nodo{
	int valor;
	struct Nodo* sig;
}Nodo;

typedef struct queue
{
	int size;
	struct Nodo *head;
	struct Nodo *tail;
}queue;

//Prototipos de funcion para las operaciones de la estructura de Datos lista
void empty(queue** q);
int isEmpty(queue* q);
void enqueue(queue** q, int elem);
void delete(queue** q);
void dequeue(queue** q);
int front(queue* q);
void printQueue(queue* q);
int length(queue* q);

#endif	//COLA_H
