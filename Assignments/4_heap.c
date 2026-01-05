/*
 * Student Name: Seyithan Durmuş
 * Student Number: 1910213029
 * Course: CS1102 - Data Structures and Algorithms
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Heap structure
typedef struct {
    int arr[MAX_SIZE];
    int size;
} Heap;

// Initialize heap
void initHeap(Heap *h) {
    h->size = 0;
}

// Swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Max Heap: Heapify up
void maxHeapifyUp(Heap *h, int index) {
    int parent = (index - 1) / 2;
    
    if (index > 0 && h->arr[index] > h->arr[parent]) {
        swap(&h->arr[index], &h->arr[parent]);
        maxHeapifyUp(h, parent);
    }
}

// Max Heap: Heapify down
void maxHeapifyDown(Heap *h, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    
    if (left < h->size && h->arr[left] > h->arr[largest]) {
        largest = left;
    }
    
    if (right < h->size && h->arr[right] > h->arr[largest]) {
        largest = right;
    }
    
    if (largest != index) {
        swap(&h->arr[index], &h->arr[largest]);
        maxHeapifyDown(h, largest);
    }
}

// Min Heap: Heapify up
void minHeapifyUp(Heap *h, int index) {
    int parent = (index - 1) / 2;
    
    if (index > 0 && h->arr[index] < h->arr[parent]) {
        swap(&h->arr[index], &h->arr[parent]);
        minHeapifyUp(h, parent);
    }
}

// Min Heap: Heapify down
void minHeapifyDown(Heap *h, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    
    if (left < h->size && h->arr[left] < h->arr[smallest]) {
        smallest = left;
    }
    
    if (right < h->size && h->arr[right] < h->arr[smallest]) {
        smallest = right;
    }
    
    if (smallest != index) {
        swap(&h->arr[index], &h->arr[smallest]);
        minHeapifyDown(h, smallest);
    }
}

// Insert into Max Heap
void insertMaxHeap(Heap *h, int value) {
    if (h->size >= MAX_SIZE) {
        printf("Heap is full!\n");
        return;
    }
    
    h->arr[h->size] = value;
    maxHeapifyUp(h, h->size);
    h->size++;
}

// Insert into Min Heap
void insertMinHeap(Heap *h, int value) {
    if (h->size >= MAX_SIZE) {
        printf("Heap is full!\n");
        return;
    }
    
    h->arr[h->size] = value;
    minHeapifyUp(h, h->size);
    h->size++;
}

// Extract max from Max Heap
int extractMax(Heap *h) {
    if (h->size == 0) {
        printf("Heap is empty!\n");
        return -1;
    }
    
    int max = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    maxHeapifyDown(h, 0);
    
    return max;
}

// Extract min from Min Heap
int extractMin(Heap *h) {
    if (h->size == 0) {
        printf("Heap is empty!\n");
        return -1;
    }
    
    int min = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    minHeapifyDown(h, 0);
    
    return min;
}

// Print heap
void printHeap(Heap *h) {
    printf("Heap: ");
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}

int main() {
    Heap maxHeap, minHeap;
    initHeap(&maxHeap);
    initHeap(&minHeap);
    
    int values[] = {10, 20, 15, 30, 40, 5, 25};
    int n = sizeof(values) / sizeof(values[0]);
    
    printf("=== MAX HEAP ===\n");
    for (int i = 0; i < n; i++) {
        insertMaxHeap(&maxHeap, values[i]);
        printf("Inserted %d: ", values[i]);
        printHeap(&maxHeap);
    }
    
    printf("\nExtracting max elements:\n");
    while (maxHeap.size > 0) {
        printf("Extracted: %d, ", extractMax(&maxHeap));
        printHeap(&maxHeap);
    }
    
    printf("\n=== MIN HEAP ===\n");
    for (int i = 0; i < n; i++) {
        insertMinHeap(&minHeap, values[i]);
        printf("Inserted %d: ", values[i]);
        printHeap(&minHeap);
    }
    
    printf("\nExtracting min elements:\n");
    while (minHeap.size > 0) {
        printf("Extracted: %d, ", extractMin(&minHeap));
        printHeap(&minHeap);
    }
    
    return 0;
}

