#include <stdio.h>
#include <stdlib.h>

void swap (int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int* arr, int l, int r, int n) {
    //if n is size
    //initially we would send in 0, n-1
    if (r == l) {
        return;
    }
    int mid = ((l + r) / 2);
    sort(arr, l, mid, n);
    sort(arr, mid + 1, r, n);
    
}
int main () {

}