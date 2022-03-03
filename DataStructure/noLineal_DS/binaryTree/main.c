#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "binaryTree.h"

#define N 12

void clean_stdin(void);

int main()
{
    binaryTree bst = NULL;
    int read_succes;
    type_data x;

    for(int i = 0; i < N; i++) {
        while (1) {
            printf("Ingrese dato[%d]: ",i+1);
            read_succes = scanf("%d",&x);
            clean_stdin();
            if(read_succes == 1)
                break;
            else {
                fprintf(stderr,"No matching number. Try again, press any key to continue...");
            }
            getchar();
        }
        insert(&bst,x);
    }

    printf("\nIn-Order Traversal: ");
    inOrderTraversal(bst);
    printf("\nPre-Order Traversal: ");
    preOrderTraversal(bst);
    printf("\nPost-Order Traversal: ");
    postOrderTraversal(bst);
    printf("\nLevel Order Traversal: ");
    levelOrderTraversal(bst);

    if(isAtTree(bst,71))
        printf("\n%d encontrado en el arbol\n", search_node(bst,71)->x);
    if(isAtTree(bst,15))
        printf("\n%d encontrado en el arbol\n", search_node(bst,15)->x);
    else
        printf("\nno hubo coincidencia con el arbol\n");
    
    remove_node_at_Tree(&bst,65);
    remove_node_at_Tree(&bst,130);
    remove_node_at_Tree(&bst,120);
    remove_node_at_Tree(&bst,4);
    printf("\nIn-Order Traversal: ");
    inOrderTraversal(bst);
    printf("\nPre-Order Traversal: ");
    preOrderTraversal(bst);
    printf("\nPost-Order Traversal: ");
    postOrderTraversal(bst);
    printf("\nLevel Order Traversal: ");
    levelOrderTraversal(bst);
    printf("\n");

    return 0;
}

void clean_stdin() {
    int fdflags;
    fdflags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, fdflags | O_NONBLOCK);
    while (getchar()!=EOF);
    fcntl(STDIN_FILENO, F_SETFL, fdflags);
}