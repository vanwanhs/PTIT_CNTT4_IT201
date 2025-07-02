//
// Created by Hikari on 02/07/2025.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
}Node;
Node* createNode(int data)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
Node* printList(Node* head)
{
    Node* current=head;
    while (current!=NULL)
    {
        printf("%d->",current->data);
        current=current->next;
    }
    printf("NULL\n");
}
int length(Node*head)
{
    int count=0;
    Node* current=head;
    while (current!=NULL)
    {
        count++;
        current=current->next;
    }
    return count;
}
Node* removeHead(Node* head)
{
    if (head==NULL)
    {
        return NULL;
    }
    Node* temp=head;
    head=head->next;
    free(temp);
    return head;
}
int main()
{
    Node* head=createNode(1);
    head->next=createNode(2);
    head->next->next=createNode(3);
    head->next->next->next=createNode(4);
    head->next->next->next->next=createNode(5);
    printList(head);
    head=removeHead(head);
    printList(head);
    return 0;
}
