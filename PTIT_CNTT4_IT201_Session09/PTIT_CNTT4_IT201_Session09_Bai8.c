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

void deleteAtPosition(Node **headRef, int position) {
    if (*headRef == NULL || position <= 0) {
        printf("Vi tri khong hop le\n");
        return;
    }

    Node *temp;

    if (position == 1) {
        temp = *headRef;
        *headRef = (*headRef)->next;
        free(temp);
        return;
    }

    Node *cur = *headRef;
    int index = 1;

    while (cur != NULL && index < position - 1) {
        cur = cur->next;
        index++;
    }

    if (cur == NULL || cur->next == NULL) {
        printf("Vi tri vuot qua do dai danh sach\n");
        return;
    }

    temp = cur->next;
    cur->next = temp->next;
    free(temp);
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

    int position;
    printf("Nhap vi tri muon xoa (bat dau tu 1): ");
    scanf("%d", &position);

    deleteAtPosition(&head, position);

    printf("Danh sach sau khi xoa: ");
    printList(head);

    freeList(head);
    return 0;
}
