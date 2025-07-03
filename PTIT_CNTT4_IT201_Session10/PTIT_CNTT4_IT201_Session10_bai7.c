//
// Created by Hikari on 03/07/2025.
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

void sortList(Node* head) {
    if (head == NULL) return;
    Node* i, *j;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                int tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
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
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("So khong hop le\n");
        return 1;
    }

    printf("Nhap cac phan tu: ");
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        append(&head, x);
    }

    printf("Danh sach ban dau: ");
    printList(head);

    sortList(head);

    printf("Danh sach sau khi sap xep tang dan: ");
    printList(head);

    freeList(head);
    return 0;
}
