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

void printList(Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf(" <-> ");
        head = head->next;
    }
    printf(" -> NULL\n");
}
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

Node* deleteByValue(Node* head, int target) {
    Node* curr = head;
    while (curr != NULL) {
        if (curr->data == target) {
            Node* toDelete = curr;
            if (curr->prev == NULL) {
                head = curr->next;
                if (head != NULL)
                    head->prev = NULL;
            } else {
                curr->prev->next = curr->next;
                if (curr->next != NULL)
                    curr->next->prev = curr->prev;
            }
            curr = curr->next;
            free(toDelete);
        } else {
            curr = curr->next;
        }
    }
    return head;
}

int main() {
    Node *n1 = createNode(5);
    Node *n2 = createNode(4);
    Node *n3 = createNode(3);
    Node *n4 = createNode(5);
    Node *n5 = createNode(2);
    Node *n6 = createNode(1);
    Node *n7 = createNode(5);

    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    n4->next = n5; n5->prev = n4;
    n5->next = n6; n6->prev = n5;
    n6->next = n7; n7->prev = n6;

    Node* head = n1;

    printf("Original list:\n");
    printList(head);

    int x;
    printf("Enter the value to delete: ");
    scanf("%d", &x);

    head = deleteByValue(head, x);

    printf("List after deleting %d:\n", x);
    printList(head);
    freeList(head);
    return 0;
}
