//
// Created by Hikari on 08/07/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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

void push(Stack* stack, int value) {
    if (stack->top < stack->cap - 1) {
        stack->arr[++stack->top] = value;
    }
}

int pop(Stack* stack) {
    if (stack->top == -1) return 0;
    return stack->arr[stack->top--];
}

int evaluatePostfix(char expr[]) {
    int len = strlen(expr);
    Stack* stack = createStack(len);

    for (int i = 0; i < len; i++) {
        char c = expr[i];

        if (isdigit(c)) {
            push(stack, c - '0');
        } else {
            int b = pop(stack);
            int a = pop(stack);
            int res = 0;
            if (c == '+') res = a + b;
            else if (c == '-') res = a - b;
            else if (c == '*') res = a * b;
            else if (c == '/') res = a / b;
            push(stack, res);
        }
    }

    int result = pop(stack);
    free(stack->arr);
    free(stack);
    return result;
}

int main() {
    char expr[1000];
    printf("Nhap bieu thuc postfix: ");
    fgets(expr, sizeof(expr), stdin);

    size_t len = strlen(expr);
    if (expr[len - 1] == '\n') expr[len - 1] = '\0';

    int result = evaluatePostfix(expr);
    printf("%d\n", result);

    return 0;
}
