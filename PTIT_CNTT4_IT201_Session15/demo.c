//
// Created by Hikari on 11/07/2025.
//


#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
};
Node *createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//
// // xây dựng cấu trúc dữ liệu hàng đợi
// typedef struct Queue {
//     int* array;
//     int front; // chi so cua phan tu dau tien de la 0
//     int rear;   // chi so cua phan tu cuoi cung de la -1
//     int capacity;
// }Queue;
//
// Queue *createQueue(int capacity) {
//     Queue *queue = (Queue*)malloc(sizeof(Queue));
//     queue->array = (int*)malloc(sizeof(int) * capacity);
//     queue->front = 0;
//     queue->rear = -1;
//     queue->capacity = capacity;
//     return queue;
// }
// // xay dung hang them vao hamg doi
// void enQueue(Queue* queue, int value) {
//     // Kiem tra hang doi (Mang khon gccon vi tri de them)
//     if (queue->rear == queue->capacity - 1) {
//         printf("Queue is full\n");
//         return;
//     }
//     // tang chi so rear len
//     queue->rear++;
//     // them gia tri vao vi tri rear
//     queue->array[queue->rear] = value;
// }
//
// // xay dung lay khoi hang doi
// void deQueue(Queue* queue) {
//     // kiem tra hang doi trong
//     if (queue->rear < queue ->front - 1) {
//         printf("Queue is empty\n");
//         return;
//     }
//     // tang gia tri cua rear len
//     queue->rear++;
// }
//
// // xay dung hang xem phan ut dau hang doi
// int getFront(Queue* queue) {
//     // kiem tra hang doij
//     if (queue->rear < queue->front) {
//         printf("Queue is empty\n");
//         return -1;
//     }
//     // tra ve phan tu co chi so la front
//     return queue->array[queue->rear];
// }
// // xay dung ham in toan bo hang doi
// void displayQueue(Queue* queue) {
//     if (queue->rear < queue->front) {
//         printf("Queue is empty\n");
//         return;
//     }
//     // hien thi toan bo phan tu hang doi theo kieu tu front den rear
//     for (int i = 0; i < queue->rear; i++) {
//         printf("%d ", queue->array[i]);
//     }
// }
typedef struct Queue {
    int front;
    int rear;
}Queue;
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}
// xay dung ham them phan tu vao hang
void enQueue(Queue* queue, int data) {
    //kiem tra tran bo nho
    //Kiem tra hang doi trong
}
int main() {
    Queue* queue = createQueue(5);
    return 0;
}
