#include <stdio.h>
#include <stdlib.h>

// #define int long long

int cmp (const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int solve (int* arr, int n, int k) {
    int itr = 0;
    int sum = 0;
    for (int i = 0; i < k; i++) {
        if (arr[itr] < arr[itr + 1]) itr++;
        sum = sum + arr[itr];
        arr[itr] = arr[itr] - 1;
    }
    return sum;
}
int main () {
    int t;
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        int n, k;
        scanf("%d %d", &n, &k);
        int* arr = (int*) malloc (sizeof(int) * n);
        for (int j = 0; j < n; i++) {
            scanf("%d", &arr[j]);
        }
        qsort(arr, n, sizeof(arr[0]), cmp);
        // for (int i = 0; i < n; i++) {
        //     printf("%d ", arr[i]);
        // }
        // printf("\n");
        int res = solve(arr, n, k);
        printf("%d\n", res);
        free(arr);
    }
}