#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data  = value;
    newNode->next  = NULL;
    newNode->prev  = NULL;
    return newNode;
}

void printList(Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" <-> ");
        head = head->next;
    }
    printf(" -> NULL\n");
}

void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

Node* addAtEnd(Node* head, int value) {
    Node* newNode = createNode(value);
    if (!head) return newNode;

    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node* deleteByValue(Node* head, int target) {
    Node* curr = head;
    while (curr) {
        if (curr->data == target) {
            Node* toDelete = curr;
            if (!curr->prev) {
                head = curr->next;
                if (head) head->prev = NULL;
            } else {
                curr->prev->next = curr->next;
                if (curr->next) curr->next->prev = curr->prev;
            }
            curr = curr->next;
            free(toDelete);
        } else {
            curr = curr->next;
        }
    }
    return head;
}

int main(void) {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size!\n");
        return 1;
    }

    Node* head = NULL;
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; ++i) {
        int val;
        scanf("%d", &val);
        head = addAtEnd(head, val);
    }

    printf("\nOriginal list:\n");
    printList(head);

    int x;
    printf("\nEnter the value to delete: ");
    scanf("%d", &x);

    head = deleteByValue(head, x);

    printf("\nList after deleting %d:\n", x);
    printList(head);

    freeList(head);
    return 0;
}
