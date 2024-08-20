#include <stdio.h>
#include <stdlib.h>

typedef struct fight {
    int hardestFight;
    int moddedIndex;
    int Index;
} fight;

int cmp (const void* a, const void* b) {
    const fight* first = (const fight*) a;
    const fight* second = (const fight*) b;
    return (second->hardestFight - first->hardestFight);
}
int main () {
    int t;
    for (int i = 0; i < t; i++) {
        int k, m; // number of participating schools and number of students from each school
        int totalElements = (k * m) + 1;
        int* arr = (int*) malloc (sizeof(int) * totalElements);
    }
}