#include <stdio.h>
#include <stdlib.h>
#include "avlTree.h"

int isEmpty(avlTree root) {
    return root == NULL? TRUE:FALSE;
}

int isLeaf(avlTree root) {
    return (root->left == NULL) && (root->right == NULL)? TRUE:FALSE;
}

int isAtTree(avlTree root, type_data value) {
    return root == NULL? FALSE:root->x == value? TRUE:isAtTree(value < root->x? root->left:root->right,value);
}

nodo* crear_Nodo(type_data e) {
    nodo* new_nodo = (nodo*) malloc(sizeof(nodo));
    if(new_nodo == NULL) {
        fprintf(stderr,"Error. No se reservo espacio en memoria\n");
        exit(EXIT_FAILURE);
    }
    new_nodo->x = e;
    new_nodo->h = 1;
    new_nodo->right = new_nodo->left = NULL;

    return new_nodo;
}

int find_smallestDescendent(avlTree root) {
    if(root->right != NULL)
        return find_smallestDescendent(root->right);
    
    return root->x;
}

int height(avlTree root) {

    if(isEmpty(root))
        return 0;

    int hleft = height(root->left);
    int hright = height(root->right);
    
    return hleft > hright? hleft+1:hright+1;
}

int get_factorBalance(avlTree root) {
    if(isEmpty(root))
        return 0;

    return height(root->left) - height(root->right);
}

void leftRotate(avlTree* root) {
    avlTree aux = (*root)->right;
    (*root)->right = aux->left;
    aux->left = *root;
    *root = aux;
    (*root)->h = height(*root);
    (*root)->left->h = height((*root)->left);
}

void rightRotate(avlTree* root) {
    avlTree aux = (*root)->left;
    (*root)->left = aux->right;
    aux->right = *root;
    *root = aux;
    (*root)->h = height(*root);
    (*root)->right->h = height((*root)->right);
}

void insert(avlTree* root, type_data e) {
    
    if(isEmpty(*root))
        *root = crear_Nodo(e);
    else if((*root)->x == e)
        return;
    else
        insert(e < (*root)->x? &(*root)->left:&(*root)->right,e);
    
    //actualizamos la altura del ancestro del nodo
    (*root)->h = height(*root);
    //obtenemos el factor balance del ancestro
    int balance = get_factorBalance(*root);
    //Si el nodo no esta balanceado, tenemos 4 casos
    //left left case
    avlTree aux = *root;
    if((balance > 1) && (e < (*root)->left->x)) {
        rightRotate(&aux);
    }
    //left right case
    else if((balance > 1) && (e > (*root)->left->x)) {
        leftRotate((&aux->left));
        rightRotate(&aux);
    }
    //right right case
    else if((balance < -1) && (e > (*root)->right->x)) {
        leftRotate(&aux);
    }
    //right left case
    else if((balance < -1) && (e < (*root)->right->x)) {
        rightRotate(&aux->right);
        leftRotate(&aux);
    }
    (*root) = aux; 
}

void remove_dato_at_tree(avlTree* root, int value) {
    if(isEmpty(*root)) {
        fprintf(stderr,"Error. Tree is empty or element is not at Tree.\n");
        return;
    }
    
    if(value < (*root)->x)
        remove_dato_at_tree(&(*root)->left,value);
    else if(value > (*root)->x)
        remove_dato_at_tree(&(*root)->right,value);
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
            int n = find_smallestDescendent((*root)->left);
            (*root)->x = n;
            remove_dato_at_tree(&(*root)->left,n);
        }
    }

    if(isEmpty(*root))
        return;

    (*root)->h = height(*root);
    int balance = get_factorBalance(*root);

    //Si el nodo no esta balaneado se tiene 4 casos
    // left left case
    avlTree aux = *root;
    if((balance > 1) && (get_factorBalance((*root)->left) >= 0)) {
        rightRotate(&aux);
    }
    //left right case
    else if((balance > 1) && (get_factorBalance((*root)->left) < 0)) {
        leftRotate(&aux->left);
        rightRotate(&aux);
    }
    //right right case
    else if((balance < -1) && (get_factorBalance((*root)->right) <= 0)) {
        leftRotate(&aux);
    }
    //right left case
    else if((balance < -1) && (get_factorBalance((*root)->right) > 0)) {
        rightRotate(&aux->right);
        leftRotate(&aux);
    }
    *root = aux;
}

type_data search_dato_at_tree(avlTree root, type_data value) {
    //return isEmpty(root)? NULL:root->x == value? root:search_node(value < root->x? root->left:root->right,value);
    return isAtTree(root,value)? root->x == value? root->x:search_dato_at_tree(value < root->x? root->left:root->right,value):-1;
}

void print_dato(type_data e) {
    printf("%d ",e);
}

void inOrderTraversal(avlTree root) {
    if(!isEmpty(root)) {
        inOrderTraversal(root->left);
        print_dato(root->x);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(avlTree root) {
    if(!isEmpty(root)) {
        print_dato(root->x);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(avlTree root) {
    if(!isEmpty(root)) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        print_dato(root->x);
    }
}

void printGivenLevel(avlTree root, int level) {
    if(isEmpty(root))
        return;
    if(level == 0) {
        //printf("%d|",root->h);
        print_dato(root->x);
    } else if(level > 0){
        printGivenLevel(root->left,level-1);
        printGivenLevel(root->right,level-1);
    }
}

void levelOrderTraversal(avlTree root) {
    
    int h = height(root);
    for(int i = 0; i < h; ++i) {
        printGivenLevel(root,i);       
    }
}