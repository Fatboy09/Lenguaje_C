#include <stdio.h>
#include "list.h"

#define N 10

int main()
{
    lista lst = NULL;
    
    linkedList_remove_node(&lst);
    linkedList_remove_last_node(&lst);
    
    printf("lista[10]: %d\n",linkedList_get_element_at(lst,10));
    
    for(int i = 0; i < N; ++i) {
        linkedList_insert_node(&lst,i+1);
    }
    
    print_linkedList(lst);
    printf("size List: %d\n",size_list(lst));
    
    linkedList_insert_node_at(&lst,3,11);
    linkedList_insert_node_at(&lst,0,12);
    
    print_linkedList(lst);
    printf("size List: %d\n",size_list(lst));
    
    linkedList_insert_node_at(&lst,5,20);
    
    print_linkedList(lst);
    printf("size List: %d\n",size_list(lst));
    
    linkedList_insert_node_at(&lst,-1,20);
    linkedList_insert_node_at(&lst,13,20);
    linkedList_insert_at_begin(&lst,25);
    linkedList_insert_node_at(&lst,size_list(lst),34);
    linkedList_insert_node_at(&lst,size_list(lst)-1,34);
    print_linkedList(lst);
    linkedList_remove_node(&lst);
    print_linkedList(lst);
    linkedList_remove_last_node(&lst);
    print_linkedList(lst);
    
    printf("size List: %d\n",size_list(lst));
    
    linkedList_remove_node_at(&lst,5);
    print_linkedList(lst);
    linkedList_remove_node_at(&lst,-1);
    linkedList_remove_node_at(&lst,size_list(lst));
    linkedList_remove_node_at(&lst,0);
    linkedList_remove_node_at(&lst,size_list(lst)-1);
    linkedList_remove_node_at(&lst,3);
    print_linkedList(lst);
    
    printf("lista[0]: %d\n",linkedList_get_element_at(lst,0));
    printf("lista[8]: %d\n",linkedList_get_element_at(lst,8));
    printf("lista[4]: %d\n",linkedList_get_element_at(lst,4));
    printf("lista[-1]: %d\n",linkedList_get_element_at(lst,-1));
    printf("lista[10]: %d\n",linkedList_get_element_at(lst,10));
    printf("bool: %d\n",is_element_at_linkedList(lst,6));
    printf("bool: %d\n",is_element_at_linkedList(lst,1));
    printf("bool: %d\n",is_element_at_linkedList(lst,9));
    printf("bool: %d\n",is_element_at_linkedList(lst,40));
    
    return 0;
}
