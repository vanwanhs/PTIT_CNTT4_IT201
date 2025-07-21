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

Node* taoNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int chieuCao(Node* goc) {
    if (goc == NULL) return -1;
    int trai = chieuCao(goc->left);
    int phai = chieuCao(goc->right);
    return 1 + (trai > phai ? trai : phai);
}

int main() {
    Node* goc = taoNode(2);
    goc->left = taoNode(3);
    goc->right = taoNode(4);
    goc->left->left = taoNode(5);

    printf("%d\n", chieuCao(goc));
    return 0;
}
