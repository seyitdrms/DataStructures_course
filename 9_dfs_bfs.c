/*
 * Student Name: Seyithan Durmuş
 * Student Number: 1910213029
 * Course: CS1102 - Data Structures and Algorithms
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Graph represented as adjacency matrix
int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int vertices;

// Queue for BFS
typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

// Initialize queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is empty
bool isEmpty(Queue *q) {
    return q->rear == -1;
}

// Enqueue
void enqueue(Queue *q, int value) {
    if (q->rear == MAX_VERTICES - 1) {
        printf("Queue is full!\n");
        return;
    }
    
    if (q->front == -1) {
        q->front = 0;
    }
    
    q->rear++;
    q->items[q->rear] = value;
}

// Dequeue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    
    int item = q->items[q->front];
    q->front++;
    
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    
    return item;
}

// Initialize graph
void initGraph(int v) {
    vertices = v;
    for (int i = 0; i < v; i++) {
        visited[i] = 0;
        for (int j = 0; j < v; j++) {
            graph[i][j] = 0;
        }
    }
}

// Add edge to graph
void addEdge(int src, int dest) {
    graph[src][dest] = 1;
    graph[dest][src] = 1; // Undirected graph
}

// Reset visited array
void resetVisited() {
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }
}

// Depth First Search
void DFS(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    
    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

// Breadth First Search
void BFS(int start) {
    Queue q;
    initQueue(&q);
    
    visited[start] = 1;
    enqueue(&q, start);
    
    while (!isEmpty(&q)) {
        int vertex = dequeue(&q);
        printf("%d ", vertex);
        
        for (int i = 0; i < vertices; i++) {
            if (graph[vertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
}

// Print adjacency matrix
void printGraph() {
    printf("Adjacency Matrix:\n");
    printf("   ");
    for (int i = 0; i < vertices; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < vertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int v = 6;
    initGraph(v);
    
    // Create a sample graph
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);
    
    printf("Graph Structure:\n");
    printGraph();
    printf("\n");
    
    printf("=== DFS Traversal (starting from 0) ===\n");
    resetVisited();
    DFS(0);
    printf("\n\n");
    
    printf("=== BFS Traversal (starting from 0) ===\n");
    resetVisited();
    BFS(0);
    printf("\n");
    
    return 0;
}

