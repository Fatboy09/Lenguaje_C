#ifndef MINHEAP_H
#define MINHEAP_H

#include <stdbool.h>

typedef struct MinHeapNode{
	unsigned v;
	size_t dist;
}MinHeapNode;

typedef struct MinHeap {
    int capacity;
    int size;
    unsigned *pos;
    MinHeapNode **array; 
} MinHeap;

typedef MinHeapNode* dataType_minHeap;

MinHeapNode* new_MinHeapNode(unsigned v, size_t dist);
MinHeap* new_MinHeap(int capacity);
void swapMinHeapNode(dataType_minHeap* a, dataType_minHeap* b);
void minHeapify(MinHeap* mh, unsigned index);
bool isEmpty_MinHeap(MinHeap* mh);
dataType_minHeap extractMin(MinHeap* mh);
dataType_minHeap peek_MinHeap(MinHeap* mh);
void decrease_key(MinHeap* mh, unsigned v, size_t dist);
bool isInMinHeap(MinHeap* mh, unsigned v);
void delete_MinHeap(MinHeap** mh);

unsigned getLeftChildrenIndex(unsigned parentIndex);
unsigned getRightChildrenIndex(unsigned parentIndex);
unsigned getParentIndex(unsigned childIndex);

dataType_minHeap leftChild(MinHeap* h, unsigned index);
dataType_minHeap rightChild(MinHeap* h, unsigned index);
dataType_minHeap parent(MinHeap* h, unsigned index);

#endif //MINHEAP_H
