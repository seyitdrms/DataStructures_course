/*
 * Student Name: Seyithan Durmuş
 * Student Number: 1910213029
 * Course: CS1102 - Data Structures and Algorithms
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure
typedef struct {
    char data[MAX];
    int top;
} Stack;

// Initialize stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Push element to stack
void push(Stack *s, char item) {
    if (isFull(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->data[++s->top] = item;
}

// Pop element from stack
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        return '\0';
    }
    return s->data[s->top--];
}

// Peek top element
char peek(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->data[s->top];
}

// Get precedence of operator
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Check if character is operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Shunting Yard Algorithm - Infix to Postfix
void infixToPostfix(char *infix, char *postfix) {
    Stack stack;
    initStack(&stack);
    
    int i = 0, j = 0;
    int len = strlen(infix);
    
    while (i < len) {
        char ch = infix[i];
        
        // If operand, add to output
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // If left parenthesis, push to stack
        else if (ch == '(') {
            push(&stack, ch);
        }
        // If right parenthesis, pop until left parenthesis
        else if (ch == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Remove '('
        }
        // If operator
        else if (isOperator(ch)) {
            while (!isEmpty(&stack) && 
                   peek(&stack) != '(' && 
                   precedence(peek(&stack)) >= precedence(ch)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, ch);
        }
        
        i++;
    }
    
    // Pop remaining operators
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }
    
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    
    printf("Infix:   %s\n", infix);
    printf("Postfix: %s\n", postfix);
    
    return 0;
}

