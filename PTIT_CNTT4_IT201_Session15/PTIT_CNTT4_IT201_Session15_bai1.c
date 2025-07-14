
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
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->cap = capacity;
    queue->rear = -1;
    queue->front = 0;
    queue->value = (int*)malloc(sizeof(int) * capacity);
    if (!queue->value) {
        free(queue);
        return NULL;
    }
    return queue;
}


int isFull(Queue* queue)
{
    return queue->rear == queue->cap - 1;
}

int isEmpty(Queue* queue)
{
    return queue->front > queue->rear;
}

void enQueue(Queue* queue, int value)
{
    if (isFull(queue)) return;
    queue->rear++;
    queue->value[queue->rear] = value;

}
void deQueue(Queue* queue)
{
    if (isEmpty(queue)) return;
    queue->front++;
}
int getFront(Queue* queue)
{
    if (isEmpty(queue)) return -1;
    return queue->value[queue->front];
}

void printQueue(Queue* queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d ", queue->value[i]);
    }
}

int main()
{

    return 0;
}