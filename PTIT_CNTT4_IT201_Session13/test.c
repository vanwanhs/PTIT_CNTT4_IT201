//
// Created by Hikari on 08/07/2025.
//
#include <stdio.h>
#include <stdlib.h>


typedef struct Stack {
    int *arr;
    int top;
    int cap;
} Stack;

Stack* createStack(int cap) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = (int*)malloc(sizeof(int) * cap);
    stack->top = -1;
    stack->cap = cap;
    return stack;
}


int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == stack->cap - 1;
}

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        return;
    }
    stack->top++;
    stack->arr[stack->top] = value;
}


int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("No element in stack\n");
        return -1;
    }
    int popped = stack->arr[stack->top];
    stack->top--;
    return popped;
}

void printStack(Stack* stack) {
    printf("\nstack={\n    elements: [");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d", stack->arr[i]);
        if (i < stack->top) printf(", ");
    }
    printf("],\n    top: %d,\n    cap: %d\n}\n", stack->top, stack->cap);
}


void freeStack(Stack* stack) {
    free(stack->arr);
    free(stack);
}

