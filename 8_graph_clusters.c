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

// DFS to find all vertices in a cluster
void DFS(int vertex, int cluster[], int *clusterSize) {
    visited[vertex] = 1;
    cluster[*clusterSize] = vertex;
    (*clusterSize)++;
    
    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] == 1 && visited[i] == 0) {
            DFS(i, cluster, clusterSize);
        }
    }
}

// Extract all clusters from graph
void extractClusters() {
    int clusterNum = 0;
    
    // Reset visited array
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }
    
    for (int i = 0; i < vertices; i++) {
        if (visited[i] == 0) {
            int cluster[MAX_VERTICES];
            int clusterSize = 0;
            
            DFS(i, cluster, &clusterSize);
            
            clusterNum++;
            printf("Cluster %d: ", clusterNum);
            for (int j = 0; j < clusterSize; j++) {
                printf("%d ", cluster[j]);
            }
            printf("\n");
        }
    }
    
    printf("Total clusters found: %d\n", clusterNum);
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
    int v = 8;
    initGraph(v);
    
    // Create a graph with multiple clusters
    // Cluster 1: 0-1-2
    addEdge(0, 1);
    addEdge(1, 2);
    
    // Cluster 2: 3-4
    addEdge(3, 4);
    
    // Cluster 3: 5-6-7
    addEdge(5, 6);
    addEdge(6, 7);
    
    printf("Graph Structure:\n");
    printGraph();
    printf("\n");
    
    printf("=== Extracted Clusters ===\n");
    extractClusters();
    
    return 0;
}

