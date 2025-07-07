#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node* addAtEnd(Node* head, int value) {
    Node* newNode = createNode(value);
    if (head == NULL) return newNode;
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

void printList(Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" <-> ");
        head = head->next;
    }
    printf(" -> NULL\n");
}

void sortList(Node* head) {
    if (!head) return;
    for (Node* i = head; i; i = i->next)
        for (Node* j = i->next; j; j = j->next)
            if (i->data > j->data) {
                int t = i->data;
                i->data = j->data;
                j->data = t;
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
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    Node* head = NULL;
    for (int i = 0; i < n; ++i) {
        int v;
        scanf("%d", &v);
        head = addAtEnd(head, v);
    }
    printf("Before sorting:\n");
    printList(head);
    sortList(head);
    printf("After sorting:\n");
    printList(head);
    freeList(head);
    return 0;
}
