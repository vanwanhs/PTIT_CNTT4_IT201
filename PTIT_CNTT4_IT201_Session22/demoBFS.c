//
// Created by Hikari on 24/07/2025.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct Graph {
    int V;
    int **matrix;
}Graph;
typedef struct Queue {
    int **array;
    int front;
    int rear;
    int capacity;
}Queue;
Queue *createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->array = (int **)malloc(queue->capacity * sizeof(int *));
    for (int i = 0; i < queue->capacity; i++) {
        queue->array[i] = (int *)malloc(queue->capacity * sizeof(int));
    }
}
int main() {

    return 0;
}
