
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

void printfQueue(Queue* queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
    }else printf("return value = 1\n");
    printf("array=[");
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d, ", queue->value[i]);
    }
    printf("]");
    printf("\n");
    printf("front = %d\n", queue->front);
    printf("rear = %d\n", queue->rear);
    printf("capacity = %d\n", queue->cap);
}
int main()
{
    Queue* queue = createQueue(5);
    printf("truong hop 1\n");
    printfQueue( queue);
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    printf("\n");
    printf("truong hop 2\n");
    printfQueue(queue);
    free(queue);

    return 0;
}