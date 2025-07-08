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

void push(Stack* stack, char c) {
    if (stack->top < stack->cap - 1) {
        stack->arr[++stack->top] = c;
    }
}

char pop(Stack* stack) {
    if (stack->top == -1) return '\0';
    return stack->arr[stack->top--];
}

char peek(Stack* stack) {
    if (stack->top == -1) return '\0';
    return stack->arr[stack->top];
}

int isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int isValidBrackets(char expr[]) {
    int len = strlen(expr);
    Stack* stack = createStack(len);

    for (int i = 0; i < len; i++) {
        char c = expr[i];
        if (c == '(' || c == '[' || c == '{') {
            push(stack, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stack->top == -1 || !isMatching(peek(stack), c)) {
                free(stack->arr);
                free(stack);
                return 0;
            }
            pop(stack);
        }
    }

    int result = (stack->top == -1);
    free(stack->arr);
    free(stack);
    return result;
}

int main() {
    char expr[1000];
    printf("Nhap bieu thuc: ");
    fgets(expr, sizeof(expr), stdin);
    size_t len = strlen(expr);
    if (expr[len - 1] == '\n') expr[len - 1] = '\0';

    if (isValidBrackets(expr)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
