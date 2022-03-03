#ifndef ALGORITHMS_H
#define ALGORITHMS_H

typedef enum heap{MAX_HEAP,MIN_HEAP} heap;

void quicksort(int* arr, int beginPos, int lastPos);
void mergesort(int* arr, int size);
void heapsort(int* arr, int size,heap h);
int binarySearch(int* arr, int x, int beginPos, int lastPos);
void buildHeap(int* arr, int size, heap h);

#endif //ALGORITHMS