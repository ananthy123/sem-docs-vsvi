#include <stdio.h>
#include <stdlib.h>

void quicksort(int* arr, int l, int r)
{
    if (l == r) return;
    int idx = l - 1;
    int pivot = arr[r];
    int i = l;
    while (i < r) {
        if (arr[i] < pivot) {
            idx++;
            swap(&arr[idx], &arr[i]);
        }
        i++;
    }
}


