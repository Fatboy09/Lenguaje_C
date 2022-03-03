#include <stdio.h>
#include <stdlib.h>
#include "treeAVL.h"

int main(int argc, char const *argv[])
{
	Nodo* root;
	root = empty(&root);
	Nodo* elem = NULL;
	int data;
	int flag = 1;

	printf("\nInsercion\n\n");

	while(flag)
	{
		printf("Teclee un numero entero positivo: ");
		scanf("%d", &data);
		if(data < 0)
			flag = 0;
		else
			insert(&root, newNodo(data));
	}
	
	printf("\n");

	printf("InOrden (IRD): ");
	inOrden(root);
	printf("\n");

	printf("PostOrden (IDR): ");
	postOrden(root);
	printf("\n");

	printf("PreOrden (RID): ");
	preOrden(root);

	printf("\nAltura: %d", height(root));

	printf("\n\nBusqueda\n\n");

	flag = 1;

	while(flag)
	{
		printf("Teclee un numero entero positivo: ");
		scanf("%d", &data);
		if(data < 0)
			flag = 0;
		else
		{
			elem = search(root,data);
			if (elem != NULL) 
				printf("Elemento encontrado en el arbol\n\n");
			else
				printf("No existe el elemento en el arbol\n\n");
		}
	}

	/*printf("\nEliminacion\n\n");

	flag = 1;

	while(flag)
	{
		printf("Teclee un numero entero positivo: ");
		scanf("%d", &data);
		if(data < 0)
			flag = 0;
		else
		{
			elem = search(root,data);
			if (elem != NULL) 
				delete(&root,data);
			else
				printf("No existe el elemento en el arbol\n\n");
		}
	}

	printf("\n");

	printf("InOrden (IRD): ");
	inOrden(root);
	printf("\n");

	printf("PostOrden (IDR): ");
	postOrden(root);
	printf("\n");

	printf("PreOrden (RID): ");
	preOrden(root);
	printf("\nAltura: %d\n", height(root));*/

	free(root);
	return 0;
}