/*
 * Student Name: Seyithan Durmuş
 * Student Number: 1910213029
 * Course: CS1102 - Data Structures and Algorithms
 * Week 5 Homework: Shunting Yard Algorithm - Infix to Postfix
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

// Print step-by-step conversion
void printConversion(char *infix) {
    printf("Infix Expression: %s\n", infix);
    
    char postfix[MAX];
    infixToPostfix(infix, postfix);
    
    printf("Postfix Expression: %s\n", postfix);
    
    // Show the conversion process
    printf("\nConversion Process:\n");
    printf("1. Read operands and add directly to output\n");
    printf("2. Push operators to stack based on precedence\n");
    printf("3. Pop operators when encountering lower precedence or ')'\n");
    printf("4. Pop all remaining operators at the end\n\n");
}

int main() {
    printf("=== Shunting Yard Algorithm - Infix to Postfix Conversion ===\n\n");
    
    // Example 1: a*b+c
    printf("Example 1: a*b+c\n");
    printf("----------------------------------------\n");
    printConversion("a*b+c");
    
    printf("Step-by-step for 'a*b+c':\n");
    printf("  Input: a  -> Output: a\n");
    printf("  Input: *  -> Stack: *\n");
    printf("  Input: b  -> Output: ab\n");
    printf("  Input: +  -> Pop *, Output: ab*, Stack: +\n");
    printf("  Input: c  -> Output: ab*c\n");
    printf("  End    -> Pop +, Output: ab*c+\n");
    printf("  Final: ab*c+\n\n");
    
    // Example 2: (a+b)*c
    printf("Example 2: (a+b)*c\n");
    printf("----------------------------------------\n");
    printConversion("(a+b)*c");
    
    printf("Step-by-step for '(a+b)*c':\n");
    printf("  Input: (  -> Stack: (\n");
    printf("  Input: a  -> Output: a\n");
    printf("  Input: +  -> Stack: ( +\n");
    printf("  Input: b  -> Output: ab\n");
    printf("  Input: )  -> Pop +, Output: ab+, Pop (\n");
    printf("  Input: *  -> Stack: *\n");
    printf("  Input: c  -> Output: ab+c\n");
    printf("  End    -> Pop *, Output: ab+c*\n");
    printf("  Final: ab+c*\n\n");
    
    // Additional examples
    printf("Additional Examples:\n");
    printf("----------------------------------------\n");
    
    char examples[][50] = {
        "a+b*c",
        "a*b+c*d",
        "(a+b)*(c+d)",
        "a+b-c*d"
    };
    
    for (int i = 0; i < 4; i++) {
        char postfix[MAX];
        infixToPostfix(examples[i], postfix);
        printf("Infix:   %s\n", examples[i]);
        printf("Postfix: %s\n\n", postfix);
    }
    
    return 0;
}

