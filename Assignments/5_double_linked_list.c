/*
 * Student Name: Seyithan Durmuş
 * Student Number: 1910213029
 * Course: CS1102 - Data Structures and Algorithms
 */

#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Create a new node
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at the beginning
Node* insertAtBeginning(Node *head, int data) {
    Node *newNode = createNode(data);
    
    if (head == NULL) {
        return newNode;
    }
    
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// Insert at the end
Node* insertAtEnd(Node *head, int data) {
    Node *newNode = createNode(data);
    
    if (head == NULL) {
        return newNode;
    }
    
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Insert after a given node
Node* insertAfter(Node *head, int key, int data) {
    Node *newNode = createNode(data);
    Node *temp = head;
    
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Key %d not found!\n", key);
        free(newNode);
        return head;
    }
    
    newNode->next = temp->next;
    newNode->prev = temp;
    
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    
    temp->next = newNode;
    return head;
}

// Delete a node by value
Node* deleteNode(Node *head, int key) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    
    Node *temp = head;
    
    // If head node is to be deleted
    if (temp->data == key) {
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }
    
    // Find the node to delete
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Key %d not found!\n", key);
        return head;
    }
    
    // Update links
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    
    free(temp);
    return head;
}

// Traverse forward
void traverseForward(Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Forward traversal: ");
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Traverse backward
void traverseBackward(Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    // Go to the last node
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    printf("Backward traversal: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Search for a value
int search(Node *head, int key) {
    Node *temp = head;
    int position = 0;
    
    while (temp != NULL) {
        if (temp->data == key) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    
    return -1; // Not found
}

int main() {
    Node *head = NULL;
    
    // Insert operations
    printf("=== Insert Operations ===\n");
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtBeginning(head, 5);
    head = insertAfter(head, 20, 25);
    
    traverseForward(head);
    traverseBackward(head);
    
    // Search operation
    printf("\n=== Search Operation ===\n");
    int key = 20;
    int pos = search(head, key);
    if (pos != -1) {
        printf("Value %d found at position %d\n", key, pos);
    } else {
        printf("Value %d not found\n", key);
    }
    
    // Delete operations
    printf("\n=== Delete Operations ===\n");
    head = deleteNode(head, 25);
    traverseForward(head);
    
    head = deleteNode(head, 5);
    traverseForward(head);
    
    head = deleteNode(head, 30);
    traverseForward(head);
    
    return 0;
}

