//
// Created by Hikari on 14/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Không thể cấp phát bộ nhớ.\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}
int isEmpty(Queue* q) {
    return (q->front == NULL);
}
Node* createNode() {
    int value;
    printf("Nhap so nguyen: ");
    scanf("%d", &value);

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Queue* q) {
    Node* newNode = createNode();

    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}
void printQueue(Queue* q) {
    Node* current = q->front;
    printf("queue = {\n  front->");
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n  rear->");

    if (q->rear != NULL) {
        printf("%d->NULL\n", q->rear->data);
    } else {
        printf("NULL\n");
    }
    printf("},\n");
}

void peekFront(Queue* q) {
    if (isEmpty(q)) {
        printf("queue is empty\n");
    } else {
        printf("%d\n", q->front->data);
    }
}
int main() {
    Queue* q = createQueue();
    printQueue(q);
    peekFront(q);
    enqueue(q);
    enqueue(q);
    enqueue(q);

    printQueue(q);
    peekFront(q);

    return 0;
}
