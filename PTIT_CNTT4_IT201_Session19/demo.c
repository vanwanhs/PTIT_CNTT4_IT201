
//
// Created by Hikari on 21/07/2025.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node *createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preorderDFS(Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorderDFS(root->left);
    preorderDFS(root->right);
}

void inorderDFS(Node *root) {
    if (root == NULL) {
        return;
    }
    inorderDFS(root->left);
    printf("%d ", root->data);
    inorderDFS(root->right);
}

void postorderDFS(Node *root) {
    if (root == NULL) {
        return;
    }
    postorderDFS(root->left);
    postorderDFS(root->right);
    printf("%d ", root->data);
}

// Cấu trúc hàng đợi
typedef struct Queue {
    Node **arr;
    int front;
    int rear;
    int capacity;
} Queue;

Queue *createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->arr = (Node **)malloc(sizeof(Node *) * capacity);
    for (int i = 0; i < capacity; i++) {
        queue->arr[i] = NULL;
    }
    queue->front = 0;
    queue->rear = 0;
    queue->capacity = capacity;
    return queue;
}

int isEmpty(Queue *queue) {
    return queue->front == queue->rear;
}

int isFull(Queue *queue) {
    return queue->rear == queue->capacity;
}

void enqueue(Queue *queue, Node *node) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->arr[queue->rear++] = node;
}

Node *dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        return NULL;
    }
    return queue->arr[queue->front++];
}

void levelorderBFS(Node *root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    Queue *queue = createQueue(100);
    enqueue(queue, root);

    while (!isEmpty(queue)) {
        Node *node = dequeue(queue);
        printf("%d ", node->data);
        if (node->left != NULL) {
            enqueue(queue, node->left);
        }
        if (node->right != NULL) {
            enqueue(queue, node->right);
        }
    }
}
int main() {
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);

    printf("Preorder DFS: ");
    preorderDFS(root);
    printf("\n");

    printf("Inorder DFS: ");
    inorderDFS(root);
    printf("\n");

    printf("Postorder DFS: ");
    postorderDFS(root);
    printf("\n");

    printf("Level-order BFS: ");
    levelorderBFS(root);
    printf("\n");

    return 0;
}
