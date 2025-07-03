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
    struct Node *next;
} Node;

Node* createNode(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Khong the cap phat bo nho\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void append(Node **headRef, int value) {
    Node *newNode = createNode(value);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    Node *cur = *headRef;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = newNode;
}

void deleteByValue(Node **headRef, int value) {
    while (*headRef && (*headRef)->data == value) {
        Node *tmp = *headRef;
        *headRef = (*headRef)->next;
        free(tmp);
    }
    Node *cur = *headRef;
    while (cur && cur->next) {
        if (cur->next->data == value) {
            Node *tmp = cur->next;
            cur->next = cur->next->next;
            free(tmp);
        } else {
            cur = cur->next;
        }
    }
}

void printList(Node *head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf("->");
        head = head->next;
    }
    printf("->NULL\n");
}

void freeList(Node *head) {
    while (head) {
        Node *tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    Node *head = NULL;
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

    int target;
    printf("Nhap gia tri can xoa: ");
    scanf("%d", &target);

    if (target > 0) {
        deleteByValue(&head, target);
        printf("Danh sach sau khi xoa: ");
        printList(head);
    } else {
        printf("Gia tri khong hop le\n");
    }

    freeList(head);
    return 0;
}
