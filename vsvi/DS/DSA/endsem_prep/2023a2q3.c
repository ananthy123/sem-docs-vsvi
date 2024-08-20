#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

typedef int T;

typedef struct queue {
    T *data;
    int front;
    int rear;
    int size;
} queue;

queue *create_queue(int max_size) {
    queue *new_queue = (queue *) malloc(sizeof(queue));
    new_queue->data = (T *) malloc(max_size * sizeof(T));
    new_queue->front = -1;
    new_queue->rear = -1;
    new_queue->size = max_size;
    return new_queue;
}

void enqueue(queue *q, T data) {
    assert(q->rear < q->size - 1);
    q->data[++q->rear] = data;
}

T dequeue(queue *q) {
    assert(q->front < q->rear);
    return q->data[++q->front];
}
Node* createNode (int val)
{
    Node* newNode = (Node*) malloc (sizeof(Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* createTree (Node* head, int itr, int n) {
    if (itr > n) return NULL;
    
}

void flipArray(int* arr, int n) {
    int x = 2;
    // flip every x * 4 elements 
    for (int i = 0; i < n; i++) {
        if (i + 1 == x) { // start reversing from here
            if (i + x * 2 > n) { // indicating we have reached last level
                int finalItr = n - 1;
                int mid = (i + finalItr) / 2;
                for (int j = i; j <= mid; j++) {
                    int temp = arr[j];
                    arr[j] = arr[finalItr];
                    arr[finalItr] = temp;
                    finalItr--;
                }
            } else {

                int finalIndex = (x * 2) - 2;
                int mid = (i + finalIndex) / 2;
                for (int j = i; j <= mid; j++) {
                    int temp = arr[j];
                    arr[j] = arr[finalIndex];
                    arr[finalIndex] = temp;
                    finalIndex--;
                }
            }
            x = x * 4;  
        }
    }
}


int main () {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        int* inputArray = (int*) malloc (sizeof(int) * n);
        for (int j = 0; j < n; j++) {
        scanf("%d", &inputArray[j]);
        }
        flipArray(inputArray, n);

        for (int j = 0; j < n; j++) {
            printf("%d ", inputArray[j]);
        }
        printf("\n");
    }
}