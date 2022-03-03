#ifndef AVLTREE_H
#define AVLTREE_H

typedef struct Nodo{
	int valor;
	struct Nodo* left;
	struct Nodo* rigth;
}Nodo;

//Prototipos de funcion para las operaciones de la estructura de Datos lista
Nodo* empty();
int isEmpty(Nodo* root);
Nodo* newNodo(int elem);
void insert(Nodo** root, Nodo* newNodo);
void delete(Nodo** root, int dato);
void inOrden(Nodo* root);
void preOrden(Nodo* root);
void postOrden(Nodo* root);
void single_rotate_left(Nodo** root);
void single_rotate_right(Nodo** root);
void double_rotate_with_left(Nodo** root);
void double_rotate_with_right(Nodo** root);
Nodo* search(Nodo* root, int value);
int findMin(Nodo* root);
int height(Nodo* root);
int factorBalance(Nodo* root);
#endif	//AVLTREE_H
