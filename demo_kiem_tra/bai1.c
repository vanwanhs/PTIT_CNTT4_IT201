//
// Created by Hikari on 17/07/2025.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Project {
    int id;
    char title[50];
    char owner[50];
    int priority;
}Project;
typedef struct SingleNode {
    Project project;
    struct SingleNode *next;
}SingleNode;
typedef struct DoubleNode {
    Project project;
    struct DoubleNode *next;
    struct DoubleNode *prev;
}DoubleNode;
DoubleNode *createDoubleNode(Project project) {
    DoubleNode *newNode = (DoubleNode *)malloc(sizeof(DoubleNode));
    newNode->project = project;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
SingleNode *createNode(Project project) {
    SingleNode *newNode = (SingleNode *)malloc(sizeof(SingleNode));
    newNode->project = project;
    newNode->next = NULL;
    return newNode;
}
SingleNode *inser(SingleNode *head, Project project) {
    SingleNode *newNode = createNode(project);
    if (head == NULL) {
        return newNode;
    }
    SingleNode *current = head;
    while (current != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}
void display(SingleNode *head) {
    SingleNode *current = head;
    while (current != NULL) {
        printf("%d ", current->project.id);
        printf("%s ", current->project.title);
        printf("%s ", current->project.owner);
        printf("%d ", current->project.priority);
        printf(".........................................");
        printf("\n");
        current = current->next;
    }
}
SingleNode *deleteNode(SingleNode *head, int id) {
    if (head == NULL) {
        return NULL;
    }
    SingleNode *current = head;
    SingleNode *prev = NULL;
    if (current->project.id == id) {
        head = head->next;
        free(current);
        return head;
    }
    while (current != NULL && current->project.id != id) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        return head;
    }
    prev->next = current->next;
    free(current);
    return head;
}
SingleNode *update(SingleNode *head, int id) {
    if (head == NULL) {
        return NULL;
    }
    SingleNode *current = head;
    while (current != NULL) {
        if (current->project.id == id) {
            printf("Enter new title: ");
            fgets(current->project.title, sizeof(current->project.title), stdin);
            current->project.title[strlen(current->project.title) - 1] = '\0';
            printf("Enter Ower: ");
            fgets(current->project.owner, sizeof(current->project.owner), stdin);
            current->project.owner[strlen(current->project.owner) - 1] = '\0';
            printf("Enter priority: ");
            scanf("%d", &current->project.priority);
            while (getchar() != '\n');
            return head;
        }
        current = current->next;
    }
    printf("Couldn't find ID\n");
    return head;
}
DoubleNode *fisnish(DoubleNode *head, Project project) {
    DoubleNode *newNode = createDoubleNode(project);
    if (head == NULL) {
        return newNode;
    }
    DoubleNode *current = head;
    while (current ->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}
SingleNode *findNodeById(SingleNode *head, int id) {
    while (head != NULL) {
        if (head->project.id == id) {
            return head;
            head = head->next;
        }
    }
    return NULL;
}
SingleNode *bubbleSortByPriority(SingleNode *head) {
    if (head == NULL || head->next == NULL) return head;

    for (SingleNode *i = head; i->next != NULL; i = i->next) {
        for (SingleNode *j = head; j->next != NULL; j = j->next) {
            if (j->project.priority > j->next->project.priority) {
                Project temp = j->project;
                j->project = j->next->project;
                j->next->project = temp;
            }
        }
    }

    return head;
}
void searchByTitle(SingleNode *head, const char *title) {
    int found = 0;
    SingleNode *current = head;
    while (current != NULL) {
        if (strcasecmp(current->project.title, title) == 0) {
            printf("ID: %d\n", current->project.id);
            printf("Title: %s\n", current->project.title);
            printf("Owner: %s\n", current->project.owner);
            printf("Priority: %d\n", current->project.priority);
            printf("------------------------------\n");
            found = 1;
        }
        current = current->next;
    }
    if (!found) {
        printf("Don't search: %s\n", title);
    }
}


int main() {
    SingleNode *headSingle = NULL;
    DoubleNode *headDouble = NULL;
    int nextId = 1;
    int choice;
    do {
        printf("\n=========== Menu ===========\n");
        printf("1. Add\n");
        printf("2. Display\n");
        printf("3. Delete\n");
        printf("4. Edit\n");
        printf("5. Mark complete\n");
        printf("6. Sort\n");
        printf("7. Search\n");
        printf("8. Exit\n");
        printf("=>> Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                Project project;
                project.id = nextId++;
                printf("Enter title: ");
                fgets(project.title, 50, stdin);
                project.title[strlen(project.title) - 1] = '\0';
                printf("Enter Ower: ");
                fgets(project.owner, 50, stdin);
                project.owner[strlen(project.owner) - 1] = '\0';
                printf("Enter priority: ");
                scanf(" %d", &project.priority);
                while (getchar() != '\n');
                fflush(stdin);
                headSingle = inser(headSingle, project);
                break;
            case 2:
                display(headSingle);
                break;
            case 3:
                int id;
                printf("Enter id: ");
                scanf(" %d", &id);
                headSingle = deleteNode(headSingle, id);
                break;
            case 4:
                int updateById;
                printf("Enter id: ");
                scanf(" %d", &updateById);
                headSingle = update(headSingle, updateById);
                break;
            case 5:
                int finish;
                printf("Enter id: ");
                scanf(" %d", &finish);
                SingleNode *finishNode = findNodeById(headSingle, finish);
                if (finishNode == NULL) {
                    printf("Couldn't find ID\n");
                    break;
                }
                Project finishProject = finishNode->project;
                headDouble = inser(headDouble, finishProject);
                headSingle = deleteNode(headSingle, finish);
                break;
            case 6:
                headSingle = bubbleSortByPriority(headSingle);
                printf("sort successfully.\n");
                break;
            case 7: {
                char searchTitle[50];
                printf("Enter title: ");
                while (getchar() != '\n');
                fgets(searchTitle, sizeof(searchTitle), stdin);
                searchTitle[strcspn(searchTitle, "\n")] = '\0';
                searchByTitle(headSingle, searchTitle);
                break;
            }

            case 8:
                printf("Thanks you using program...");
                break;
            default:
                printf("Invalid choice-\n");
        }
    }while (choice != 8);
    return 0;
}
