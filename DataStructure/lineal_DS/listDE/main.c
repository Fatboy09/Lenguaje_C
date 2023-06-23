#include <stdio.h>
#include "listDE.h"

#define N 10

int main()
{
    lista lst = NULL;
    
    doubleLinkedList_remove_node(&lst);
    doubleLinkedList_remove_last_node(&lst);
    printf("lista[10]: %d\n",doubleLinkedList_get_element_at(lst,10));
    
    for(int i = 0; i < N; ++i) {
        doubleLinkedList_insert_node(&lst, i + 1);
    }
    
    print_doubleLinkedList(lst);
    printf("size List: %d\n",size_doubleLinkedList(lst));
    print_doubleLinkedListReference(lst);
    
    doubleLinkedList_insert_node_at(&lst,3,11);
    doubleLinkedList_insert_node_at(&lst,0,12);
    
    print_doubleLinkedList(lst);
    printf("size List: %d\n",size_doubleLinkedList(lst));
    print_doubleLinkedListReference(lst);
    
    doubleLinkedList_insert_node_at(&lst,5,20);
    doubleLinkedList_insert_node_at(&lst,-1,20);
    doubleLinkedList_insert_node_at(&lst,13,20);
    doubleLinkedList_insert_at_begin(&lst,25);
    doubleLinkedList_insert_node_at(&lst,size_doubleLinkedList(lst),34);
    doubleLinkedList_insert_node_at(&lst,size_doubleLinkedList(lst)-1,34);
    
    print_doubleLinkedList(lst);
    print_doubleLinkedListReference(lst);
    printf("------------------------------\n");
    
    doubleLinkedList_remove_node(&lst);
    doubleLinkedList_remove_last_node(&lst);
    
    print_doubleLinkedList(lst);
    printf("size List: %d\n",size_doubleLinkedList(lst));
    print_doubleLinkedListReference(lst);
    
    doubleLinkedList_remove_node_at(&lst,5);
    doubleLinkedList_remove_node_at(&lst,-1);
    doubleLinkedList_remove_node_at(&lst,size_doubleLinkedList(lst));
    doubleLinkedList_remove_node_at(&lst,0);
    doubleLinkedList_remove_node_at(&lst,size_doubleLinkedList(lst)-1);
    doubleLinkedList_remove_node_at(&lst,3);
    print_doubleLinkedList(lst);
    print_doubleLinkedListReference(lst);
    printf("lista[0]: %d\n",doubleLinkedList_get_element_at(lst,0));
    printf("lista[8]: %d\n",doubleLinkedList_get_element_at(lst,8));
    printf("lista[4]: %d\n",doubleLinkedList_get_element_at(lst,4));
    printf("lista[-1]: %d\n",doubleLinkedList_get_element_at(lst,-1));
    printf("lista[10]: %d\n",doubleLinkedList_get_element_at(lst,10));
    printf("bool: %d\n",doubleLinkedList_is_elem_at_list(lst,6));
    printf("bool: %d\n",doubleLinkedList_is_elem_at_list(lst,1));
    printf("bool: %d\n",doubleLinkedList_is_elem_at_list(lst,9));
    printf("bool: %d\n",doubleLinkedList_is_elem_at_list(lst,40));
    doubleLinkedList_clear_list(&lst);
    print_doubleLinkedList(lst);
    print_doubleLinkedListReference(lst);
    printf("size List: %d\n",size_doubleLinkedList(lst));/**/

    return 0;
}
