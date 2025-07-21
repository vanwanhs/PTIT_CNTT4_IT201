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

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

typedef struct Queue {
    Node** data;
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (Node**)malloc(sizeof(Node*) * size);
    q->front = 0;
    q->rear = 0;
    q->size = size;
    return q;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, Node* node) {
    if (q->rear < q->size) {
        q->data[q->rear++] = node;
    }
}

Node* dequeue(Queue* q) {
    if (!isEmpty(q)) {
        return q->data[q->front++];
    }
    return NULL;
}

void addValue(Node* root, int value) {
    if (root == NULL) return;

    Queue* queue = createQueue(100);
    enqueue(queue, root);

    while (!isEmpty(queue)) {
        Node* current = dequeue(queue);

        if (current->left == NULL) {
            current->left = createNode(value);
            break;
        } else {
            enqueue(queue, current->left);
        }

        if (current->right == NULL) {
            current->right = createNode(value);
            break;
        } else {
            enqueue(queue, current->right);
        }
    }

    free(queue->data);
    free(queue);
}

void printLevelOrder(Node* root) {
    if (root == NULL) return;

    Queue* queue = createQueue(100);
    enqueue(queue, root);

    while (!isEmpty(queue)) {
        Node* current = dequeue(queue);
        printf("%d ", current->data);

        if (current->left != NULL)
            enqueue(queue, current->left);
        if (current->right != NULL)
            enqueue(queue, current->right);
    }

    free(queue->data);
    free(queue);
}

int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    printf("Cay ban dau: ");
    printLevelOrder(root);

    printf("\n\naddValue: 6\n");
    addValue(root, 6);

    printf("Cay sau khi them: ");
    printLevelOrder(root);

    return 0;
}

