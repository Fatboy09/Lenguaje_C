#include <stdio.h>
#include <stdlib.h>
#include "treeAVL.h"

#define MAX(a,b) (a < b ? b : a) 

Nodo* empty()
{
	return NULL;
}

int isEmpty(Nodo* root)
{
	return root == NULL;
}

Nodo* newNodo(int elem)
{
	Nodo* nodo = NULL;

	nodo = (Nodo*) malloc(sizeof(Nodo));
	nodo->valor = elem;
	nodo->left = nodo->rigth = NULL;

	return nodo;
}

int factorBalance(Nodo* root)
{
	int h_right = height(root->rigth);
	int h_left = height(root->left);

	return h_left - h_right;
}
//insert(child->valor < (*root)->valor ? &(*root)->left : &(*root)->rigth, child);
void insert(Nodo** root, Nodo* child)
{
	if(isEmpty(*root))
		*root = child;
	
	else if(child->valor < (*root)->valor)
	{
		Nodo* temp = (*root);

		insert(&(temp)->left,child);
		if(factorBalance(temp) > 1)
		{
			if(factorBalance(temp->left) > 0)
				single_rotate_left(&temp);
			else
				double_rotate_with_left(&temp);
		}
		(*root) = temp;
	}
	else if(child->valor > (*root)->valor)
	{
		Nodo* temp = (*root);

		insert(&(temp)->rigth,child);
		if(factorBalance(temp) < -1)
		{
			if(factorBalance(temp->rigth) > 0)
				double_rotate_with_right(&temp);
			else
				single_rotate_right(&temp);
		}
		(*root) = temp;
	}
}

int findMin(Nodo* root)
{	
	if(root->left != NULL)
		return findMin(root->left);
	
	return root->valor;
}

void delete(Nodo** root, int dato)
{
	if(isEmpty(*root))
	{
		perror("El arbol esta vacio\n");
		return;
	}
	
	if (dato < (*root)->valor)
		delete(&(*root)->left, dato);
	else if (dato > (*root)->valor)
		delete(&(*root)->rigth,dato);
	else{
		//caso 1: no tiene hijo izquierdo ni derecho
		Nodo* aux = *root;
		if((*root)->left == NULL && (*root)->rigth == NULL)
		{
			free(aux);
			*root = NULL;
		}
		//caso 2: tiene un hijo (derecho)
		else if((*root)->rigth == NULL)
		{
			*root = (*root)->rigth;
			free(aux);
		}
		//caso 3: tiene un hijo (izquierdo)
		else if((*root)->rigth == NULL)
		{
			*root = (*root)->left;
			free(aux);
		}
		//caso 4: tiene dos hijos
		else
		{
			int data = findMin((*root)->rigth);
			(*root)->valor = data;
			delete(&(*root)->rigth,data);
		}
	}
}

void inOrden(Nodo* root)
{
	if(root != NULL)
	{
		inOrden(root->left);
		printf("%d ", root->valor);
		inOrden(root->rigth);
	}
}

void preOrden(Nodo* root)
{
	if(root != NULL)
	{
		printf("%d ", root->valor);
		preOrden(root->left);
		preOrden(root->rigth);
	}
}

void postOrden(Nodo* root)
{
	if(root != NULL)
	{
		postOrden(root->left);
		postOrden(root->rigth);
		printf("%d ", root->valor);
	}
}

void single_rotate_left(Nodo** root)
{
	Nodo* aux =  NULL;
	aux = (*root)->left;

	(*root)->left = aux->rigth;
	aux->rigth = (*root);
	(*root) = aux;
}

void single_rotate_right(Nodo** root)
{
	Nodo* aux =  NULL;
	aux = (*root)->rigth;

	(*root)->rigth = aux->left;
	aux->left = (*root);
	(*root) = aux;
}

void double_rotate_with_left(Nodo** root)
{
	Nodo* aux = (*root);
	single_rotate_right(&(aux)->left);
	single_rotate_left(&aux);
	*(root) = aux;
}

void double_rotate_with_right(Nodo** root)
{
	Nodo* aux = (*root);
	single_rotate_left(&(aux)->rigth);
	single_rotate_right(&aux);
	*(root) = aux;
}

Nodo* search(Nodo* root, int value)
{
	return isEmpty(root) ? NULL : root->valor == value ? root : search(value > root->valor ? root->rigth : root->left, value);
}

int height(Nodo* root)
{
	if(isEmpty(root))
		return 0;
	else
	{
		int hLeftt = height(root->left);
		int hRigth = height(root->rigth);

		return 1 + MAX(hLeftt,hRigth);	
	}
}