#include <stdio.h>
#include <string.h>
#include "algorithms.h"

#define TRUE 1
#define FALSE 0

void swap(int* arr, int i, int j) { 
    /*if(arr[i] != arr[j]) {
        arr[i] ^= arr[j];
        arr[j] ^= arr[i];
        arr[i] ^= arr[j];
    }*/
    
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int* arr, int left, int right, int pivote) {

    while(left <= right) {
        while(arr[left] < pivote)
            left++;
    
        while(arr[right] > pivote)
            right--;

        if(left <= right) {
            swap(arr,left,right);
            left++;
            right--;
        }
    }
    
    return left;
}

void quicksort(int* arr, int left, int right) {
    /*int pivote;
    
    if(left >= right)
        return;
    
    pivote = arr[(left+right)/2];
    int index = partition(arr,left,right,pivote);

    quicksort(arr,left,index-1);
    quicksort(arr,index,right);*/
    
    if(left != right) {
        int pivote = arr[(left+right)/2];
        int index = partition(arr,left,right,pivote);
        quicksort(arr,left,index-1);
        quicksort(arr,index,right);
    }

}

void mergeHalves(int* arr, int* temp, int leftStart, int rightEnd) {
    int leftEnd = (rightEnd + leftStart)/2;
    int rightStart = leftEnd + 1;
    int size = rightEnd - leftStart + 1;

    int left = leftStart;
    int right = rightStart;
    int index = leftStart;

    while((left <= leftEnd) && (right <= rightEnd)) {
        if(arr[left] <= arr[right]) {
            temp[index] = arr[left];
            ++left;
        } else {
            temp[index] = arr[right];
            ++right;
        }
        ++index;
    }
    
    memmove(temp+index,arr+left,(size_t)(leftEnd - left + 1)*sizeof(int));
    memmove(temp+index,arr+right,(size_t)(rightEnd - right + 1)*sizeof(int));
    memmove(arr+leftStart,temp+leftStart,(size_t)size*sizeof(int));
}

void mergesortA(int* arr, int* temp, int left, int right) {
    if(left != right){
        int middle = (left + right) / 2;
        mergesortA(arr,temp,left,middle);
        mergesortA(arr,temp,middle+1,right);
        mergeHalves(arr,temp,left,right);
    }
}

void mergesort(int* arr, int size) {
    int temp[size];
    memset(temp,0,(size_t)size*sizeof(arr[0]));
    mergesortA(arr,temp,0,size-1);
    
}

int binarySearch(int* arr, int x, int left, int right) {
    
    if(right >= left) {
        int m = left + (right-left)/2;
        if(x == arr[m])
            return TRUE;
        if(x < arr[m])
            return binarySearch(arr,x,left,m-1);
        else
            return binarySearch(arr,x,m+1,right);
    }
    return FALSE;
}

void maxHeapify(int* arr, int n, int i) {

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < n && arr[l] > arr[largest])
        largest = l;

    if(r < n && arr[r] > arr[largest])
        largest = r;

    if(largest != i) {
        swap(arr,i,largest);
        maxHeapify(arr,n,largest);
    }
}

void minHeapify(int* arr, int n, int i) {

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < n && arr[l] < arr[largest])
        largest = l;

    if(r < n && arr[r] < arr[largest])
        largest = r;

    if(largest != i) {
        swap(arr,i,largest);
        minHeapify(arr,n,largest);
    }
}

void buildHeap(int* arr, int size, heap h) {

    int starIdx = (size/2) - 1;

    if(h == MAX_HEAP) {
        for(int i = starIdx; i>=0 ; --i) {
            maxHeapify(arr,size,i);
        }
    } else {
        for(int i = starIdx; i>=0 ; --i) {
            minHeapify(arr,size,i);
        }
    }

    
}

void heapsort(int* arr, int n, heap h) {

    if(h == MAX_HEAP) {
        for(int i = n-1; i > 0; --i) {
            swap(arr,i,0);
            maxHeapify(arr,i,0);
        }
    } else {
        for(int i = n-1; i > 0; --i) {
            swap(arr,i,0);
            minHeapify(arr,i,0);
        }
    }   
}