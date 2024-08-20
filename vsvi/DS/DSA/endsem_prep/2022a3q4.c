#include <stdio.h>

int minSwapsToSort(int towers[], int n, int k) {
    int swaps = 0;
    
    for (int i = 0; i < n; i++) {
        if (towers[i] > k) {
            swaps++;
        }
    }

    if (swaps > k) {
        return -1; // Sorting not possible
    }

    return swaps;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int towers[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &towers[i]);
    }

    int minSwaps = minSwapsToSort(towers, n, k);

    printf("%d\n", minSwaps);

    return 0;
}
