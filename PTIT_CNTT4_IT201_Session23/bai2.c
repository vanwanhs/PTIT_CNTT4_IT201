//
// Created by Hikari on 25/07/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

typedef struct Operation {
    char action;
    char value;
} Operation;

typedef struct Stack {
    Operation* data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = malloc(sizeof(Stack));
    stack->data = (Operation*)malloc(sizeof(Operation) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

void push(Stack* stack, Operation op) {
    if (isFull(stack)) {
        printf("Stack is full\n");
        return;
    }
    stack->data[++stack->top] = op;
}

Operation pop(Stack* stack) {
    if (isEmpty(stack)) {
        Operation empty = {'\0', '\0'};
        return empty;
    }
    return stack->data[stack->top--];
}

void insertChar(char* text, char ch, Stack* undoStack) {
    int len = strlen(text);
    if (len < MAX_LENGTH - 1) {
        text[len] = ch;
        text[len + 1] = '\0';
        push(undoStack, (Operation){'I', ch});
    } else {
        printf("Text is full!\n");
    }
}

void undo(char* text, Stack* undoStack, Stack* redoStack) {
    if (isEmpty(undoStack)) {
        printf("No operation to UNDO\n");
        return;
    }
    Operation last = pop(undoStack);
    if (last.action == 'I') {
        int len = strlen(text);
        if (len > 0) {
            text[len - 1] = '\0';
            push(redoStack, last);
        }
        printf("UNDO successful\n");
    }
}

void redo(char* text, Stack* redoStack, Stack* undoStack) {
    if (isEmpty(redoStack)) {
        printf("No operation to REDO\n");
        return;
    }
    Operation last = pop(redoStack);
    if (last.action == 'I') {
        insertChar(text, last.value, undoStack);
        printf("REDO successful\n");
    }
}

void printMenu() {
    printf("----------TEXT EDITOR----------\n");
    printf("1. INSERT\n");
    printf("2. UNDO\n");
    printf("3. REDO\n");
    printf("4. DISPLAY\n");
    printf("5. EXIT\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    char text[MAX_LENGTH] = "";
    Stack* undoStack = createStack(100);
    Stack* redoStack = createStack(100);

    do {
        printMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                char ch;
                printf("Enter a character to insert: ");
                getchar(); // To clear newline
                scanf("%c", &ch);
                insertChar(text, ch, undoStack);
                break;
            }
            case 2:
                undo(text, undoStack, redoStack);
                break;
            case 3:
                redo(text, redoStack, undoStack);
                break;
            case 4:
                printf("Current text: %s\n", text);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    free(undoStack->data);
    free(undoStack);
    free(redoStack->data);
    free(redoStack);
    return 0;
}

