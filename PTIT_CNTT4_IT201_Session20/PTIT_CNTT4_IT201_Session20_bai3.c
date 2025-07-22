#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Queue {
    Node** items;
    int front;
    int rear;
    int size;
} Queue;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->items = (Node**)malloc(sizeof(Node*) * capacity);
    q->front = 0;
    q->rear = 0;
    q->size = capacity;
    return q;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, Node* node) {
    if (q->rear < q->size) {
        q->items[q->rear++] = node;
    }
}

Node* dequeue(Queue* q) {
    if (isEmpty(q)) return NULL;
    return q->items[q->front++];
}

void add(Node* root, int value) {
    Queue* q = createQueue(100);
    enqueue(q, root);
    while (!isEmpty(q)) {
        Node* current = dequeue(q);
        if (current->left == NULL) {
            current->left = createNode(value);
            break;
        } else {
            enqueue(q, current->left);
        }
        if (current->right == NULL) {
            current->right = createNode(value);
            break;
        } else {
            enqueue(q, current->right);
        }
    }
}

void levelOrder(Node* root) {
    if (root == NULL) return;
    Queue* q = createQueue(100);
    enqueue(q, root);
    while (!isEmpty(q)) {
        Node* current = dequeue(q);
        printf("%d ", current->data);
        if (current->left != NULL) enqueue(q, current->left);
        if (current->right != NULL) enqueue(q, current->right);
    }
}

int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int valueToAdd = 6;
    add(root, valueToAdd);

    printf("Output: ");
    levelOrder(root);

    return 0;
}
