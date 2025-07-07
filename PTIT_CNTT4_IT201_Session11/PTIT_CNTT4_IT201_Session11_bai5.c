#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int value);
void printList(Node* head);
void addToHead(Node** head, int value);

int main() {
    Node* n1 = createNode(1);
    Node* n2 = createNode(2);
    Node* n3 = createNode(3);
    Node* n4 = createNode(4);
    Node* n5 = createNode(5);

    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;
    n4->next = n5;
    n5->prev = n4;

    Node* head = n1;

    printf("Danh sach truoc khi them:\n");
    printList(head);

    int x;
    printf("Nhap so nguyen duong can them vao dau danh sach: ");
    scanf("%d", &x);

    if (x > 0) {
        addToHead(&head, x);
        printf("Danh sach sau khi them:\n");
        printList(head);
    } else {
        printf("Chi nhap so nguyen duong.\n");
    }

    return 0;
}

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL)
            printf("<->");
        current = current->next;
    }
    printf("->NULL\n");
}

void addToHead(Node** head, int value) {
    Node* newNode = createNode(value);
    newNode->next = *head;
    if (*head != NULL)
        (*head)->prev = newNode;
    *head = newNode;
}
