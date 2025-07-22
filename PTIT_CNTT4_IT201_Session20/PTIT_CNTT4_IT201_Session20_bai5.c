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
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findMaxValue(Node* root) {
    if (root == NULL) return -1e9; // giả sử giá trị toàn cây luôn dương

    int leftMax = findMaxValue(root->left);
    int rightMax = findMaxValue(root->right);

    int max = root->data;
    if (leftMax > max) max = leftMax;
    if (rightMax > max) max = rightMax;

    return max;
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(5);
    root->right->right = createNode(4);

    int maxValue = findMaxValue(root);
    printf("max value: %d\n", maxValue);

    return 0;
}
