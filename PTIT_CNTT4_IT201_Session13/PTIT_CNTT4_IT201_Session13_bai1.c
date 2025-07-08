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

void freeStack(Stack* stack) {
    free(stack->arr);
    free(stack);
}

int main() {
    int n = 5;
    Stack* myStack = createStack(n);
    freeStack(myStack);
    return 0;
}
