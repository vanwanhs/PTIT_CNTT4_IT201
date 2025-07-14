
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


int main()
{
    Queue* queue = createQueue(5);
    if (isEmpty(queue)) printf("true\n");
    else printf("false\n");

    enQueue(queue, 1);

    if (isEmpty(queue)) printf("true\n");
    else printf("false\n");
    free(queue);

    return 0;
}