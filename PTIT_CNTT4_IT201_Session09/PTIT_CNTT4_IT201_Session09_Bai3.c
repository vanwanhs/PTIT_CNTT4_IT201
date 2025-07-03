#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        perror("Malloc failed");
        exit(EXIT_FAILURE);
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

void searchNode(Node *head, int key) {
    while (head != NULL) {
        if (head->data == key) {
            printf("Tim thay %d\n", key);
            return;
        }
        head = head->next;
    }
    printf("Khong tim thay %d\n", key);
}

void printList(Node *head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) {
            printf(" ");
        }
        head = head->next;
    }
    printf("\n");
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
        int value;
        scanf("%d", &value);
        append(&head, value);
    }

    printf("Danh sach: ");
    printList(head);

    int key;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &key);
    searchNode(head, key);

    freeList(head);
    return 0;
}
