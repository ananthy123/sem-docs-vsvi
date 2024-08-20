#include <stdio.h>
#include <stdlib.h>

// #define int long long

typedef struct group {
    int j1;
    int j2;
}group;

int cmp (const void* a, const void* b) {
    const group* g1 = (const group*) a;
    const group* g2 = (const group*) b;
    return (g1->j1 - g2->j1);
}
int main () {

}