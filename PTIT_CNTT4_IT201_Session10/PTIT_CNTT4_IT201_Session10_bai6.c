//
// Created by Hikari on 03/07/2025.
//

//
// Created by Hikari on 02/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Khong the cap phat bo nho\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void append(Node** headRef, int value) {
    Node* newNode = createNode(value);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    Node* cur = *headRef;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = newNode;
}

void printList(Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next)
            printf("->");
        head = head->next;
    }
    printf("->NULL\n");
}

void findMiddle(Node* head) {
    int count = 0;
    Node* cur = head;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }

    int middleIndex = count / 2 + 1;

    cur = head;
    int pos = 1;
    while (cur != NULL && pos < middleIndex) {
        cur = cur->next;
        pos++;
    }

    if (cur != NULL)
        printf("Node %d: %d\n", middleIndex, cur->data);
}

void freeList(Node* head) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    Node* head = NULL;
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);

    printf("Nhap cac phan tu: ");
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        append(&head, x);
    }

    printList(head);
    findMiddle(head);
    freeList(head);
    return 0;
}
