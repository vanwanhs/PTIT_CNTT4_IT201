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

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = (int*)malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->cap = capacity;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int value) {
    if (stack->top < stack->cap - 1) {
        stack->arr[++stack->top] = value;
    }
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("No element in stack\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

void printStack(Stack* stack) {
    printf("stack={\n    elements: [");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d", stack->arr[i]);
        if (i < stack->top) printf(", ");
    }
    printf("],\n    top: %d,\n    cap: %d\n}\n", stack->top, stack->cap);
}

void viewStack(Stack* stack) {
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->arr[i]);
    }
}

void freeStack(Stack* stack) {
    free(stack->arr);
    free(stack);
}

int main() {
    Stack* stack = createStack(5);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);

    printStack(stack);

    printf("\n");
    viewStack(stack);

    freeStack(stack);
    return 0;
}
