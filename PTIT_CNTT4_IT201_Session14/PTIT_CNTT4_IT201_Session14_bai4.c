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

int pop(Stack* stack) {
    if (stack->head == NULL) {
        printf("Ngan xep trong\n");
        return -1;
    }

    Node* temp = stack->head;
    int value = temp->data;
    stack->head = stack->head->next;
    free(temp);
    return value;
}

void printStack(Stack* stack) {
    printf("stack={\n  ");
    Node* current = stack->head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL)
            printf("->");
        current = current->next;
    }
    printf("->NULL\n}\n");
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

    push(stack, 5);
    push(stack, 4);
    push(stack, 3);
    push(stack, 2);
    push(stack, 1);

    printStack(stack);

    int popped = pop(stack);
    if (popped != -1) {
        printf("Da lay ra: %d\n", popped);
    }

    printStack(stack);
    while (pop(stack) != -1);
    pop(stack);
    freeStack(stack);
    return 0;
}
