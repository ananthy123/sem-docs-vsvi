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

int search (int* in, int iStart, int iEnd, int val) {
    for (int i = iStart; i < iEnd; i++) {
        if (in[i] == val) return i;
    }
}

int preIndex = 0;

Node* inPretoTree(int* pre, int* in, int inLeft, int inRight) {
    if (inLeft > inRight) return NULL;
    Node* new = newNode(pre[preIndex++]);
    if (inLeft == inRight) return new;

    int inIndex = search(in, inLeft, inRight, new->val);

    new->left = (pre, in, inLeft, inIndex - 1);
    new->right = (pre, in, inIndex + 1, inRight);
    return new;

}
int main () {

}