#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "heap.h"

#define TRUE 1
#define FALSE 0

void init_heap(heap* h, int capacity, Heap_type type) {
    h->size = 0;
    h->capacity = capacity;
    h->type = type;
    h->items = (data_type*) malloc(capacity*sizeof(data_type));
    if(h->items == NULL) {
        fprintf(stderr,"Error.No allocated memory");
        exit(EXIT_FAILURE);
    }
    //memset((*h)->items,0,capacity*sizeof(data_type));
}

int getLeftChildrenIndex(int i) { return 2 * i + 1; }
int getRightChildrenIndex(int i) { return 2 * i + 2; }
int getParentIndex(int i) { return (i - 1) / 2; }

int hasParent(int index) { return getParentIndex(index)>=0? TRUE:FALSE; }
int hasLeftChild(int index, int size) { return getLeftChildrenIndex(index) < size? TRUE:FALSE; }
int hasRightChild(int index, int size) { return getRightChildrenIndex(index) < size? TRUE:FALSE; }

data_type leftChild(heap h, int i) { return h.items[getLeftChildrenIndex(i)]; }
data_type rightChild(heap h, int i) { return h.items[getRightChildrenIndex(i)]; }
data_type parent(heap h, int i) { return h.items[getParentIndex(i)]; }

data_type peek(heap h) {
    
    if(h.size == 0) {
        fprintf(stderr,"Error. Heap is empty\n");
        return -1;
    }
    return h.items[0];
}

void swap(data_type* array, const int index_1, const int index_2) {
    int temp = array[index_1];
    array[index_1] = array[index_2];
    array[index_2] = temp;
}

void add_extraCapacity(heap* h) {
    int n = h->capacity + h->capacity;
    h->items = (data_type*) realloc(h->items,n * sizeof(data_type));
    if(h->items == NULL) {
        fprintf(stdout,"No add extra allocated memory\n");
    } else {
        h->capacity += h->capacity;
    }
}

void minHeapify(heap* h, int index) {
    int largest = index;
    int l = getLeftChildrenIndex(index);
    int r = getRightChildrenIndex(index);

    if(l < h->size && h->items[l] < h->items[largest])
        largest = l;
    if(r < h->size && h->items[r] < h->items[largest])
        largest = r;
    if(largest != index) {
        swap(h->items,largest,index);
        minHeapify(h,largest);
    }
}

void maxHeapify(heap* h, int index) {
    int largest = index;
    int l = getLeftChildrenIndex(index);
    int r = getRightChildrenIndex(index);

    if(l < h->size && h->items[l] > h->items[largest])
        largest = l;
    if(r < h->size && h->items[r] > h->items[largest])
        largest = r;
    if(largest != index) {
        swap(h->items,largest,index);
        maxHeapify(h,largest);
    }
}

void insert_key(heap* h, data_type k) {
    if(h->size == h->capacity)
        add_extraCapacity(h);
    h->size++;
    int i = h->size - 1;
    h->items[i] = k;

    while(i != 0 && h->items[getParentIndex(i)] > h->items[i]) {
        swap(h->items,i,getParentIndex(i));
        i = getParentIndex(i);
    }
}

void decrease_key(heap* h, int i, data_type new_key) {
    h->items[i] = new_key;
    while(i != 0 && h->items[getParentIndex(i)] > h->items[i]) {
        swap(h->items,getParentIndex(i),i);
        i = getParentIndex(i);
    }
}

data_type delete_key(heap* h, int index) {
    int k = h->items[index];
    decrease_key(h,index,INT_MIN);
    extract_root(h);
    return k;
}

data_type extract_root(heap* h) {
    if(h->size <= 0) {
        fprintf(stderr,"Error. Heap is empty\n");
        return INT_MAX;
    }

    if(h->size == 1) {
        h->size--;
        return h->items[0];
    }

    int root = h->items[0];
    h->items[0] = h->items[h->size - 1];
    h->size--;
    minHeapify(h,0);
    return root;
}/**/

void delete_heap(heap* h) {
    h->size = 0;
    h->capacity = 0;
    free(h->items);
    h->items = NULL;
}

void print_data(data_type x) {
    printf("%d ",x);
}

void print_heap(heap h) {
    
    printf("[ ");
    for(int i = 0; i < h.size; ++i) {
        print_data(h.items[i]);
    }
    printf("]\n");
}