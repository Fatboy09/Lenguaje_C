#ifndef QUEUEC_H
#define QUEUEC_H

typedef struct Nodo{
	int valor;
	struct Nodo* sig;
}Nodo;

//Prototipos de funcion para las operaciones de la estructura de Datos lista
Nodo* empty();
int isEmpty(Nodo* head);
void enqueue(Nodo** head, int elem);
int dequeue(Nodo** head);
void delete(Nodo* head);
Nodo* front(Nodo* head);
void printQueue(Nodo* head);
int length(Nodo* head);

#endif	//QUEUEC
