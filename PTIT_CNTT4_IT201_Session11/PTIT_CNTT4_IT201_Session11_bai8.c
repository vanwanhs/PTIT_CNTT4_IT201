#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int value);
void printList(Node* head);
int length(Node* head);
void deleteAt(Node** head, int pos);

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

    int pos;
    printf("\nNhap vi tri can xoa (bat dau tu 1): ");
    scanf("%d", &pos);

    deleteAt(&head, pos);

    printf("\nDanh sach sau khi xoa:\n");
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

void deleteAt(Node** head, int pos) {
    if (*head == NULL || pos <= 0) return;

    Node* cur = *head;
    int index = 1;

    if (pos == 1) {
        *head = cur->next;
        if (*head) (*head)->prev = NULL;
        free(cur);
        return;
    }

    while (cur != NULL && index < pos) {
        cur = cur->next;
        index++;
    }

    if (cur == NULL) return;
    if (cur->prev) cur->prev->next = cur->next;
    if (cur->next) cur->next->prev = cur->prev;

    free(cur);
}
