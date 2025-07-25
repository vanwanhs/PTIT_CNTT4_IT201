//
// Created by Hikari on 25/07/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {
    int id;
    char name[50];
    int priority;
    char deadline[20];
} Task;

typedef struct NodeSingly {
    Task *task;
    struct NodeSingly *next;
} NodeSingly;

typedef struct NodeDoubly {
    Task *task;
    struct NodeDoubly *next;
    struct NodeDoubly *prev;
} NodeDoubly;

NodeSingly* createNodeSingly(Task *task) {
    NodeSingly *newNode = (NodeSingly*)malloc(sizeof(NodeSingly));
    newNode->task = task;
    newNode->next = NULL;
    return newNode;
}

NodeDoubly* createNodeDoubly(Task *task) {
    NodeDoubly* newNode = (NodeDoubly*)malloc(sizeof(NodeDoubly));
    newNode->task = task;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void markTaskComplete(NodeSingly **headSingly, NodeDoubly **headDoubly, int id) {
    if (*headSingly == NULL) {
        printf("No tasks available.\n");
        return;
    }
    NodeSingly *temp = *headSingly;
    NodeSingly *prev = NULL;
    while (temp != NULL && temp->task->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Task with ID %d not found.\n", id);
        return;
    }
    NodeDoubly *newNode = createNodeDoubly(temp->task);
    if (*headDoubly == NULL) {
        *headDoubly = newNode;
    } else {
        newNode->next = *headDoubly;
        (*headDoubly)->prev = newNode;
        *headDoubly = newNode;
    }
    if (prev == NULL) {
        *headSingly = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Task marked as completed.\n");
}

void printMenu() {
    printf("        MENU\n");
    printf("1. Add task\n");
    printf("2. Display task list\n");
    printf("3. Delete task\n");
    printf("4. Edit task information\n");
    printf("5. Mark task as completed\n");
    printf("6. Sort tasks\n");
    printf("7. Search for task by title\n");
    printf("8. Exit program\n");
    printf("Your choice: ");
}

void insertNodeSingly(NodeSingly **head, Task *task) {
    NodeSingly *newNode = createNodeSingly(task);
    if (*head == NULL) {
        *head = newNode;
        printf("Task added successfully.\n");
        return;
    }
    NodeSingly *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Task added successfully.\n");
}

void printTaskList(NodeSingly *head) {
    if (head == NULL) {
        printf("No tasks available!\n");
        return;
    }
    NodeSingly *temp = head;
    int count = 1;
    while (temp != NULL) {
        printf("Task #%d\n", count++);
        printf("ID: %d\n", temp->task->id);
        printf("Title: %s\n", temp->task->name);
        printf("Priority: %d\n", temp->task->priority);
        printf("Deadline: %s\n", temp->task->deadline);
        printf("\n");
        temp = temp->next;
    }
}

void deleteTask(NodeSingly **head, int id) {
    if (*head == NULL) {
        printf("No tasks available!\n");
        return;
    }
    NodeSingly *temp = *head;
    NodeSingly *prev = NULL;
    while (temp != NULL && temp->task->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Task ID not found!\n");
        return;
    }
    if (prev == NULL) *head = temp->next;
    else prev->next = temp->next;
    free(temp->task);
    free(temp);
    printf("Task with ID %d deleted successfully.\n", id);
}

void editTask(NodeSingly **head, int id) {
    if (*head == NULL) {
        printf("No tasks available!\n");
        return;
    }
    NodeSingly *temp = *head;
    while (temp != NULL && temp->task->id != id) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Task ID not found!\n");
        return;
    }
    printf("New title: ");
    getchar();
    fgets(temp->task->name, sizeof(temp->task->name), stdin);
    temp->task->name[strcspn(temp->task->name, "\n")] = '\0';

    printf("New priority: ");
    scanf("%d", &temp->task->priority);
    getchar();

    printf("New deadline: ");
    fgets(temp->task->deadline, sizeof(temp->task->deadline), stdin);
    temp->task->deadline[strcspn(temp->task->deadline, "\n")] = '\0';
}

void bubbleSort(NodeSingly *head) {
    if (head == NULL || head->next == NULL) return;
    int swapped;
    NodeSingly *ptr;
    Task *tempTask;
    do {
        swapped = 0;
        ptr = head;
        while (ptr->next != NULL) {
            if (ptr->task->priority > ptr->next->task->priority) {
                tempTask = ptr->task;
                ptr->task = ptr->next->task;
                ptr->next->task = tempTask;
                swapped = 1;
            }
            ptr = ptr->next;
        }
    } while (swapped);
    printf("Tasks sorted successfully by priority.\n");
}

void searchByName(NodeSingly *head, const char *name) {
    if (head == NULL) {
        printf("No tasks available!\n");
        return;
    }
    NodeSingly *temp = head;
    while (temp != NULL && strcmp(temp->task->name, name) != 0) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Task titled \"%s\" not found.\n", name);
        return;
    }
    printf("ID: %d\n", temp->task->id);
    printf("Title: %s\n", temp->task->name);
    printf("Priority: %d\n", temp->task->priority);
    printf("Deadline: %s\n", temp->task->deadline);
}

void freeSinglyList(NodeSingly **head) {
    NodeSingly *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp->task);
        free(temp);
    }
}

void freeDoublyList(NodeDoubly **head) {
    NodeDoubly *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp->task);
        free(temp);
    }
}

int main() {
    int choice;
    NodeSingly *headSingly = NULL;
    NodeDoubly *headDoubly = NULL;
    int nextId = 1;
    do {
        printMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                Task *task = (Task *)malloc(sizeof(Task));
                task->id = nextId++;
                getchar();
                printf("Task title: ");
                fgets(task->name, sizeof(task->name), stdin);
                task->name[strcspn(task->name, "\n")] = '\0';

                printf("Task priority: ");
                scanf("%d", &task->priority);
                getchar();

                printf("Task deadline: ");
                fgets(task->deadline, sizeof(task->deadline), stdin);
                task->deadline[strcspn(task->deadline, "\n")] = '\0';

                insertNodeSingly(&headSingly, task);
                break;
            }
            case 2:
                printTaskList(headSingly);
                break;
            case 3: {
                int id;
                printf("Task ID to delete: ");
                scanf("%d", &id);
                deleteTask(&headSingly, id);
                break;
            }
            case 4: {
                int id;
                printf("Task ID to edit: ");
                scanf("%d", &id);
                editTask(&headSingly, id);
                break;
            }
            case 5: {
                int id;
                printf("Task ID to mark as completed: ");
                scanf("%d", &id);
                markTaskComplete(&headSingly, &headDoubly, id);
                break;
            }
            case 6:
                bubbleSort(headSingly);
                break;
            case 7: {
                char name[100];
                printf("Enter task title: ");
                getchar();
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                searchByName(headSingly, name);
                break;
            }
            case 8:
                freeSinglyList(&headSingly);
                freeDoublyList(&headDoubly);
                printf("Program exited successfully.\n");
                break;
            default:
                printf("Invalid input!\n");
        }
    } while (choice != 8);
    return 0;
}

