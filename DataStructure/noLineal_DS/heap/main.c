#include <stdio.h>
#include "heap.h"

int main(int argc, char const *argv[]) {
    
    heap h,h2;
    /*Min-heap*/
    init_heap(&h,10,MIN_HEAP);
    printf("root: %d\n",peek(h));
    printf("%d\n",extract_root(&h));
    print_heap(h);
    printf("size: %d\n",h.size);
    insert_key(&h,3);
    insert_key(&h,2);
    insert_key(&h,1);
    insert_key(&h,15);
    insert_key(&h,5);
    insert_key(&h,4);
    insert_key(&h,45);
    print_heap(h);
    printf("root: %d\n",peek(h));
    printf("size: %d\n",h.size);
    printf("capacity: %d\n", h.capacity);
    printf("type: %s\n", h.name_typeHeap);
    printf("key eliminated: %d\n",delete_key(&h,1));
    print_heap(h);
    printf("root: %d\n",peek(h));
    printf("size: %d\n",h.size);
    printf("capacity: %d\n", h.capacity);
    printf("type: %s\n", h.name_typeHeap);
    extract_root(&h);
    decrease_key(&h,getLeftChildrenIndex(0),leftChild(h,0)-2);
    print_heap(h);
    printf("root: %d\n",peek(h));
    printf("size: %d\n",h.size);
    printf("capacity: %d\n", h.capacity);
    printf("type: %s\n\n", h.name_typeHeap);
    /*Max-heap*/
    init_heap(&h2,10,MAX_HEAP);
    printf("root: %d\n",peek(h2));
    printf("%d\n",extract_root(&h2));
    print_heap(h2);
    printf("size: %d\n",h2.size);
    insert_key(&h2,3);
    insert_key(&h2,2);
    insert_key(&h2,1);
    insert_key(&h2,15);
    insert_key(&h2,5);
    insert_key(&h2,4);
    insert_key(&h2,45);
    print_heap(h2);
    printf("root: %d\n",peek(h2));
    printf("size: %d\n",h2.size);
    printf("capacity: %d\n", h2.capacity);
    printf("type: %s\n", h2.name_typeHeap);
    printf("key eliminated: %d\n",delete_key(&h2,1));
    print_heap(h2);
    printf("root: %d\n",peek(h2));
    printf("size: %d\n",h2.size);
    printf("capacity: %d\n", h2.capacity);
    printf("type: %s\n", h2.name_typeHeap);
    extract_root(&h2);
    increment_key(&h2,getLeftChildrenIndex(0),leftChild(h,0)+2);
    print_heap(h2);
    printf("root: %d\n",peek(h2));
    printf("size: %d\n",h2.size);
    printf("capacity: %d\n", h2.capacity);
    printf("type: %s\n", h2.name_typeHeap);

    delete_heap(&h);
    delete_heap(&h2);
    return 0;
}
