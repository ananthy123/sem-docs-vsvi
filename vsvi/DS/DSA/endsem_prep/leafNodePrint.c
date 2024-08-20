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
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    // if (root->left == NULL && root->right == NULL) 
        printf("%d ", root->val);
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}
int main () {
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Inorder traversal of the original tree: ");
    inorder(root);
    printf("\n");
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");
}