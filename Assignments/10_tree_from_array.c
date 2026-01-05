/*
 * Student Name: Seyithan Durmuş
 * Student Number: 1910213029
 * Course: CS1102 - Data Structures and Algorithms
 */

#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Create a new node
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Build tree from array (level order)
Node* buildTreeFromArray(int arr[], int size, int index) {
    if (index >= size || arr[index] == -1) {
        return NULL;
    }
    
    Node *root = createNode(arr[index]);
    
    // Left child at 2*index + 1
    root->left = buildTreeFromArray(arr, size, 2 * index + 1);
    
    // Right child at 2*index + 2
    root->right = buildTreeFromArray(arr, size, 2 * index + 2);
    
    return root;
}

// Inorder traversal
void inorderTraversal(Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Preorder traversal
void preorderTraversal(Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Postorder traversal
void postorderTraversal(Node *root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Level order traversal (BFS)
void levelOrderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }
    
    Node *queue[100];
    int front = 0, rear = 0;
    
    queue[rear++] = root;
    
    while (front < rear) {
        Node *current = queue[front++];
        printf("%d ", current->data);
        
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}

// Print tree structure (simple visualization)
void printTree(Node *root, int space) {
    if (root == NULL) {
        return;
    }
    
    space += 5;
    
    printTree(root->right, space);
    
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    
    printTree(root->left, space);
}

int main() {
    // Array representation of tree
    // -1 represents NULL/empty node
    int arr[] = {1, 2, 3, 4, 5, 6, 7, -1, -1, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array representation: ");
    for (int i = 0; i < size; i++) {
        if (arr[i] != -1) {
            printf("%d ", arr[i]);
        } else {
            printf("NULL ");
        }
    }
    printf("\n\n");
    
    // Build tree from array
    Node *root = buildTreeFromArray(arr, size, 0);
    
    printf("=== Tree Traversals ===\n");
    printf("Inorder:   ");
    inorderTraversal(root);
    printf("\n");
    
    printf("Preorder:  ");
    preorderTraversal(root);
    printf("\n");
    
    printf("Postorder: ");
    postorderTraversal(root);
    printf("\n");
    
    printf("Level Order: ");
    levelOrderTraversal(root);
    printf("\n");
    
    printf("\n=== Tree Structure ===\n");
    printTree(root, 0);
    printf("\n");
    
    return 0;
}

