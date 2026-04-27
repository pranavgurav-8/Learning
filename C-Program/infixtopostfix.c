#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

// Structure for a stack node
struct StackNode {
    char data;
    struct StackNode* next;
};

// Function to create a new stack node
struct StackNode* createNode(char data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
int isEmpty(struct StackNode* root) {
    return (root == NULL);
}

// Function to push an element onto the stack
void push(struct StackNode** root, char data) {
    struct StackNode* newNode = createNode(data);
    newNode->next = *root;
    *root = newNode;
}

// Function to pop an element from the stack
char pop(struct StackNode** root) {
    if (isEmpty(*root)) {
        printf("Stack is empty. Cannot pop.\n");
        exit(EXIT_FAILURE);
    }
    struct StackNode* temp = *root;
    char data = temp->data;
    *root = temp->next;
    free(temp);
    return data;
}

// Function to get the top element of the stack without popping it
char peek(struct StackNode* root) {
    if (isEmpty(root)) {
        return '\0';
    }
    return root->data;
}

// Function to determine the precedence of an operator
int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return 0;
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char* infix, char* postfix) {
    struct StackNode* stack = NULL;
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // If the character is an operand, add it to the postfix expression
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            // If the character is an opening parenthesis, push it onto the stack
            push(&stack, ch);
        } else if (ch == ')') {
            // If the character is a closing parenthesis, pop from the stack and add to postfix until an opening parenthesis is found
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(stack) && peek(stack) == '(') {
                pop(&stack); // Pop the opening parenthesis from the stack
            }
        } else {
            // If the character is an operator, pop operators from the stack and add to postfix until the stack is empty or the operator at the top has lower precedence
            while (!isEmpty(stack) && getPrecedence(peek(stack)) >= getPrecedence(ch)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, ch); // Push the current operator onto the stack
        }
    }

    // Pop any remaining operators from the stack and add to postfix
    while (!isEmpty(stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[] = "a+b*(c-d)";
    char postfix[100];

    infixToPostfix(infix, postfix);
    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
