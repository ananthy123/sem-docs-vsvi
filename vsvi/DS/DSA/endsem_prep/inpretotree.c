#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* left;
    struct Node* right;
    int val;
}Node;

Node* newNode(int val) {
    Node* new = (Node*) malloc (sizeof(Node));
    new->left = NULL;
    new->right = NULL;
    new->val = val;
}

int preIndex = 0;
int search (int* in, int iStart, int iEnd, int val) {
    for (int i = iStart; i < iEnd; i++) {
        if (in[i] == val) return i;
    }
}
Node* inpretoTree(int* pre, int* in, int iStart, int iEnd) {
    if (iStart > iEnd) return NULL; //indicating that no further goes
    Node* new = newNode(pre[preIndex++]);
    if (iStart == iEnd) return new;

    int inIndex = search(in, iStart, iEnd, new->val);

    new->left = inpretoTree(pre, in, iStart, inIndex - 1);
    new->right = inpretoTree(pre, in, inIndex + 1, iEnd);

    return new;
}
int main () {

}