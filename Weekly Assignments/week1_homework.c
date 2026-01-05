/*
 * Student Name: Seyithan Durmuş
 * Student Number: 1910213029
 * Course: CS1102 - Data Structures and Algorithms
 * Week 1 Homework: Array Operations
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Reverse array
void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Insert element at specific position
int insertElement(int arr[], int *size, int pos, int value) {
    if (*size >= MAX_SIZE) {
        printf("Array is full!\n");
        return 0;
    }
    
    if (pos < 0 || pos > *size) {
        printf("Invalid position!\n");
        return 0;
    }
    
    // Shift elements to the right
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[pos] = value;
    (*size)++;
    return 1;
}

// Delete element at specific position
int deleteElement(int arr[], int *size, int pos) {
    if (*size == 0) {
        printf("Array is empty!\n");
        return 0;
    }
    
    if (pos < 0 || pos >= *size) {
        printf("Invalid position!\n");
        return 0;
    }
    
    // Shift elements to the left
    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    (*size)--;
    return 1;
}

// Delete element by value
int deleteByValue(int arr[], int *size, int value) {
    int found = 0;
    
    for (int i = 0; i < *size; i++) {
        if (arr[i] == value) {
            // Shift elements to the left
            for (int j = i; j < *size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            (*size)--;
            found = 1;
            i--; // Check same position again
        }
    }
    
    return found;
}

// Print array
void printArray(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty!\n");
        return;
    }
    
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    
    // Initialize array
    printf("=== Initial Array ===\n");
    for (int i = 0; i < 5; i++) {
        arr[i] = (i + 1) * 10;
        size++;
    }
    printArray(arr, size);
    
    // Reverse operation
    printf("\n=== Reverse Operation ===\n");
    reverseArray(arr, size);
    printf("After reverse: ");
    printArray(arr, size);
    
    // Reverse back
    reverseArray(arr, size);
    printf("After reverse back: ");
    printArray(arr, size);
    
    // Insert operations
    printf("\n=== Insert Operations ===\n");
    insertElement(arr, &size, 2, 25);
    printf("Inserted 25 at position 2: ");
    printArray(arr, size);
    
    insertElement(arr, &size, 0, 5);
    printf("Inserted 5 at position 0: ");
    printArray(arr, size);
    
    insertElement(arr, &size, size, 60);
    printf("Inserted 60 at the end: ");
    printArray(arr, size);
    
    // Delete operations
    printf("\n=== Delete Operations ===\n");
    deleteElement(arr, &size, 2);
    printf("Deleted element at position 2: ");
    printArray(arr, size);
    
    deleteByValue(arr, &size, 20);
    printf("Deleted value 20: ");
    printArray(arr, size);
    
    deleteElement(arr, &size, 0);
    printf("Deleted element at position 0: ");
    printArray(arr, size);
    
    return 0;
}

