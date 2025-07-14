//
// Created by Hikari on 14/07/2025.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Students {
    char name[20];
    int age;
    int id;
}Students;
typedef struct Node {
    Students student;
    struct Node* next;
}Node;
Node *createNode(Students student) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->student = student;
    newNode->next = NULL;
    return newNode;
}
Students createStudent(int id) {
    Students student;
    printf("Enter name: ");
    getchar();
    fgets(student.name, 20, stdin);
    student.name[strlen(student.name)-1] = '\0';
    printf("Enter age: ");
    scanf("%d", &student.age);
    student.id = id;
    return student;
}
Node *appendNode(Node *head, Students student) {
    Node *newNode = createNode(student);
    if (head == NULL) {
        return newNode;
    }
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp -> next = newNode;
    return head;
}
void updateStudentById(Node *head, int id) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->student.id == id) {
            printf("Enter name: ");
           getchar();
            fgets(temp->student.name, 20, stdin);
            temp->student.name[strlen(temp->student.name)-1] = '\0';
            printf("Enter age: ");
            scanf("%d", &temp->student.age);
            temp->student.id = id;
            return;
        }
        temp = temp->next;
    }
    printf("Student not found\n");
}
void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("ID: %d\n", temp->student.id);
        printf("Name: %s\n", temp->student.name);
        printf("Age: %d\n", temp->student.age);
        temp = temp->next;

    }
}
int main() {
    Node *head = NULL;
    int n,id;
    printf("Enter number of students: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        Students student = createStudent(i+1);
        head = appendNode(head, student);
    }
    printList(head);
    printf("enter id of student: ");
    scanf("%d", &id);
    updateStudentById(head, id);
    printList(head);
    return 0;
}
