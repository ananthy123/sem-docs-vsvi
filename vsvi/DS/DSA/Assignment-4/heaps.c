#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000
void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify (int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] < arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        //swap arr[i] and arr[largest]
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, n, largest);
    }
}

void buildMinHeap (int arr[], int n) {
    for (int i = (n-1)/2; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

//Logic for heapifying from bottom

void minInsertHeap (int arr[], int *n, int key) {
    //assert if n is max size
    int i = *n;
    (*n)++;

    while (i > 0 && arr[(i-1) / 2] > arr[i]) {
        int k = (i-1) / 2;
        //swap arr[i] and arr[k] and push it 
        int temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
        i = k; 
    }
}

int deleteHeap (int arr[], int* n) {
    //check if n is less than 0
    int greatestElem = arr[0];
    arr[0] = arr[--(*n)];
    maxHeapify(arr, *n, 0);
}

void minInsertHeap(int arr[], int *n, int key) {
    // Ensure capacity
    if (*n == MAX_SIZE) {
        printf("Heap is full. Cannot insert.\n");
        return;
    }

    // Insert the new key at the end of the heap
    int i = *n;
    arr[i] = key;
    (*n)++;

    // Fix the min heap property by comparing with parent and swapping if necessary
    while (i > 0 && arr[(i - 1) / 2] > arr[i]) {
        // Swap arr[i] with its parent
        int parent = (i - 1) / 2;
        swap(&arr[i], &arr[parent]);
        i = parent; // Update index to the parent
    }
}
