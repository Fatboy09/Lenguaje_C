#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include "minHeap.h"

MinHeapNode* new_MinHeapNode(unsigned v, size_t dist) {
	MinHeapNode *minHeapNode = malloc(sizeof(MinHeapNode));
	assert(minHeapNode != NULL);
	minHeapNode->v = v;
	minHeapNode->dist = dist;
	return minHeapNode;
}

MinHeap* new_MinHeap(int capacity) {
    MinHeap *minHeap = malloc(sizeof(MinHeap));
    assert(minHeap != NULL);
    minHeap->pos = malloc(sizeof(unsigned) * (size_t)capacity);
    assert(minHeap->pos != NULL);
    minHeap->array = malloc(sizeof(MinHeapNode*) * (size_t)capacity);
    assert(minHeap->array != NULL);
    minHeap->size = 0;
    minHeap->capacity = capacity;
	return minHeap;
}

unsigned getLeftChildrenIndex(unsigned i) { return 2 * i + 1; }
unsigned getRightChildrenIndex(unsigned i) { return 2 * i + 2; }
unsigned getParentIndex(unsigned i) { return (i - 1) / 2; }

bool hasParent(unsigned index) { return index > 0? true:false; }
bool hasLeftChild(unsigned index, int size) { return getLeftChildrenIndex(index) < (unsigned)size? true:false; }
bool hasRightChild(unsigned index, int size) { return getRightChildrenIndex(index) < (unsigned)size? true:false; }

dataType_minHeap leftChild(MinHeap* h, unsigned i) { return h->array[getLeftChildrenIndex(i)]; }
dataType_minHeap rightChild(MinHeap* h, unsigned i) { return h->array[getRightChildrenIndex(i)]; }
dataType_minHeap parent(MinHeap* h, unsigned i) { return h->array[getParentIndex(i)]; }

dataType_minHeap peek_MinHeap(MinHeap* mh) {
    if(mh->size == 0) {
        fprintf(stderr,"Error. Heap is empty\n");
        return NULL;
    }
    return mh->array[0];
}

void swapMinHeapNode(dataType_minHeap* a, dataType_minHeap* b) {
    dataType_minHeap temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap* mh, unsigned index) {
    unsigned smallest = index;
    unsigned l = getLeftChildrenIndex(index);
    unsigned r = getRightChildrenIndex(index);

    if(l < (unsigned)mh->size && mh->array[l]->dist < mh->array[smallest]->dist)
        smallest = l;
    if(r < (unsigned)mh->size && mh->array[r]->dist < mh->array[smallest]->dist)
        smallest = r;
    if(smallest != index) {
		dataType_minHeap smallestNode = mh->array[smallest];
		dataType_minHeap idxNode = mh->array[index];
		mh->pos[smallestNode->v] = index;
		mh->pos[idxNode->v] = smallest;
        swapMinHeapNode(&mh->array[smallest],&mh->array[index]);
        minHeapify(mh,smallest);
    }
}

bool isEmpty_MinHeap(MinHeap* mh) { return mh->size == 0; }

void decrease_key(MinHeap* mh, unsigned v, size_t dist) {
    unsigned i = mh->pos[v];
    mh->array[i]->dist = dist;
    while(i != 0 && mh->array[getParentIndex(i)]->dist > mh->array[i]->dist) {
        mh->pos[mh->array[i]->v] = getParentIndex(i);
        mh->pos[mh->array[getParentIndex(i)]->v] = i;
        swapMinHeapNode(&mh->array[getParentIndex(i)],&mh->array[i]);
        i = getParentIndex(i);
    }
}

dataType_minHeap extractMin(MinHeap* mh) {
    if(isEmpty_MinHeap(mh))
        return NULL;
        
    dataType_minHeap root = mh->array[0];
    dataType_minHeap lastNode = mh->array[mh->size - 1];
    mh->array[0] = lastNode;
    mh->pos[root->v] = (unsigned)mh->size - 1;
    mh->pos[lastNode->v] = 0;
    --mh->size;
    minHeapify(mh,0);    
    return root;
}

bool isInMinHeap(MinHeap* mh, unsigned v) { return mh->pos[v] < (unsigned)mh->size? true:false; }

void delete_MinHeap(MinHeap** mh) {
    if(*mh != NULL) {
		(*mh)->size = 0;
		(*mh)->capacity = 0;
		free((*mh)->array);
		free((*mh)->pos);
		(*mh)->pos = NULL;
		(*mh)->array = NULL;
		free(*mh);
		*mh = NULL;
	}
}

/*void printData_MinHeap(dataType_minHeap x) {
    printf("%d ",x);
}

void print_heap(MinHeap* mh) {
    
    printf("[ ");
    for(int i = 0; i < mh->size; ++i) {
        printData_MinHeap(h->array[i]);
    }
    printf("]\n");
}*/
