#ifndef HEAP_H
#define HEAP_H

typedef enum Heap_type{MIN_HEAP,MAX_HEAP} Heap_type;
typedef int data_type;

typedef struct heap {
    int capacity;
    int size;
    char name_typeHeap[9];
    data_type* items;
    Heap_type type;
} heap;

void init_heap(heap* h, int capacity, Heap_type type);
void insert_key(heap* h, data_type k);
data_type delete_key(heap* h, int index);
data_type extract_root(heap* h);
data_type peek(heap h);
void decrease_key(heap* h, int i, data_type new_key);
void increment_key(heap* h, int i, data_type new_key);
void delete_heap(heap* h);

int getLeftChildrenIndex(int parentIndex);
int getRightChildrenIndex(int parentIndex);
int getParentIndex(int childIndex);

data_type leftChild(heap h, int index);
data_type rightChild(heap h, int index);
data_type parent(heap h, int index);/**/

void print_heap(heap h);

#endif //HEAP_H