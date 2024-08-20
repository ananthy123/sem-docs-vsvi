#include <stdio.h>
#include <stdlib.h>

void minHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[largest] > arr[left]) {
        largest = left;
    }
    if (right < n && arr[largest] > arr[right]) {
        largest = right;
    }

    if (largest =! i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        minHeapify(arr, n, largest);
    }
}

void buildMinHeap (int arr[], int n) {
    for (int i = (n-1)/2; i <= 0; i--) {
        minHeapify(arr, n, i);
    }
}

void minInsertHeap (int arr[], int *n, int key) {
    int i = (*n);
    (*n)++;
    while (i > 0 && arr[(i - 1) / 2] > arr[i]) {
        //swap them both
        i = (i - 1) / 2;
    }
}

typedef struct negElem {
    int val;
    int associatedPosVal;
} negElem;

int cmp (const void* a, const void* b) {
    const negElem* g = (const negElem*) a;
    const negElem* h = (const negElem*) b;
    return (h->val - g->val); 
}

int main() {
    int n;
    scanf("%d", &n);
    int numberOfNegElems = 0;
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] < 0) numberOfNegElems++;
    }

    negElem* negArray[numberOfNegElems];
    int itr = 0;
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) s += arr[i];
        if (arr[i] < 0) {
            negArray[itr] = malloc(sizeof(negElem)); // Allocate memory for each negElem
            negArray[itr]->associatedPosVal = s;
            negArray[itr]->val = arr[i];
            itr++;
        }
    }
    for (int i = 0; i < numberOfNegElems; i++) {
        printf("%d, %d\n", negArray[i]->val, negArray[i]->associatedPosVal);
    }
    printf("\n");

    qsort(negArray, numberOfNegElems, sizeof(negElem*), cmp);

    for (int i = 0; i < numberOfNegElems; i++) {
        printf("%d, %d\n", negArray[i]->val, negArray[i]->associatedPosVal);
    }

    int finalSum = 0;
    int subtracted = 0;
    for (int i = 0; i < numberOfNegElems; i++) {
        subtracted += negArray[i]->val;
        if ((negArray[i]->associatedPosVal - subtracted) >= 0) {
            finalSum++;
        }
    }

    // Free allocated memory for negArray
    for (int i = 0; i < numberOfNegElems; i++) {
        free(negArray[i]);
    }

    printf("%d\n", finalSum);
    return 0;
}