

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int* value;
    int rear;
    int front;
    int cap;

}Queue;

Queue* createQueue(int cap)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->cap = cap;
    queue->rear = -1;
    queue->front = 0;
    queue->value = (int*)malloc(sizeof(int) * cap);
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
    if (isFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->cap;
    queue->value[queue->rear] = value;
}
void displayQueue(Queue* queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }
    for (int i = 0; i <= queue->rear; i++)
    {
        printf("%d\n", queue->value[i]);
    }
}

int main()
{
    Queue* queue = createQueue(5);
    displayQueue( queue);

    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);

    displayQueue( queue);
    free(queue);

    return 0;
}