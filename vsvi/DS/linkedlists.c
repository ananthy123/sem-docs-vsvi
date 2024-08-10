#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;

    // Update the head pointer
    *head = newNode;
}

// Function to delete a node from the linked list
void deleteNode(struct Node** head, int key) {
    // If the list is empty
    if (*head == NULL) {
        return;
    }

    // If the key is present at the head node
    if ((*head)->data == key) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    // Find the key in the linked list
    struct Node* prev = *head;
    struct Node* curr = (*head)->next;
    while (curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    // If the key is found, delete the node
    if (curr != NULL) {
        prev->next = curr->next;
        free(curr);
    }
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Insert nodes at the beginning
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    // Display the linked list
    printf("Linked list: ");
    displayList(head);

    // Delete a node
    deleteNode(&head, 2);

    // Display the updated linked list
    printf("Updated linked list: ");
    displayList(head);

    return 0;
}
