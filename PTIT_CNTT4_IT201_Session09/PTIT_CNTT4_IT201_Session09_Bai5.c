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

void insertHead(Node **headRef, int value) {
    Node *newNode = createNode(value);
    newNode->next = *headRef;
    *headRef = newNode;
}

void printList(Node *head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf("->");
        head = head->next;
    }
    printf("->NULL\n");
}

void freeList(Node *head) {
    while (head) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node *head = NULL;
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Khong hop le");
        return 0;
    }

    printf("Nhap cac phan tu: ");
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        append(&head, x);
    }

    printf("Danh sach ban dau: ");
    printList(head);

    int value;
    printf("Nhap gia tri can them vao dau: ");
    scanf("%d", &value);
    insertHead(&head, value);

    printf("Danh sach sau khi them: ");
    printList(head);

    freeList(head);
    return 0;
}
