//
// Created by Hikari on 02/07/2025.
//


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void searchNode(Node *head, int key) {
    while (head != NULL) {
        if (head->data == key) {
            printf("Tim thay: %d\n", key);
            return;
        }
        head = head->next;
    }
    printf("Khong tim thay\n");
}

int main() {
    Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    searchNode(head, 3);
    searchNode(head, 10);

    return 0;
}

