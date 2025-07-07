//
// Created by Hikari on 07/07/2025.
//


#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
Node *createNode (int value) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}
void print(Node *head) {
    if (head == NULL) {
        return;
    }
    while (head != NULL) {
        printf("%d", head -> data);
        head = head -> next;
    }
}
Node *deleteAtEnd(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    if (head -> next == NULL) {
        free(head);
        return NULL;
    }
    Node *temp = head;
    while (temp -> next != NULL) {
        temp = temp -> next;
    }
    temp -> prev -> next = NULL;
    free(temp);
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
    Node *n1 = createNode(1);
    Node *n2 = createNode(2);
    Node *n3 = createNode(3);
    Node *n4 = createNode(4);
    Node *n5 = createNode(5);
    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    n4->next = n5; n5->prev = n4;
    Node *head = n1;
    print(head);
    printf("\n");
    deleteAtEnd(head);
    print(head);
    freeList(head);
    return 0;
}
