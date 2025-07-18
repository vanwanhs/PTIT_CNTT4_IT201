#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char text[100];
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

void initStack(Stack* stack) {
    stack->top = NULL;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, const char* text) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->text, text);
    newNode->next = stack->top;
    stack->top = newNode;
}

char* pop(Stack* stack) {
    if (isEmpty(stack)) return NULL;
    Node* temp = stack->top;
    stack->top = temp->next;

    char* result = (char*)malloc(strlen(temp->text) + 1);
    strcpy(result, temp->text);
    free(temp);
    return result;
}

void clearStack(Stack* stack) {
    while (!isEmpty(stack)) {
        Node* temp = stack->top;
        stack->top = temp->next;
        free(temp);
    }
}

void displayClipboard(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Clipboard empty!\n");
        return;
    }
    printf("=== Clipboard ===\n");
    Node* curr = stack->top;
    while (curr != NULL) {
        printf("- %s\n", curr->text);
        curr = curr->next;
    }
    printf("=================\n");
}

int main() {
    Stack clipboard, redo;
    initStack(&clipboard);
    initStack(&redo);

    int choice;
    char text[100];

    do {
        printf("\n............CLIPBOARD MANAGER............\n");
        printf("1. COPY\n");
        printf("2. PASTE\n");
        printf("3. UNDO\n");
        printf("4. REDO\n");
        printf("5. DISPLAY\n");
        printf("6. EXIT\n");
        printf("=>>CHOICE: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("ENTER COPY: ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = '\0';
                push(&clipboard, text);
                clearStack(&redo);
                printf("Copy cussesfully.\n");
                break;
            case 2:
                if (!isEmpty(&clipboard))
                    printf("PASTE: %s\n", clipboard.top->text);
                else
                    printf("Clipboard empty!\n");
                break;
            case 3: {
                char* undone = pop(&clipboard);
                if (undone) {
                    push(&redo, undone);
                    printf("UNDO: %s\n", undone);
                    free(undone);
                } else {
                    printf("Empty.\n");
                }
                break;
            }
            case 4: {
                char* redone = pop(&redo);
                if (redone) {
                    push(&clipboard, redone);
                    printf("REDO: %s\n", redone);
                    free(redone);
                } else {
                    printf("Empty.\n");
                }
                break;
            }
            case 5:
                displayClipboard(&clipboard);
                break;
            case 6:
                printf("Exit.\n");
                break;
            default:
                printf("Invalidate Input.\n");
        }

    } while (choice != 6);

    clearStack(&clipboard);
    clearStack(&redo);
    return 0;
}
