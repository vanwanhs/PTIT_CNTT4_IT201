#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int* value;
    int front;
    int rear;
    int cap;
}Queue;

Queue* createQueue(int capacity)
{
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->value = (int*)malloc(sizeof(int) * capacity);
    newQueue->front = 0;
    newQueue->rear = -1;
    newQueue->cap = capacity;
    return newQueue;
}

int isEmpty(Queue* queue)
{
    return queue->front > queue->rear;
}

int isFull(Queue* queue)
{
    return queue->rear == queue->cap - 1;
}

void enQueue(Queue* queue, int value)
{
    if (isFull(queue))
    {
        printf("queue is full\n");
        return;
    }
    queue->rear++;
    queue->value[queue->rear] = value;
}
void deQueue(Queue* queue)
{
    if (isEmpty(queue)) return;
    queue->rear--;
    queue->front++;
}
void displayQueue(Queue* queue)
{
    if (isEmpty(queue)) return;
    printf("Queue= ");
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d, ", queue->value[i]);
    }
    printf("\n");
    printf("front = %d\n", queue->front);
    printf("rear = %d\n", queue->rear);
    printf("capacity = %d\n", queue->cap);
}
int main()
{
    int number;
    printf("number= ");
    scanf("%d", &number);
    Queue* queue = createQueue(number);
    enQueue(queue, number);
    displayQueue(queue);
    free(queue);
    return 0;
}