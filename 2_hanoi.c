/*
 * Student Name: Seyithan Durmuş
 * Student Number: 1910213029
 * Course: CS1102 - Data Structures and Algorithms
 */

#include <stdio.h>

// Tower of Hanoi recursive solution
void hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    
    // Move n-1 disks from source to auxiliary
    hanoi(n - 1, from_rod, aux_rod, to_rod);
    
    // Move the largest disk from source to destination
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    
    // Move n-1 disks from auxiliary to destination
    hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Number of disks must be positive!\n");
        return 1;
    }
    
    printf("\nTower of Hanoi solution for %d disks:\n", n);
    printf("A = Source, B = Auxiliary, C = Destination\n\n");
    
    hanoi(n, 'A', 'C', 'B');
    
    printf("\nTotal moves required: %d\n", (1 << n) - 1);
    
    return 0;
}

