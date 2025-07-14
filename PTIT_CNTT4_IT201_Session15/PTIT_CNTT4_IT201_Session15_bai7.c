
#include <Stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[50];
}User;
typedef struct
{
    User* queue;
    int front,rear,size;
}Queue;
void createQueue(Queue* queue)
{
    queue->queue = (User*)malloc(sizeof(User)*100);
    queue->front=0;
    queue->rear=0;
    queue->size=0;
}

int isFull(Queue* queue)
{
    return queue->size==100;
}
int isEmpty(Queue* queue)
{
    return queue->size==0;
}
void enQueue(Queue* queue,const char* name)
{
    if (isFull(queue)) return;
    strcpy(queue->queue[queue->rear].name,name);
    queue->rear=(queue->rear+1)%100;
    queue->size++;
    printf("da them khach: %s\n",name);
}
void deQueue(Queue* queue)
{
    if (isEmpty(queue)) return;
    printf("phuc vi khach: %s\n",queue->queue[queue->front].name);
    queue-> front=(queue->front+1)%100;
    queue->size--;
}

void displayQueue(Queue* queue)
{
    if (isEmpty(queue))
    {
        printf("hien tai khong co khach hang nao");
        return;
    }else
    {
        printf("khach dang cho phuc vu:\n");
        for(int i=0;i<queue->size;i++)
        {
            int index=(queue->front+i)%100;
            printf("%s \n",queue->queue[index].name);
        }
    }

}

void printMenu()
{
    printf("\n            MENU\n");
    printf("1.Them khach hang moi\n");
    printf("2.Phuc vu khach hang\n");
    printf("3.hien thi khach dang cho\n");
    printf("4.Thoat chuong trinh\n");
    printf("Moi ban chon: ");
}
int main(){
    Queue queue;
    createQueue(&queue);
    int choice;
    char name[50];
    do{
        printMenu();
        scanf("%d",&choice);
        getchar();
        switch (choice)
        {
            case 1:
                if (isFull(&queue))
                {
                    printf("so khach da day khong the them duoc nua\n");
                    break;
                }
                printf("moi ban nhap ten khach hang: ");
                fgets(name,50,stdin);
                name[strcspn(name,"\n")] = '\0';
                enQueue(&queue,name);
                break;
            case 2:
                deQueue(&queue);
                break;
            case 3:
                displayQueue(&queue);
                break;
            case 4:
                printf("cam on ban");
                break;
            default:
        }
    }while(choice!=4);
    return 0;
}