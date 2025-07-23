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

Node *createNode(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ----------------- QUEUE -----------------
typedef struct Queue {
    Node **arr;
    int capacity;
    int front;
    int rear;
} Queue;

Queue *createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->arr = (Node **)malloc(sizeof(Node *) * capacity);
    queue->front = 0;
    queue->rear = -1;   // rear = -1
    queue->capacity = capacity;
    return queue;
}

int isEmpty(Queue *queue) {
    return queue->front > queue->rear;
}

int isFull(Queue *queue) {
    return queue->rear == queue->capacity - 1;
}

void enqueue(Queue *queue, Node *node) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->arr[++queue->rear] = node;
}

Node *dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return NULL;
    }
    return queue->arr[queue->front++];
}

// ----------------- DELETE TREE NODE -----------------
Node *deleteTreeNode(Node *root, int data) {
    if (root == NULL) return NULL;

    // Nếu cây chỉ có 1 node
    if (root->left == NULL && root->right == NULL) {
        if (root->data == data) {
            free(root);
            return NULL;
        } else return root;
    }

    Queue *queue = createQueue(100);
    enqueue(queue, root);

    Node *target = NULL;      // node cần xóa
    Node *current = NULL;
    Node *lastNode = NULL;    // node cuối cùng
    Node *parentOfLast = NULL;

    while (!isEmpty(queue)) {
        current = dequeue(queue);
        if (current->data == data) {
            target = current;  // tìm node cần xóa
        }
        // enqueue con trái
        if (current->left) {
            parentOfLast = current;
            enqueue(queue, current->left);
        }
        // enqueue con phải
        if (current->right) {
            parentOfLast = current;
            enqueue(queue, current->right);
        }
        lastNode = current; // node cuối cùng trong BFS
    }

    // Nếu không tìm thấy giá trị cần xóa
    if (target == NULL) return root;

    // Thay giá trị node cần xóa bằng giá trị của node cuối
    target->data = lastNode->data;

    // Xóa node cuối
    if (parentOfLast->right == lastNode) {
        parentOfLast->right = NULL;
    } else if (parentOfLast->left == lastNode) {
        parentOfLast->left = NULL;
    }
    free(lastNode);

    return root;
}

// ----------------- TRAVERSAL -----------------
void levelOrder(Node *root) {
    if (root == NULL) return;
    Queue *queue = createQueue(100);
    enqueue(queue, root);
    while (!isEmpty(queue)) {
        Node *node = dequeue(queue);
        printf("%d ", node->data);
        if (node->left) enqueue(queue, node->left);
        if (node->right) enqueue(queue, node->right);
    }
    printf("\n");
}

// ----------------- MAIN -----------------
int main() {
    Node *root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);

    printf("Level order before delete: ");
    levelOrder(root);

    root = deleteTreeNode(root, 5);

    printf("Level order after delete: ");
    levelOrder(root);

    return 0;
}
