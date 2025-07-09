//
// Created by Hikari on 09/07/2025.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* head;
} Stack;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}

void push(Stack* stack, int value) {
    Node* newNode = createNode(value);
    newNode->next = stack->head;
    stack->head = newNode;
}

void printStack(Stack* stack) {
    printf("stack ={\n   ");
    Node* current = stack->head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n}\n");
}

void freeStack(Stack* stack) {
    Node* current = stack->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(stack);
}

int main() {
    Stack* stack = createStack();

    printStack(stack);

    int value;
    printf("Nhap so nguyen duong: ");
    scanf("%d", &value);

    if (value > 0) {
        push(stack, value);
    }

    printStack(stack);
    push(stack, 7);
    printStack(stack);

    freeStack(stack);
    return 0;
}

