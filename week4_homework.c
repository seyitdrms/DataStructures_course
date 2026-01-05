/*
 * Student Name: Seyithan Durmuş
 * Student Number: 1910213029
 * Course: CS1102 - Data Structures and Algorithms
 * Week 4 Homework: Double and Circular Linked List Operations
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Double Linked List Node
typedef struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

// Circular Linked List Node
typedef struct CNode {
    int data;
    struct CNode *next;
} CNode;

// ========== DOUBLE LINKED LIST OPERATIONS ==========

// Create a new double linked list node
DNode* createDNode(int data) {
    DNode *newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at the end of double linked list
DNode* insertAtEndDouble(DNode *head, int data) {
    DNode *newNode = createDNode(data);
    
    if (head == NULL) {
        return newNode;
    }
    
    DNode *current = head;
    // Traverse to the last node
    while (current->next != NULL) {
        current = current->next;
    }
    
    // Link the new node
    current->next = newNode;
    newNode->prev = current;
    
    return head;
}

// Insert in the middle of double linked list (after a specific value)
DNode* insertInMiddleDouble(DNode *head, int afterValue, int data) {
    DNode *newNode = createDNode(data);
    
    if (head == NULL) {
        printf("List is empty!\n");
        free(newNode);
        return NULL;
    }
    
    DNode *current = head;
    while (current != NULL && current->data != afterValue) {
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Value %d not found!\n", afterValue);
        free(newNode);
        return head;
    }
    
    // Insert after current node
    newNode->next = current->next;
    newNode->prev = current;
    
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    
    current->next = newNode;
    return head;
}

// Print double linked list
void printDoubleList(DNode *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Double Linked List: ");
    DNode *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// ========== SINGLE LINKED LIST (for comparison) ==========

typedef struct SNode {
    int data;
    struct SNode *next;
} SNode;

SNode* createSNode(int data) {
    SNode *newNode = (SNode*)malloc(sizeof(SNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Delete all nodes recursively (Single Linked List)
SNode* deleteAllRecursive(SNode *head) {
    if (head == NULL) {
        return NULL;
    }
    
    // Recursively delete the rest
    head->next = deleteAllRecursive(head->next);
    
    // Delete current node
    free(head);
    return NULL;
}

// ========== CIRCULAR LINKED LIST ==========

CNode* createCNode(int data) {
    CNode *newNode = (CNode*)malloc(sizeof(CNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

CNode* insertAtEndCircular(CNode *head, int data) {
    CNode *newNode = createCNode(data);
    
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    
    CNode *current = head;
    while (current->next != head) {
        current = current->next;
    }
    
    current->next = newNode;
    newNode->next = head;
    return head;
}

void printCircularList(CNode *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Circular Linked List: ");
    CNode *current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

// ========== SORTING COMPARISON ==========

// Bubble Sort for Circular Linked List
void bubbleSortCircular(CNode *head) {
    if (head == NULL || head->next == head) {
        return; // Empty or single node
    }
    
    int swapped;
    CNode *current;
    CNode *last = NULL;
    
    do {
        swapped = 0;
        current = head;
        
        while (current->next != last && current->next != head) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

// Bubble Sort for Normal Linked List
void bubbleSortNormal(SNode *head) {
    if (head == NULL || head->next == NULL) {
        return;
    }
    
    int swapped;
    SNode *current;
    SNode *last = NULL;
    
    do {
        swapped = 0;
        current = head;
        
        while (current->next != last) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

void printNormalList(SNode *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Normal Linked List: ");
    SNode *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    printf("=== 1. Double Linked List - Insert at End ===\n");
    DNode *dHead = NULL;
    dHead = insertAtEndDouble(dHead, 10);
    dHead = insertAtEndDouble(dHead, 20);
    dHead = insertAtEndDouble(dHead, 30);
    printDoubleList(dHead);
    
    printf("\n=== 2. Single Linked List - Delete All Recursively ===\n");
    SNode *sHead = createSNode(10);
    sHead->next = createSNode(20);
    sHead->next->next = createSNode(30);
    printf("Before deletion: ");
    printNormalList(sHead);
    sHead = deleteAllRecursive(sHead);
    printf("After deletion: ");
    printNormalList(sHead);
    
    printf("\n=== 3. Double Linked List - Insert in Middle ===\n");
    dHead = insertInMiddleDouble(dHead, 20, 25);
    printDoubleList(dHead);
    
    printf("\n=== 4. Circular vs Normal Linked List - Sorting Comparison ===\n");
    
    // Create circular list with unsorted data
    CNode *cHead = NULL;
    int circularData[] = {64, 34, 25, 12, 22, 11, 90};
    for (int i = 0; i < 7; i++) {
        cHead = insertAtEndCircular(cHead, circularData[i]);
    }
    printf("Circular Linked List (before sort): ");
    printCircularList(cHead);
    bubbleSortCircular(cHead);
    printf("Circular Linked List (after sort): ");
    printCircularList(cHead);
    
    // Create normal list with same unsorted data
    SNode *nHead = createSNode(64);
    nHead->next = createSNode(34);
    nHead->next->next = createSNode(25);
    nHead->next->next->next = createSNode(12);
    nHead->next->next->next->next = createSNode(22);
    nHead->next->next->next->next->next = createSNode(11);
    nHead->next->next->next->next->next->next = createSNode(90);
    
    printf("\nNormal Linked List (before sort): ");
    printNormalList(nHead);
    bubbleSortNormal(nHead);
    printf("Normal Linked List (after sort): ");
    printNormalList(nHead);
    
    printf("\n=== Key Differences ===\n");
    printf("Circular Linked List:\n");
    printf("- Last node points to first node\n");
    printf("- No NULL pointer at the end\n");
    printf("- Can traverse from any node\n");
    printf("- Requires special handling in loops\n\n");
    
    printf("Normal Linked List:\n");
    printf("- Last node points to NULL\n");
    printf("- Clear end of list\n");
    printf("- Simpler traversal logic\n");
    printf("- Easier to detect end of list\n");
    
    return 0;
}

