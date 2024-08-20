#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode (int val)
{
    Node* newNode = (Node*) malloc (sizeof(Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int val) {
    // If the tree is empty, create a new node and make it the root
    if (root == NULL) {
        return createNode(val);
    }

    // Traverse the tree to find the appropriate position to insert the new node
    if (val < root->val) {
        // If the value is less than the current node's value, insert into the left subtree
        root->left = insertNode(root->left, val);
    } else if (val > root->val) {
        // If the value is greater than the current node's value, insert into the right subtree
        root->right = insertNode(root->right, val);
    }

    // Return the root of the modified tree
    return root;
}

int main () {
    int n;
    scanf("%d", &n);
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        root = insert(root, temp);
    }
    
}