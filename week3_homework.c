/*
 * Student Name: Seyithan Durmuş
 * Student Number: 1910213029
 * Course: CS1102 - Data Structures and Algorithms
 * Week 3 Homework: Linked List Operations
 */

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Create a new node
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Create a list from array
// Time Complexity: O(n) where n is the number of elements
Node* createList(int arr[], int size) {
    if (size == 0) {
        return NULL;
    }
    
    Node *head = createNode(arr[0]);
    Node *current = head;
    
    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    
    return head;
}

// Traverse and print the list
// Time Complexity: O(n) where n is the number of nodes
void traverse(Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("List traversal: ");
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Insert at the beginning
// Time Complexity: O(1)
Node* insertAtBeginning(Node *head, int data) {
    Node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Insert at the end
// Time Complexity: O(n) where n is the number of nodes
Node* insertAtEnd(Node *head, int data) {
    Node *newNode = createNode(data);
    
    if (head == NULL) {
        return newNode;
    }
    
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = newNode;
    return head;
}

// Insert in the middle (after a specific value)
// Time Complexity: O(n) where n is the number of nodes
Node* insertInMiddle(Node *head, int afterValue, int data) {
    Node *newNode = createNode(data);
    Node *current = head;
    
    while (current != NULL && current->data != afterValue) {
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Value %d not found! Insertion failed.\n", afterValue);
        free(newNode);
        return head;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Delete a node by value
// Time Complexity: O(n) where n is the number of nodes
Node* deleteNode(Node *head, int value) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    
    // If head node is to be deleted
    if (head->data == value) {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    
    // Find the node to delete
    Node *current = head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }
    
    if (current->next == NULL) {
        printf("Value %d not found!\n", value);
        return head;
    }
    
    // Delete the node
    Node *temp = current->next;
    current->next = current->next->next;
    free(temp);
    
    return head;
}

// Delete all nodes
// Time Complexity: O(n) where n is the number of nodes
Node* deleteAll(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    return NULL;
}

int main() {
    Node *head = NULL;
    
    printf("=== Creating a List ===\n");
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    head = createList(arr, size);
    traverse(head);
    
    printf("\n=== Insert Operations ===\n");
    head = insertAtBeginning(head, 5);
    printf("Inserted 5 at beginning: ");
    traverse(head);
    
    head = insertAtEnd(head, 60);
    printf("Inserted 60 at end: ");
    traverse(head);
    
    head = insertInMiddle(head, 30, 25);
    printf("Inserted 25 after 30: ");
    traverse(head);
    
    printf("\n=== Delete Operations ===\n");
    head = deleteNode(head, 25);
    printf("Deleted 25: ");
    traverse(head);
    
    head = deleteNode(head, 5);
    printf("Deleted 5: ");
    traverse(head);
    
    printf("\n=== Complexity Analysis ===\n");
    printf("Creating a list: O(n)\n");
    printf("Traversal: O(n)\n");
    printf("Insert at beginning: O(1)\n");
    printf("Insert at end: O(n)\n");
    printf("Insert in middle: O(n)\n");
    printf("Delete node: O(n)\n");
    printf("Delete all: O(n)\n");
    
    printf("\n=== Delete All ===\n");
    head = deleteAll(head);
    traverse(head);
    
    return 0;
}

