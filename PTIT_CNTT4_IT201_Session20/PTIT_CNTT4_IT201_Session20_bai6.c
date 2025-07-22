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
int findLevel(Node* root, int x, int level) {
    if (root == NULL) return -1;

    if (root->data == x)
        return level;
    int leftLevel = findLevel(root->left, x, level + 1);
    if (leftLevel != -1) return leftLevel;
    return findLevel(root->right, x, level + 1);
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(5);
    root->right->right = createNode(4);

    int value = 3;
    int level = findLevel(root, value, 0);

    if (level != -1)
        printf("Node level: %d\n", level);
    else
        printf("Node not found.\n");

    return 0;
}

