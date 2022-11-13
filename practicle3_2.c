#include <stdio.h>
#include <stdlib.h>

struct cqueue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct cqueue *q)
{
    if ((q->rear + 1) % q->size == q->front)

        return 1;

    else
        return 0;
}

int isEmpty(struct cqueue *q)
{
    if (q->rear == q->front)
        return 1;

    else
        return 0;
}

void enqueue(struct cqueue *q, int val)
{
    if (isFull(q))
    {
        printf("queue is full \n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = val;
    }
}

int dequeue(struct cqueue *q)
{

    if (isEmpty(q))
    {
        printf("queue is empty \n");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        return q->arr[q->front];
    }
}

 
void display(struct cqueue *q)
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
            
        }printf("\n");
    }
}

int main()
{
    int d;

    struct cqueue q;

    q.size = 5;
    q.rear = 0;
    q.front = 0;

    q.arr = (int *)malloc(sizeof(int) * q.size);


     int ch;
    int ele;

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

            printf("ENTER THE ELEMENT YOU WANT TO ENQUEUE \n");
            scanf("%d", &ele);
            enqueue(&q, ele);
            break;

        case 2:
            dequeue(&q);
            break;

        case 3:
            display(&q);
            break;

        case 4:
            exit(1);

        default:
            printf("invalid choice \n");
            break;
        }
    }

    // enqueue(&q, 1);
    // enqueue(&q, 2);
    // enqueue(&q, 3);
    // enqueue(&q, 4);
    // enqueue(&q, 5);

    // printf("dequeuing elemnet is %d \n",dequeue(&q));
    // printf("dequeuing elemnet is %d \n",dequeue(&q));
    // printf("dequeuing elemnet is %d \n",dequeue(&q));
    // printf("dequeuing elemnet is %d \n",dequeue(&q));
   

    // if (isFull(&q))
    // {
    //     printf("Finally Queue is full \n");
    // }

    // if (isEmpty(&q))
    // {
    //     printf("Finally Queue is empty \n");
    // }

    // printf("Rear is %d\n", q.rear);
    // printf("Front is %d\n", q.front);

    return 0;
}