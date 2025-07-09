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
    printf("stack={\n  ");
    Node* current = stack->head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) printf("->");
        current = current->next;
    }
    printf("->NULL\n}\n");
}

void viewStack(Stack* stack) {
    Node* current = stack->head;
    if (current == NULL) {
        printf("Ngan xep trong\n");
        return;
    }
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
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

    int value;
    printf("\nNhap gia tri them: ");
    scanf("%d", &value);
    push(stack, value);

    printf("\nDuyet ngan xep:\n");
    viewStack(stack);

    Stack* emptyStack = createStack();
    printf("\nDuyet ngan xep rong:\n");
    viewStack(emptyStack);

    freeStack(stack);
    freeStack(emptyStack);
    return 0;
}
