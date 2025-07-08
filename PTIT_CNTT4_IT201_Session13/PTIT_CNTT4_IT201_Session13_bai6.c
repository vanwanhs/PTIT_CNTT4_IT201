//
// Created by Hikari on 08/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    char *arr;
    int top;
    int cap;
} Stack;

Stack* createStack(int cap) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = (char*)malloc(sizeof(char) * cap);
    stack->top = -1;
    stack->cap = cap;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char c) {
    if (stack->top < stack->cap - 1) {
        stack->arr[++stack->top] = c;
    }
}

char pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top--];
    }
    return '\0';
}

void freeStack(Stack* stack) {
    free(stack->arr);
    free(stack);
}

int isPalindrome(char str[]) {
    int len = strlen(str);
    Stack* stack = createStack(len);

    for (int i = 0; i < len; i++) {
        push(stack, str[i]);
    }

    for (int i = 0; i < len; i++) {
        char c = pop(stack);
        if (str[i] != c) {
            freeStack(stack);
            return 0;
        }
    }

    freeStack(stack);
    return 1;
}

int main() {
    char str[1000];
    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);

    size_t len = strlen(str);
    if (str[len - 1] == '\n') str[len - 1] = '\0';

    if (isPalindrome(str)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}

