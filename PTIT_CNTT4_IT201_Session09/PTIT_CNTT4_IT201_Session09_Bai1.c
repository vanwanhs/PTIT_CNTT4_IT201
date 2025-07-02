





//
// Created by Hikari on 02/07/2025.
//


#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
}Node;
Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode ->data = value;
    newNode ->next = NULL;
    return newNode;
}

void printfList(Node *head) {
    printf("Danh sach lien ket\n");
    int count = 0;
    while (head != NULL) {
        count++;
        printf("node %d : %d\n",count,head -> data);
        head = head -> next;
    }
}
int main() {
    Node *head = NULL;
    Node *node1 = createNode(1);
    Node *node2 = createNode(2);
    Node *node3 = createNode(3);
    Node *node4 = createNode(4);
    Node *node5 = createNode(5);

    head = node1;
    node1 -> next  = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;
    printfList(head);
    return 0;
}
