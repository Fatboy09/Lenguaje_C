#ifndef AVLTREE_H
#define AVLTREE_H

#define TRUE 1
#define FALSE 0

typedef int type_data;

typedef struct NODO {
    type_data x;
    int h;
    struct NODO *right, *left;
} nodo;

typedef nodo* avlTree;

int isEmpty(avlTree);
int isLeaf(avlTree);
int isAtTree(avlTree,type_data);
void insert(avlTree*,type_data);
void remove_dato_at_tree(avlTree*, type_data);
type_data search_dato_at_tree(avlTree, type_data);
int height(avlTree);
void inOrderTraversal(avlTree);
void preOrderTraversal(avlTree);
void postOrderTraversal(avlTree);
void levelOrderTraversal(avlTree);


#endif //AVLTREE_H