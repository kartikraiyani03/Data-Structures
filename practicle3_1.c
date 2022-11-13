#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct queue *q)
{
    if (q->rear == q->size - 1 && q->front == -1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int isEmpty(struct queue *q)
{
    if (q->rear == q->front || q->rear == -1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

void enqueue(struct queue(*q), int val)
{
    if (isFull(q))
    {
        printf("queue is full \n");
    }

    else
    {
        q->rear++;
        q->arr[q->rear] = val;
    }
}

int dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("queue is empty \n");
    }

    else
    {
        q->front++;
        return q->arr[q->front];
    }
}

void display(struct queue *q)
{
    printf("ELEMENTS ARE... \n \n");

    if (q->rear == q->front)
    {
        printf("QUEUE IS EMPTY \n ");
    }
    else
    {
        for (int i = q->rear; i > q->front; i--)
        {
            printf("%d \t", q->arr[i]);
        }
        printf("\n");
        printf("\n");
    }
}

int main()
{
    struct queue q;

    q.size = 5;
    q.front = -1;
    q.rear = -1;

    q.arr = (int *)malloc(sizeof(int) * q.size);

    int ch;
    int ele;

    while (1)
    {
        printf("\n");
        printf("NAME : KARTIK RAIYANI   ENROLLMENT NO. : 210210116019   \n");
        printf("\n");

        printf("1. ENQUEUE \n");
        printf("2. DEQUEUE \n");
        printf("3. DISPLAY \n");
        printf("4. EXIT \n \n");

        printf("ENTER YOUR CHOICE \n \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:

            printf("ENTER THE ELEMENT YOU WANT TO ENQUEUE \n");
            scanf("%d", &ele);
            enqueue(&q, ele);
            system("cls");
            break;

        case 2:
            dequeue(&q);
            system("cls");
            break;

        case 3:
            system("cls");
            display(&q);
            printf("PRESS ANY KEY TO CONTINUE \n");
            getch();
            system("cls");
            break;

        case 4:
            exit(1);

        default:
            printf("invalid choice \n");
            break;
        }
    }

    // enqueue(&q, 12);
    // enqueue(&q, 1);
    // enqueue(&q, 2);
    // enqueue(&q, 13);
    // enqueue(&q, 13);

    //    dequeue(&q);
    //    dequeue(&q);
    //    dequeue(&q);
    //    dequeue(&q);
    //    dequeue(&q);

    // if (isEmpty(&q))
    // {
    //     printf("finally queue is Empty \n");
    // }

    // if (isFull(&q))
    // {
    //     printf("finally queue is Full \n");
    // }

    // printf("Rear is %d \n", q.rear);
    // printf("Front is %d \n", q.front);

    return 0;
}
