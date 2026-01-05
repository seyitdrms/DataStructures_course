/*
 * Student Name: Seyithan Durmuş
 * Student Number: 1910213029
 * Course: CS1102 - Data Structures and Algorithms
 */

#include <stdio.h>
#include <stdlib.h>

// Node structure for circular linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Create a new node
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at the beginning
Node* insertAtBeginning(Node *head, int data) {
    Node *newNode = createNode(data);
    
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    
    Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    
    newNode->next = head;
    temp->next = newNode;
    return newNode;
}

// Insert at the end
Node* insertAtEnd(Node *head, int data) {
    Node *newNode = createNode(data);
    
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    
    Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->next = head;
    return head;
}

// Insert after a given node
Node* insertAfter(Node *head, int key, int data) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    
    Node *newNode = createNode(data);
    Node *temp = head;
    
    do {
        if (temp->data == key) {
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    } while (temp != head);
    
    printf("Key %d not found!\n", key);
    free(newNode);
    return head;
}

// Delete a node by value
Node* deleteNode(Node *head, int key) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    
    Node *temp = head;
    Node *prev = NULL;
    
    // If head node is to be deleted
    if (temp->data == key) {
        // If only one node
        if (temp->next == head) {
            free(temp);
            return NULL;
        }
        
        // Find the last node
        Node *last = head;
        while (last->next != head) {
            last = last->next;
        }
        
        head = temp->next;
        last->next = head;
        free(temp);
        return head;
    }
    
    // Find the node to delete
    do {
        prev = temp;
        temp = temp->next;
        if (temp->data == key) {
            prev->next = temp->next;
            free(temp);
            return head;
        }
    } while (temp != head);
    
    printf("Key %d not found!\n", key);
    return head;
}

// Traverse the circular list
void traverse(Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Circular list traversal: ");
    Node *temp = head;
    
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    
    printf("\n");
}

// Search for a value
int search(Node *head, int key) {
    if (head == NULL) {
        return -1;
    }
    
    Node *temp = head;
    int position = 0;
    
    do {
        if (temp->data == key) {
            return position;
        }
        temp = temp->next;
        position++;
    } while (temp != head);
    
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
    
    traverse(head);
    
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
    traverse(head);
    
    head = deleteNode(head, 5);
    traverse(head);
    
    head = deleteNode(head, 30);
    traverse(head);
    
    return 0;
}

