//
// Created by Hikari on 14/07/2025.
//


#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct Queue {
    Node *rear;
    Node *front;
}Queue;
Queue *createQueue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->rear = NULL;
    queue->front = NULL;
    return queue;
}
int isQueueEmpty(Queue *queue) {
    if (queue->front == NULL) {
        return 1;
    }
}
int main() {

    return 0;
}
