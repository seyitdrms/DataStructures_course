/*
 * Student Name: Seyithan Durmuş
 * Student Number: 1910213029
 * Course: CS1102 - Data Structures and Algorithms
 * Week 2 Homework: Big O Time Complexity Analysis
 */

#include <stdio.h>

// Algo1: Simple for loop
// Time Complexity: O(n)
void algo1(int n) {
    for (int i = 1; i <= n; i++) {
        printf("Hello World\n");
    }
    // Analysis: Loop runs n times, so O(n)
}

// Algo2: Nested for loop
// Time Complexity: O(n^2)
void algo2(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("Hello World\n");
        }
    }
    // Analysis: Outer loop runs n times, inner loop runs n times
    // Total: n * n = n^2, so O(n^2)
}

// Algo3: Loop with i = i * 2
// Time Complexity: O(log2 n)
void algo3(int n) {
    for (int i = 1; i < n; i = i * 2) {
        printf("Hello World\n");
    }
    // Analysis: i values: 1, 2, 4, 8, 16, ..., 2^k
    // When 2^k >= n, loop stops
    // k = log2(n), so O(log2 n)
}

// Algo4: Loop with i = i / 5
// Time Complexity: O(log5 n)
void algo4(int n) {
    for (int i = n; i >= 1; i = i / 5) {
        printf("Hello World\n");
    }
    // Analysis: i values: n, n/5, n/25, n/125, ..., 1
    // Number of iterations: log5(n), so O(log5 n)
}

// Algo5: Loop with i = i * 5 until i < n^3
// Time Complexity: O(log5 n^3) = O(3*log5 n) = O(log5 n)
void algo5(int n) {
    for (int i = 1; i < n * n * n; i = i * 5) {
        printf("Hello World\n");
    }
    // Analysis: i values: 1, 5, 25, 125, ..., 5^k
    // When 5^k >= n^3, loop stops
    // k = log5(n^3) = 3*log5(n), so O(log5 n^3) = O(log5 n)
}

// Algo6: Loop with i^2 <= n
// Time Complexity: O(sqrt(n))
void algo6(int n) {
    for (int i = 1; i * i <= n; i++) {
        printf("Hello World\n");
    }
    // Analysis: Condition: i^2 <= n
    // Therefore: i <= sqrt(n)
    // Loop runs sqrt(n) times, so O(sqrt(n))
}

// Algo7: While loop with k = k + i
// Time Complexity: O(sqrt(n))
void algo7(int n) {
    int i = 1, k = 1;
    while (k <= n) {
        i++;
        k = k + i;
        printf("Hello World\n");
    }
    // Analysis: k values: 1, 3, 6, 10, 15, ..., n
    // k = 1 + 2 + 3 + ... + i = i(i+1)/2
    // When i(i+1)/2 >= n, loop stops
    // i^2 ≈ 2n, so i ≈ sqrt(2n) = sqrt(2) * sqrt(n)
    // Therefore: O(sqrt(n))
}

int main() {
    int n = 16;
    
    printf("=== Big O Time Complexity Analysis ===\n\n");
    
    printf("Algo1: Simple for loop\n");
    printf("Time Complexity: O(n)\n");
    printf("For n = %d: ", n);
    algo1(n);
    printf("\n");
    
    printf("Algo2: Nested for loop\n");
    printf("Time Complexity: O(n^2)\n");
    printf("For n = %d: ", n);
    algo2(n);
    printf("\n");
    
    printf("Algo3: Loop with i = i * 2\n");
    printf("Time Complexity: O(log2 n)\n");
    printf("For n = %d: ", n);
    algo3(n);
    printf("\n");
    
    printf("Algo4: Loop with i = i / 5\n");
    printf("Time Complexity: O(log5 n)\n");
    printf("For n = %d: ", n);
    algo4(n);
    printf("\n");
    
    printf("Algo5: Loop with i = i * 5 until i < n^3\n");
    printf("Time Complexity: O(log5 n^3) = O(log5 n)\n");
    printf("For n = %d: ", n);
    algo5(n);
    printf("\n");
    
    printf("Algo6: Loop with i^2 <= n\n");
    printf("Time Complexity: O(sqrt(n))\n");
    printf("For n = %d: ", n);
    algo6(n);
    printf("\n");
    
    printf("Algo7: While loop with k = k + i\n");
    printf("Time Complexity: O(sqrt(n))\n");
    printf("For n = %d: ", n);
    algo7(n);
    printf("\n");
    
    return 0;
}

