//
// Created by Hikari on 22/07/2025.
//


#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;

}Node;
Node *createNode(int data) {
    Node *createNode = (Node *)malloc(sizeof(Node));
    createNode->data = data;
    createNode->left = NULL;
    createNode->right = NULL;
    return createNode;
}
void preorderDFS(Node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderDFS(root->left);
    preorderDFS(root->right);
}
void inorderDFS(Node *root) {
    if (root == NULL) return;
    inorderDFS(root->left);
    printf("%d ", root->data);
    inorderDFS(root->right);
}
void postorderDFS(Node *root) {
    if (root == NULL) return;
    postorderDFS(root->left);
    postorderDFS(root->right);
    printf("%d ", root->data);
}
typedef struct QueueNode {
    int **arr;
    int capacity;
    int rear;
    int front;
}QueueNode;
int main() {
    Node *root = NULL;
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    printf("preorderDFS\n");
    preorderDFS(root);
    printf("\n");
    printf("inorderDFS\n");
    inorderDFS(root);
    printf("\n");
    printf("postorderDFS\n");
    postorderDFS(root);
    return 0;
}
