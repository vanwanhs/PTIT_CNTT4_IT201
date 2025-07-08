//
// Created by Hikari on 08/07/2025.
//

#include <stdio.h>
#include <stdlib.h>

// Cấu trúc ngăn xếp
typedef struct Stack {
    int *arr;
    int top;
    int cap;
} Stack;

Stack *createStack(int cap) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->arr = (int *)malloc(sizeof(int) * cap);
    stack->top = -1;
    stack->cap = cap;
    return stack;
}


int isFull(Stack *stack) {
    return (stack->top == stack->cap - 1);
}


void push(Stack *stack, int value) {
    if (isFull(stack)) {
        return;
    }
    stack->top++;
    stack->arr[stack->top] = value;
}


void printStack(Stack *stack) {
    printf("\nstack={\n    elements: [");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d", stack->arr[i]);
        if (i < stack->top) printf(", ");
    }
    printf("],\n    top: %d,\n    cap: %d\n}\n", stack->top, stack->cap);
}

void freeStack(Stack *stack) {
    free(stack->arr);
    free(stack);
}

int main() {
    int cap = 5;
    Stack *stack = createStack(cap);
    int value;

    printf("Nhap cac phan tu:\n");

    for (int i = 0; i < cap; i++) {
        scanf("%d", &value);
        push(stack, value);
    }

    printStack(stack);
    freeStack(stack);
    return 0;
}
