#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct Node {
    char key[50];
    int value;
    struct Node* next;
} Node;

Node* hashtable[SIZE];

// Hash function
int hash(char* key) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }
    return sum % SIZE;
}

// Insert a key-value pair into the hashtable
void insert(char* key, int value) {
    int index = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    newNode->value = value;
    newNode->next = NULL;

    if (hashtable[index] == NULL) {
        hashtable[index] = newNode;
    } else {
        Node* current = hashtable[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Retrieve the value associated with a key from the hashtable
int get(char* key) {
    int index = hash(key);
    Node* current = hashtable[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return -1; // Key not found
}

// Main function
int main() {
    // Insert some key-value pairs
    insert("apple", 5);
    insert("banana", 10);
    insert("orange", 15);

    // Retrieve values
    printf("Value of apple: %d\n", get("apple"));
    printf("Value of banana: %d\n", get("banana"));
    printf("Value of orange: %d\n", get("orange"));
    printf("Value of mango: %d\n", get("mango"));

    return 0;
}
