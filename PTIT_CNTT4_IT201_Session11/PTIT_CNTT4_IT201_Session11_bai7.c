#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node*  createNode(int value);
void   printList(Node* head);
int    length(Node* head);
void   insertAt(Node** head, int value, int pos);


int main() {

    Node *n1 = createNode(1),
         *n2 = createNode(2),
         *n3 = createNode(3),
         *n4 = createNode(4),
         *n5 = createNode(5);
    n1->next = n2;

    n2->prev = n1; n2->next = n3;
    n3->prev = n2; n3->next = n4;
    n4->prev = n3; n4->next = n5;
    n5->prev = n4;

    Node* head = n1;

    printf("Danh sach ban dau:\n");
    printList(head);

    int value, pos;
    printf("\nNhap gia tri can chen: ");
    scanf("%d", &value);
    printf("Nhap vi tri can chen (bat dau tu 1): ");
    scanf("%d", &pos);

    if (value <= 0 || pos <= 0) {
        printf("Chi chap nhan so nguyen duong va vi tri >= 1.\n");
        return 0;
    }

    insertAt(&head, value, pos);

    printf("\nDanh sach sau khi chen:\n");
    printList(head);
    return 0;
}

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) exit(1);
    newNode->data = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    Node* cur = head;
    while (cur) {
        printf("%d", cur->data);
        if (cur->next) printf("<->");
        cur = cur->next;
    }
    printf("->NULL\n");
}

int length(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

void insertAt(Node** head, int value, int pos) {
    Node* newNode = createNode(value);

    if (*head == NULL || pos <= 1) {
        newNode->next = *head;
        if (*head) (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    int idx = 1;
    Node* cur = *head;
    while (cur->next && idx < pos - 1) {
        cur = cur->next;
        idx++;
    }

    newNode->next = cur->next;
    newNode->prev = cur;
    if (cur->next) cur->next->prev = newNode;
    cur->next = newNode;
}
