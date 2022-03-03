#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

#define TRUE 1
#define FALSE 0

int find_smallestDescendent(binaryTree root) {
    if(root->left != NULL)
        return find_smallestDescendent(root->left);
    
    return root->x;
}

int isEmpty(binaryTree root) {
    return root == NULL? TRUE:FALSE;
}

int isLeaf(binaryTree root) {
    return ((root->left == NULL) && (root->right == NULL))? TRUE:FALSE;
}

int isAtTree(binaryTree root, int value) {
    return root == NULL? FALSE:root->x == value? TRUE:isAtTree(value < root->x? root->left:root->right,value);
}

nodo* search_node(binaryTree root, int value) {
    //return isEmpty(root)? NULL:root->x == value? root:search_node(value < root->x? root->left:root->right,value);
    return isAtTree(root,value)? root->x == value? root:search_node(value < root->x? root->left:root->right,value):NULL;
}

nodo* crear_nodo(type_data value) {
    nodo* new_nodo = (nodo*) malloc(sizeof(nodo));
    if(new_nodo == NULL) {
        perror("No se reservo espacio en memoria para crear el nuevo nodo\n");
        return NULL;
    }
    new_nodo->x = value;
    new_nodo->left = new_nodo->right = NULL;

    return new_nodo;
}

void insert(binaryTree* root, type_data e) {

    if(isEmpty(*root)) {
        *root = crear_nodo(e);
    }
    else if(e == (*root)->x) {
        return;
    }
    else {
        insert((e < (*root)->x)? &(*root)->left:&(*root)->right,e);
    }
}

void remove_node_at_Tree(binaryTree* root, int value) {
    if(isEmpty(*root)) {
        fprintf(stderr,"Error. Tree is empty or element is not at Tree.\n");
        return;
    }
    
    if(value < (*root)->x)
        remove_node_at_Tree(&(*root)->left,value);
    else if(value > (*root)->x)
        remove_node_at_Tree(&(*root)->right,value);
    else {
        nodo* aux = *root;
        /*1er caso, el nodo es una hoja*/
        if(isLeaf(*root)) {
            //free(aux);
            (*root) = NULL;
            free(aux);
        }
        /*2do caso, el nodo tiene solo un hijo [izquierdo]*/
        else if(((*root)->right == NULL) && ((*root)->left) != NULL) {
            *root = aux->left;
            free(aux); 
        }
        /*3er caso, el nodo tiene solo un hijo [derecho]*/
        else if(((*root)->left == NULL) && ((*root)->right != NULL)) {
            *root = aux->right;
            free(aux);
        }
        /*4to caso, el nodo tiene dos hijos*/
        else {
            int n = find_smallestDescendent((*root)->right);
            (*root)->x = n;
            remove_node_at_Tree(&(*root)->right,n);
        }
    } 
}

int height(binaryTree root) {

    if(root == NULL)
        return 0;
    
    int l_height = height(root->left);
    int r_height = height(root->right);

    return l_height > r_height? l_height+1:r_height+1;

}

void print_root(type_data x) {
    printf("%d ", x);
}

void inOrderTraversal(binaryTree root) {
    if(root != NULL) {
        inOrderTraversal(root->left);
        print_root(root->x);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(binaryTree root) {
    if(root != NULL) {
        print_root(root->x);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(binaryTree root) {
    if(root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        print_root(root->x);
    }
}

void printGivenLevel(binaryTree root, int level) {
    if(root == NULL)
        return;
    if(level == 0)
        print_root(root->x);
    else if(level > 0) {
        printGivenLevel(root->left,level-1);
        printGivenLevel(root->right,level-1);
    } 
}

void levelOrderTraversal(binaryTree root) {
    int h = height(root);
    int i;
    
    for(i = 1; i <= h; i++)
        printGivenLevel(root,i-1);
}
