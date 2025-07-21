//
// Created by Hikari on 21/07/2025.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

typedef struct Queue {
    Node **data;
    int front;
    int rear;
    int size;
} Queue;

Queue *createQueue(int size) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (Node **)malloc(sizeof(Node *) * size);
    q->front = 0;
    q->rear = 0;
    q->size = size;
    return q;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, Node *node) {
    if (q->rear < q->size) {
        q->data[q->rear++] = node;
    }
}

Node *dequeue(Queue *q) {
    if (!isEmpty(q)) {
        return q->data[q->front++];
    }
    return NULL;
}

int findValueBFS(Node *root, int target) {
    if (root == NULL) return 0;

    Queue *queue = createQueue(100);
    enqueue(queue, root);

    while (!isEmpty(queue)) {
        Node *current = dequeue(queue);

        if (current->data == target) {
            free(queue->data);
            free(queue);
            return 1;
        }

        if (current->left != NULL) {
            enqueue(queue, current->left);
        }
        if (current->right != NULL) {
            enqueue(queue, current->right);
        }
    }

    free(queue->data);
    free(queue);
    return 0;
}
int main() {
    Node *root = createNode(2);
    root->left = createNode(3);
    root->left->left = createNode(5);
    root->right = createNode(4);
    int x = 3;
    printf("findValue: %d\n", x);
    if (findValueBFS(root, x)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    free(root->left->left);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}


