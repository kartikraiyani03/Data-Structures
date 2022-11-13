#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct doubleendedqueue
{
    int size;
    int rear;
    int front;
    int *arr;   
};

int isEmpty(struct doubleendedqueue *dq)
{
    if (dq->front == dq->rear && dq->front != -1)
    {
        return 1;  
    }
    else
    {
        return 0;
    }                                                
}

int isFull(struct doubleendedqueue *dq)
{
    if (dq->rear == dq->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueueatR(struct doubleendedqueue *dq, int val)
{
    if (isFull(dq))
    {
        printf("can'r able to enqueue \n");
    }
    else
    {
        dq->rear++;
        dq->arr[dq->rear] = val;
    }
}

void enqueueatF(struct doubleendedqueue *dq, int val)
{
    if (isFull(dq))
    {
        printf("can't able to enqueue \n");
    }
    else
    {
        dq->front--;
        dq->arr[dq->front] = val;
    }
}

int dequeueatF(struct doubleendedqueue *dq)
{
    if (isEmpty(dq))
    {
        return 1;
    }
    else
    {
        dq->front++;
        return dq->arr[dq->rear];
    }
}

int dequeueatR(struct doubleendedqueue *dq)
{
    if (isEmpty(dq))
    {
        return 1;
    }
    else
    {
        dq->rear--;
        return dq->arr[dq->rear];
    }
}

void display(struct doubleendedqueue *dq)
{
    printf("ELEMENTS ARE... \n \n");

    if (dq->rear == dq->front)
    {
        printf(" DOUBLE ENDED QUEUE IS EMPTY \n ");
    }
    else
    {
        for (int i = dq->rear; i > dq->front; i--)
        {
            printf("%d \t", dq->arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    struct doubleendedqueue *dq;

    dq->size = 5;
    dq->rear = 0;
    dq->front = 0;

    dq->arr = (int *)malloc(sizeof(int) * dq->size);

    int ch;
    int ele;
    int choice1;
    int choice2;

    printf("\n");
    printf("NAME : KARTIK RAIYANI   ENROLLMENT NO. : 210210116019   \n");
    printf("\n");

    while (1)
    {

        printf("1. ENQUEUE \n");
        printf("2. DEQUEUE \n");
        printf("3. DISPLAY \n");
        printf("4. EXIT \n \n");

        printf("ENTER YOUR CHOICE \n \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("ENQUEUE THE ELEMENT AT...\n");
            printf("1. REAR \n");
            printf("2. FRONT \n");
            printf("ENTER YOUR CHOICE \n");
            scanf("%d", &choice1);

            if (choice1 == 1)
            {
                printf("ENTER THE ELEMENT YOU WANT TO ENQUEUE AT REAR \n");
                scanf("%d", &ele);
                enqueueatR(&dq, ele);
                printf("hello");
                system("cls");
            }
            else if (choice1 == 2)
            {
                printf("ENTER THE ELEMENT YOU WANT TO ENQUEUE AT FRONT \n");
                scanf("%d", &ele);
             enqueueatF(&dq, ele);
                system("cls");
            }
            else
            {
                printf("invalid choice \n");
            }
            break;
        case 2:

            printf("DEQUEUE THE ELEMENT AT...\n");
            printf("1. REAR \n");
            printf("2. FRONT \n");

            printf("ENTER YOUR CHOICE \n \n");
            scanf("%d", &choice2);

            if (choice2 == 1)
            {
                dequeueatR(&dq);
                system("cls");
            }
            else if (choice2 == 2)
            {
                dequeueatF(&dq);
                system("cls");
            }
            else
            {
                printf("invalid choice \n");
            }

            break;

        case 3:

            display(&dq);
            break;

        case 4:
            exit(1);

        default:
            printf("invalid choice \n");
            break;
        }
    }

    return 0;
}