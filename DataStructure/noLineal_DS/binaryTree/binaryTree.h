#ifndef BINARYTREE_H
#define BINARYTREE_H

typedef int type_data;

typedef struct NODO
{
    type_data x;
    struct NODO* left;
    struct NODO* right;
}nodo;

typedef nodo* binaryTree;

nodo* crear_nodo(type_data);
int isEmpty(binaryTree);
int isLeaf(binaryTree);
int isAtTree(binaryTree, type_data);
int height(binaryTree);
void insert(binaryTree*, type_data);
void remove_node_at_Tree(binaryTree*, type_data);
nodo* search_node(binaryTree, type_data);
void inOrderTraversal(binaryTree);
void postOrderTraversal(binaryTree);
void preOrderTraversal(binaryTree);
void levelOrderTraversal(binaryTree);

#endif //BINARYTREE