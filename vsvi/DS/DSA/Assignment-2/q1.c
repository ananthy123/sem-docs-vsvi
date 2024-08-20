#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int globalVariable = 0;
// TreeNode structure
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    int hasAccess;
    int hasPhone;
    struct TreeNode* parent;
} TreeNode;

// Queue node structure
typedef struct QueueNode {
    TreeNode* node;
    struct QueueNode* next;
} QueueNode;

// Queue structure
typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// Function to create a new TreeNode
TreeNode* createTreeNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    newNode->hasAccess = 0;
    newNode->hasPhone = 0;
    return newNode;
}

// Function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to enqueue a TreeNode
void enqueue(Queue* q, TreeNode* node) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->node = node;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

// Function to dequeue a TreeNode
TreeNode* dequeue(Queue* q) {
    if (q->front == NULL)
        return NULL;

    QueueNode* temp = q->front;
    TreeNode* node = temp->node;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return node;
}

// Function to convert level order array to a binary tree
TreeNode* levelOrderToTree(int* array, int n) {
    
    TreeNode* root = createTreeNode(array[0]);
    Queue* q = createQueue();
    enqueue(q, root);

    for (int i = 1; i < n; i += 2) {
        TreeNode* current = dequeue(q);

        if (array[i] != 0) {
            current->left = createTreeNode(array[i]);
            current->left->parent=current;
            enqueue(q, current->left);
        }

        if (i + 1 < n && array[i + 1] != 0) {
            current->right = createTreeNode(array[i + 1]);
            current->right->parent=current;
            enqueue(q, current->right);
        }
    }

    return root;
}

bool isParentOfLeftLeaf(TreeNode* root) {
    if (root->left != NULL && root->right == NULL) {
        if ((root->left->left == NULL && root->left->right == NULL)) return true;
    }
    return false;
}

bool isParentOfRightLeaf(TreeNode* root) {
    if (root->right != NULL && root->left == NULL) {
        if ((root->right->left == NULL) && (root->right->right == NULL)) return true;
    }
    return false;
}

bool isParentOfBothLeaf(TreeNode* root) {
    if (root->right != NULL && root->left != NULL) {
        if ((root->left->left == NULL && root->left->right == NULL) && ((root->right->left == NULL) && (root->right->right == NULL))) return true;
    }
    return false;
}

bool isLeftStraightLine(TreeNode* root) {
    if(root->right == NULL && root->left!=NULL && root->left->hasAccess == 0) return true;
    return false;
}

bool isRightStraightLine(TreeNode* root) {
    if (root->left == NULL && root->right->hasAccess == 0) return true;
    return false;
}

bool isDoubleNodedWithNoAccess(TreeNode* root) {
    if (root->left != NULL && root->right != NULL) {
        // printf("in 1st if in dnna\n");
        if (root->left->hasAccess == 0 || root->right->hasAccess == 0) {
            // printf("in 2nd if in dnna\n");
            return true;
        }
    }
    return false;
}

bool isDoubleNodedWithAccess(TreeNode* root) {
    if(root->left != NULL && root->right != NULL) {
        if(root->left->hasAccess == 1 || root->right->hasAccess == 1) {
            return true;
        }
    }
    return false;
}

void postOrderTraversal(TreeNode* root) {
    if (root == NULL)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    if (root->left == NULL && root->right == NULL)
        return; 
    if (isParentOfLeftLeaf(root) == true) {
        // printf("in poll\n");
        root->hasAccess = 1;
        root->hasPhone = 1;
        root->left->hasAccess = 1;
        globalVariable++;
        if (root->parent != NULL) 
            root->parent->hasAccess = 1;
    }

    else if (isParentOfRightLeaf(root) == true) {
        // printf("porl\n");
        root->hasAccess = 1;
        root->hasPhone = 1;
        root->right->hasAccess = 1;
        globalVariable++;
        if (root->parent != NULL) 
            root->parent->hasAccess = 1;
    }

    else if (isParentOfBothLeaf(root) == true) {
        // printf("pobl\n");
        root->hasAccess = 1;
        root->hasPhone = 1;
        root->right->hasAccess = 1;
        root->left->hasAccess = 1;
        globalVariable++;
        if (root->parent != NULL) 
            root->parent->hasAccess = 1;
    }

    else if (isLeftStraightLine(root) == true) {
        // printf("lsl\n");
        root->hasPhone = 1;
        root->hasAccess = 1;
        root->left->hasAccess = 1;
        globalVariable++;
        if (root->parent != NULL) 
            root->parent->hasAccess = 1;
    }

    else if (isRightStraightLine(root) == true) {
        // printf("rsl\n");
        root->hasAccess = 1;
        root->hasPhone = 1;
        root->right->hasAccess = 1;
        globalVariable++;
        if (root->parent != NULL) 
            root->parent->hasAccess = 1;
    }

    else if (isDoubleNodedWithNoAccess(root) == true) {
        // printf("DN\n");
        root->hasPhone = 1;
        root->hasAccess = 1;
        root->left->hasAccess = 1;
        root->right->hasAccess = 1;
        globalVariable++;
        if (root->parent != NULL) 
            root->parent->hasAccess = 1;
    }
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}
void printLevelOrder(TreeNode* root) {
    if (root == NULL)
        return;

    Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        TreeNode* current = dequeue(q);
        printf("%d ", current->data);

        if (current->left != NULL)
            enqueue(q, current->left);

        if (current->right != NULL)
            enqueue(q, current->right);
    }

    free(q);
}

TreeNode* access(TreeNode* root) {return root;}
    
// void numberOfPhones (TreeNode* root) {
//     postOrderTraversal(root);
// }

int main () {
    int n;
    scanf("%d", &n);
    int* array = (int*) malloc (sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    
    TreeNode* root = levelOrderToTree(array, n);
    // printLevelOrder(root);
    if(root->left==NULL && root->right==NULL)globalVariable=1;
    else {
        postOrderTraversal(root);
        if(root->hasAccess==0)globalVariable++;
    }
    printf("%d", globalVariable);
    access(root);
}