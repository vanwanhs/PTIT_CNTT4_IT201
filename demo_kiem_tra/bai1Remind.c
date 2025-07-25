//
// Created by Hikari on 25/07/2025.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task{
    int id;
    char title[100];
    int priority;
    char deadline[100];
}Task;
typedef struct SingleNode {
    Task task;
    struct SingleNode *next;
}SingleNode;
SingleNode *createSingleNode(Task task) {
    SingleNode *newNode = (SingleNode *)malloc(sizeof(SingleNode));
    newNode -> task = task;
    newNode -> next = NULL;
    return newNode;
}
SingleNode *inserNodeAtEnd(SingleNode *head, Task task) {
    SingleNode *newNode = createSingleNode(task);
    if (head == NULL) {
        return newNode;
    }
    SingleNode *temp = head;
    while (temp -> next != NULL) {
        temp = temp -> next;
    }
    temp -> next = newNode;
    return head;
}
void displayList(SingleNode *head) {
    SingleNode *temp = head;
    while (temp != NULL) {
        printf("=================================\n");
        printf("%d\n",temp -> task.id);
        printf("%s\n",temp -> task.title);
        printf("%d\n",temp -> task.priority);
        printf("%s\n",temp -> task.deadline);
        temp = temp -> next;
    }
    printf("\n");
}
SingleNode *deletel(SingleNode *head, int id) {
    if (head == NULL) {
        return NULL;
    }
    SingleNode *temp = head;
    SingleNode *prev = NULL;
    if (temp -> task.id == id) {
        head = head -> next;
        free(temp);
        return head;
    }
    while (temp != NULL && temp -> task.id != id) {
        prev = temp;
        temp = temp -> next;
    }
    if (temp == NULL) {
        return NULL;
    }
    prev -> next = temp -> next;
    free(temp);
    return head;
}
int main() {
    int choice;
    SingleNode *SingleHead = NULL;
    int nextId = 1;
    do{
        printf("1.Add\n");
        printf("2.Display\n");
        printf("3.Delete\n");
        printf("4.Update\n");
        printf("5.Mark Complete\n");
        printf("6.Sort\n");
        printf("7.Find\n");
        printf("8.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                Task task;
                task.id = nextId++;
                printf("Enter the Titel: ");
                fgets(task.title,100,stdin);
                task.title[strlen(task.title)-1] = '\0';

                printf("Enter the priority: ");
                scanf("%d",&task.priority);
                while (getchar() != '\n');

                printf("Enter the deadline: ");
                fgets(task.deadline,100,stdin);
                task.deadline[strlen(task.deadline)-1] = '\0';

                fflush(stdin);
                SingleHead= inserNodeAtEnd(SingleHead,task);
                break;
            case 2:
                displayList(SingleHead);
                break;
            case 3:
                int id;
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            default:
                printf("Invalid Choice\n");
        }
    }while (choice != 8);
    return 0;
}