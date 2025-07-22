//
// Created by Hikari on 22/07/2025.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

typedef struct Queue {
    Node** arr;     // con trỏ cấp 2
    int front, rear, capacity;
} Queue;

void initQueue(Queue* q, int capacity) {
    q->arr = (Node**)malloc(sizeof(Node*) * capacity);
    q->capacity = capacity;
    q->front = q->rear = 0;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, Node* node) {
    if (q->rear == q->capacity) {
        printf("Queue full!\n");
        return;
    }
    q->arr[q->rear++] = node;
}

Node* dequeue(Queue* q) {
    if (isEmpty(q)) return NULL;
    return q->arr[q->front++];
}

void freeQueue(Queue* q) {
    free(q->arr);
}

void addValue(Node* root, int value) {
    Queue q;
    initQueue(&q, 100);

    enqueue(&q, root);

    while (!isEmpty(&q)) {
        Node* current = dequeue(&q);

        if (current->left == NULL) {
            current->left = createNode(value);
            break;
        } else {
            enqueue(&q, current->left);
        }

        if (current->right == NULL) {
            current->right = createNode(value);
            break;
        } else {
            enqueue(&q, current->right);
        }
    }

    freeQueue(&q);
}

int countLeaves(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

void printLevelOrder(Node* root) {
    Queue q;
    initQueue(&q, 100);

    enqueue(&q, root);

    while (!isEmpty(&q)) {
        Node* current = dequeue(&q);
        printf("%d ", current->data);

        if (current->left) enqueue(&q, current->left);
        if (current->right) enqueue(&q, current->right);
    }

    freeQueue(&q);
}

int main() {
    Node* root = createNode(2);
    addValue(root, 3);
    addValue(root, 4);
    addValue(root, 5);

    printf("Level-order: ");
    printLevelOrder(root);
    printf("\n");

    printf("number of leaves: %d\n", countLeaves(root));

    return 0;
}
