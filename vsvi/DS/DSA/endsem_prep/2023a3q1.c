#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int cmp (const void* a, const void *b) {
    const char* x = (const char *)a;
    const char* y = (const char *)b;
    return *x - *y;
}

int main () {
    int n, q;
    int maxSizeOfString = 12;
    char bigArray[n][maxSizeOfString];
    char sortedArray[n][maxSizeOfString];

    for (int i = 0; i < n; i++) {
        scanf("%s", bigArray[i]);
        qsort(bigArray[i], strlen(bigArray[i]), )
    }   
}