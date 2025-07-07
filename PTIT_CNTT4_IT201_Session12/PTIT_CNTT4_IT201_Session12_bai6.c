//
// Created by Hikari on 07/07/2025.
//

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

void findMiddleNode(Node* head) {
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    int middleIndex = count / 2;

    temp = head;
    for (int i = 0; i < middleIndex; i++) {
        temp = temp->next;
    }

    printf("Node %d: %d\n", middleIndex + 1, temp->data);
}
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main() {
    Node *n1 = createNode(5);
    Node *n2 = createNode(4);
    Node *n3 = createNode(3);
    Node *n4 = createNode(2);
    Node *n5 = createNode(1);
    Node *n6 = createNode(6);
    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    n4->next = n5; n5->prev = n4;
    n5->next = n6; n6->prev = n5;

    Node* head = n1;

    printList(head);
    findMiddleNode(head);
    freeList(head);

    return 0;
}

