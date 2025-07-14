//
// Created by Hikari on 09/07/2025.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

typedef struct Stack {
    Node* head;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
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
void push(Stack* stack, int value) {
    Node *newNode = createNode(value);
    if (newNode == NULL) {
        printf("stack is full\n");
    }
    newNode->next = stack->head;
    stack->head = newNode;
}
void pop(Stack* stack) {
    if (stack->head == NULL) {
        printf("stack is empty\n");
        return;
    }
    //b2: xoa node tren dinh ngan xep ( xoa node dau tren danh sach)
    Node *temp = stack->head;
    stack->head = stack->head->next;
    free(temp);
}
int peek(Stack* stack) {
    //b1: kiem tra ngan xep trong
    if (stack->head == NULL) {
        printf("stack is empty\n");
        return -1;
    }
    return stack->head->data;
}
int main() {
    Stack* myStack = createStack();
    if (myStack->head == NULL) {
        printf("Stack created with head = NULL\n");
    }

    freeStack(myStack);
    return 0;
}
