/*
 * Student Name: Seyithan Durmuş
 * Student Number: 1910213029
 * Course: CS1102 - Data Structures and Algorithms
 */

#include <stdio.h>
#include <stdlib.h>

// Sparse Matrix Structure
typedef struct {
    int row;
    int col;
    int value;
} Element;

typedef struct {
    int rows;
    int cols;
    int numNonZero;
    Element *data;
} SparseMatrix;

// Convert regular matrix to sparse matrix
SparseMatrix* convertToSparse(int **matrix, int rows, int cols) {
    int count = 0;
    
    // Count non-zero elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }
    
    // Allocate sparse matrix
    SparseMatrix *sparse = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    sparse->rows = rows;
    sparse->cols = cols;
    sparse->numNonZero = count;
    sparse->data = (Element*)malloc(count * sizeof(Element));
    
    // Fill sparse matrix
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse->data[index].row = i;
                sparse->data[index].col = j;
                sparse->data[index].value = matrix[i][j];
                index++;
            }
        }
    }
    
    return sparse;
}

// Print sparse matrix
void printSparseMatrix(SparseMatrix *sparse) {
    printf("Sparse Matrix Representation:\n");
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < sparse->numNonZero; i++) {
        printf("%d\t%d\t%d\n", 
               sparse->data[i].row, 
               sparse->data[i].col, 
               sparse->data[i].value);
    }
}

// Convert sparse matrix back to regular matrix
int** convertToRegular(SparseMatrix *sparse) {
    int **matrix = (int**)malloc(sparse->rows * sizeof(int*));
    for (int i = 0; i < sparse->rows; i++) {
        matrix[i] = (int*)calloc(sparse->cols, sizeof(int));
    }
    
    for (int i = 0; i < sparse->numNonZero; i++) {
        matrix[sparse->data[i].row][sparse->data[i].col] = sparse->data[i].value;
    }
    
    return matrix;
}

// Print regular matrix
void printMatrix(int **matrix, int rows, int cols) {
    printf("Regular Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows = 4, cols = 5;
    
    // Allocate and initialize matrix
    int **matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    
    // Initialize with sparse data
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }
    
    matrix[0][1] = 5;
    matrix[0][3] = 8;
    matrix[1][2] = 3;
    matrix[2][0] = 2;
    matrix[2][4] = 7;
    matrix[3][1] = 9;
    
    printf("Original Matrix:\n");
    printMatrix(matrix, rows, cols);
    printf("\n");
    
    // Convert to sparse
    SparseMatrix *sparse = convertToSparse(matrix, rows, cols);
    printSparseMatrix(sparse);
    printf("\n");
    
    // Convert back to regular
    int **reconstructed = convertToRegular(sparse);
    printf("Reconstructed Matrix:\n");
    printMatrix(reconstructed, rows, cols);
    
    // Free memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
        free(reconstructed[i]);
    }
    free(matrix);
    free(reconstructed);
    free(sparse->data);
    free(sparse);
    
    return 0;
}

