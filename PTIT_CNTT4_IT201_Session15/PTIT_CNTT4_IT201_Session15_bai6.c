
#include <stdio.h>
#include <stdlib.h>


typedef struct Queue
{
    int *value;
    int front,rear,cap;
}Queue;

Queue *createQueue(int value)
{
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->value = (int*)malloc(sizeof(int)*value);
    queue->front = 0;
    queue->rear = -1;
    queue->cap = value;
}

int isFull(Queue *queue)
{
    if (queue->rear == queue->cap - 1);
}
int isEmpty(Queue *queue)
{
    return queue->rear < queue->front;
}

void enQueue(Queue *queue, int value)
{
    if (isFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->cap;
    queue->value[queue->rear] = value;
}
int isIncreasing(Queue *queue)
{
    if (!isEmpty(queue)) return 0;
    int value=queue->value[queue->front];
    for (int i = queue->front; i <= queue->rear; i++)
    {
        if (value+1!=queue->value[i]) return 0;
    }
    return 1;
}

int main()
{
    int n,value;
    printf("n= ");
    scanf("%d",&n);
    Queue *queue = createQueue(n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&value);
    }
    if (isIncreasing(queue)) printf("true\n");
    else printf("false\n");
    free(queue);
    return 0;
}