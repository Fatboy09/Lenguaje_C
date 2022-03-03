#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "avlTree.h"

#define N 12

void clean_stdin(void);

int main(int argc, char const *argv[])
{
    avlTree t = NULL;
    type_data datos[] = {100,50,110,5,65,120,115,130,52,78,71,73};

    for(int i = 0; i < N; ++i) {
        insert(&t,datos[i]);
    }
    printf("In-Order Traversal:\n");
    inOrderTraversal(t);
    printf("\nPre-Order Traversal:\n");
    preOrderTraversal(t);
    printf("\nPost-Order Traversal:\n");
    postOrderTraversal(t);
    printf("\nLevel Order Traversal:\n");
    levelOrderTraversal(t);
    remove_dato_at_tree(&t,3);
    remove_dato_at_tree(&t,130);
    remove_dato_at_tree(&t,115);
    remove_dato_at_tree(&t,100);
    printf("\nIn-Order Traversal:\n");
    inOrderTraversal(t);
    printf("\nLevel Order Traversal:\n");
    levelOrderTraversal(t);
    if(isAtTree(t,73))
        printf("\ntrue:%d encontrado en el arbol.",search_dato_at_tree(t,73));
    if(!isAtTree(t,300))
        printf("\nfalse\n");

    return 0;
}

void clean_stdin() {
    int fdflags;
    fdflags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, fdflags | O_NONBLOCK);
    while (getchar()!=EOF);
    fcntl(STDIN_FILENO, F_SETFL, fdflags);
}
