#include <stdio.h>
#include <string.h>
#include "algorithms.h"

void print_array(int*, int);

int main()
{
    int arr[] = {100,56,0,1,-45,2,46,5,9,6,67,23,5};
    //int arr[] = {1,3,5,4,6,13,10,9,8,15,17};
    int size = sizeof(arr)/sizeof(int);
    print_array(arr,size);
    /*quicksort(arr,0,size-1);
    print_array(arr,size);
    printf("%d\n",binarySearch(arr,-1,0,size-1));
    printf("%d\n",binarySearch(arr,-45,0,size-1));
    printf("%d\n",binarySearch(arr,-100,0,size-1));
    printf("%d\n",binarySearch(arr,67,0,size-1));
    printf("%d\n",binarySearch(arr,200,0,size-1));
    mergesort(arr,size);
    print_array(arr,size);*/
    buildHeap(arr,size,MAX_HEAP);
    print_array(arr,size);
    heapsort(arr,size,MAX_HEAP);
    print_array(arr,size);

    return 0;
}

void print_array(int* arr, int size) {
    printf("[");
    for(int i = 0; i < size; ++i)
        printf("%d ",arr[i]);
    printf("]\n");
}