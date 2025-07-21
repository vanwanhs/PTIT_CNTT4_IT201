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

void postorderDFS(Node *root) {
    if (root == NULL) {
        return;
    }
    postorderDFS(root->left);
    postorderDFS(root->right);
    printf("%d ", root->data);
}

int findValueDFS(Node *root, int target) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == target) {
        return 1;
    }
    return findValueDFS(root->left, target) || findValueDFS(root->right, target);
}

int main() {
    Node *root = createNode(2);
    root->left = createNode(3);
    root->left->left = createNode(5);
    root->right = createNode(4);

    printf("Postorder DFS: ");
    postorderDFS(root);
    printf("\n");
    int x = 3;
    printf("findValue: %d\n", x);
    if (findValueDFS(root, x)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}

