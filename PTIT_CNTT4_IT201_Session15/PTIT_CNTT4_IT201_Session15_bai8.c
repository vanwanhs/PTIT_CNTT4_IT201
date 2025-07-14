
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE 100

typedef struct {
    char name[50];
    int age;
} Customer;

typedef struct {
    Customer* data;
    int front, rear, size;
} Queue;

void initQueue(Queue* q) {
    q->data = (Customer*)malloc(sizeof(Customer) * MAX_QUEUE);
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

int isFull(Queue* q) {
    return q->size == MAX_QUEUE;
}

int isEmpty(Queue* q) {
    return q->size == 0;
}

void enqueue(Queue* q, Customer c) {
    if (isFull(q)) {
        printf("Hang doi da day, khong the them!\n");
        return;
    }
    q->data[q->rear] = c;
    q->rear = (q->rear + 1) % MAX_QUEUE;
    q->size++;
    printf("Da them khach: %s (%d tuoi)\n", c.name, c.age);
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong, khong the phuc vu.\n");
        return;
    }
    Customer c = q->data[q->front];
    printf("Phuc vu khach: %s (%d tuoi)\n", c.name, c.age);
    q->front = (q->front + 1) % MAX_QUEUE;
    q->size--;
}

void displayQueue(Queue* q, const char* label) {
    if (isEmpty(q)) {
        printf("%s rong.\n", label);
        return;
    }
    printf("%s:\n", label);
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % MAX_QUEUE;
        Customer c = q->data[index];
        printf("%d. %s (%d tuoi)\n", i + 1, c.name, c.age);
    }
}

void printMenu() {
    printf("\n======= MENU =======\n");
    printf("1. Them khach hang\n");
    printf("2. Phuc vu khach hang\n");
    printf("3. Hien thi hang doi\n");
    printf("4. Thoat\n");
    printf("Chon chuc nang: ");
}

int main() {
    Queue queueOld, queueNormal;
    initQueue(&queueOld);
    initQueue(&queueNormal);

    int choice;
    Customer temp;

    do {
        printMenu();
        scanf("%d", &choice);
        getchar(); // xoa ky tu \n

        switch (choice) {
            case 1:
                printf("Nhap ten khach hang: ");
                fgets(temp.name, sizeof(temp.name), stdin);
                temp.name[strcspn(temp.name, "\n")] = '\0';

                printf("Nhap tuoi: ");
                scanf("%d", &temp.age);
                getchar();

                if (temp.age >= 60)
                    enqueue(&queueOld, temp);
                else
                    enqueue(&queueNormal, temp);
                break;
            case 2:
                if (!isEmpty(&queueOld))
                    dequeue(&queueOld);
                else if (!isEmpty(&queueNormal))
                    dequeue(&queueNormal);
                else
                    printf("Khong con khach nao trong hang doi.\n");
                break;
            case 3:
                displayQueue(&queueOld, "Hang doi uu tien (>= 60 tuoi)");
                displayQueue(&queueNormal, "Hang doi thuong (< 60 tuoi)");
                break;
            case 4:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le. Thu lai!\n");
        }
    } while (choice != 4);

    free(queueOld.data);
    free(queueNormal.data);
    return 0;
}