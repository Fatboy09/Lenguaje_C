#include <stdio.h>
#include <stdlib.h>
#include "listDE.h"

#define N 10

int main()
{
    lista lst = NULL;
    remove_nodo(&lst);
    remove_last_nodo(&lst);
    printf("lista[10]: %d\n",get_element_at(lst,10));
    for(int i = 0; i < N; ++i) {
        insert_nodo(&lst,i+1);
    }
    print_list(lst);
    printf("size List: %d\n",size_list(lst));
    print_listReference(lst);
    insert_nodo_at(&lst,3,11);
    insert_nodo_at(&lst,0,12);
    print_list(lst);
    printf("size List: %d\n",size_list(lst));
    print_listReference(lst);
    insert_nodo_at(&lst,5,20);
    insert_nodo_at(&lst,-1,20);
    insert_nodo_at(&lst,13,20);
    insert_at_begin(&lst,25);
    insert_nodo_at(&lst,size_list(lst),34);
    insert_nodo_at(&lst,size_list(lst)-1,34);
    print_list(lst);
    print_listReference(lst);
    printf("------------------------------\n");
    remove_nodo(&lst);
    remove_last_nodo(&lst);
    print_list(lst);
    printf("size List: %d\n",size_list(lst));
    print_listReference(lst);
    remove_at(&lst,5);
    remove_at(&lst,-1);
    remove_at(&lst,size_list(lst));
    remove_at(&lst,0);
    remove_at(&lst,size_list(lst)-1);
    remove_at(&lst,3);
    print_list(lst);
    print_listReference(lst);
    printf("lista[0]: %d\n",get_element_at(lst,0));
    printf("lista[8]: %d\n",get_element_at(lst,8));
    printf("lista[4]: %d\n",get_element_at(lst,4));
    printf("lista[-1]: %d\n",get_element_at(lst,-1));
    printf("lista[10]: %d\n",get_element_at(lst,10));
    printf("bool: %d\n",find_elem(lst,6));
    printf("bool: %d\n",find_elem(lst,1));
    printf("bool: %d\n",find_elem(lst,9));
    printf("bool: %d\n",find_elem(lst,40));
    clear_list(&lst);
    print_list(lst);
    print_listReference(lst);
    printf("size List: %d\n",size_list(lst));/**/

    return 0;
}
