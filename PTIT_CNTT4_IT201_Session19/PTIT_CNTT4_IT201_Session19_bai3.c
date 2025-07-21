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

void postorderDFS(Node *root) {
    if (root == NULL) {
        return;
    }
    postorderDFS(root->left);
    postorderDFS(root->right);
    printf("%d ", root->data);
}

int main() {
    Node *root = createNode(2);
    root->left = createNode(3);
    root->left->left = createNode(5);
    root->right = createNode(4);

    postorderDFS(root);

    return 0;
}
