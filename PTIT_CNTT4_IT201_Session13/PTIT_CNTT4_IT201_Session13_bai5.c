//
// Created by Hikari on 08/07/2025.
//

#include <stdio.h>
#include <stdlib.h>

// Cấu trúc Stack
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
    if (!isFull(stack)) {
        stack->arr[++stack->top] = value;
    }
}

int pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top--];
    }
    return -1;
}

void freeStack(Stack* stack) {
    free(stack->arr);
    free(stack);
}

void printArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) printf(", ");
    }
    printf("]\n");
}

void reverseArray(int arr[], int n) {
    Stack* stack = createStack(n);

    for (int i = 0; i < n; i++) {
        push(stack, arr[i]);
    }

    for (int i = 0; i < n; i++) {
        arr[i] = pop(stack);
    }

    freeStack(stack);
}

// MAIN
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nmang ban dau:\n");
    printArray(arr, n);

    reverseArray(arr, n);

    printf("\nMang sau khi dao nguoc:\n");
    printArray(arr, n);

    return 0;
}
