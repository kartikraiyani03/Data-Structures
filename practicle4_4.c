#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

struct stacklist
{
    int data;
    struct stacklist *next;
};

void printStackList(struct stacklist *ptr)
{

    while (ptr != NULL)
    {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct stacklist *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stacklist *top)
{
    struct stacklist *ptr = (struct stacklist *)malloc(sizeof(struct stacklist));
    if (ptr = NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct stacklist *push(struct stacklist *top, int val)
{
    struct stacklist *ptr = (struct stacklist *)malloc(sizeof(struct stacklist));

    if (isFull(top))
    {
        printf("STACK IS EMPTY \n");
    }
    else
    {
        ptr->data = val;
        ptr->next = top;
        top = ptr;
        return top;
    }
}

struct stacklist *pop(struct stacklist **top)
{
    if (isEmpty(*top))
    {
        printf("STACK IS EMPTY \n");
    }
    else
    {
        struct stacklist *ptr = *top;
        int value = ptr->data;
        (*top) = (*top)->next;
        free(ptr);
        return value;
    }
}
struct stacklist *peep(struct stacklist *top, int index)
{
    struct stacklist *ptr = top;

    for (int i = 0; i < index - 1; i++)
    {
        if (ptr != NULL)
        {
            ptr = ptr->next;
        }
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}

int main()
{

    struct stacklist *top = NULL;

    int index;
    int element;
    int num;
    int choice;

    while (1)
    {
        printf("\n");
        printf("NAME : KARTIK RAIYANI   ENROLLMENT NO. : 210210116019   \n");
        printf("\n");

        printf("\n");
        printf("1. PUSH \n");
        printf("2. POP \n");
        printf("3. PEEP \n");
        printf("4. DISPLAY \n");
        printf("5. EXIT \n");
        printf("\n");

        printf("ENTER THE CHOICE \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("ENTER THE NUMBER WHICH YOU WANT TO PUSH IN LIST \n");
            scanf("%d", &num);
            top = push(top, num);
            system("cls");
            break;

        case 2:
            pop(&top);
            printf("ELEMENT POPED \n");
            system("cls");
            break;

        case 3:
            system("cls");
            printf("ENTER THE INDEX \n");
            scanf("%d", &index);
            printf("\n");
            printf("ELEMENT AT INDEX %d is %d\n \n \n", index, peep(top, index));
            printf("PRESS ANY KEY TO CONTINUE \n");
            getch();
            break;

        case 4:
            system("cls");
            printStackList(top);
            printf("PRESS ANY KEY TO CONTINUE \n");
            getch();
            system("cls");
            break;

        case 5:
            exit(1);
            return 0;
        }
    }

    // top = push(top, 1);
    // top = push(top, 2);
    // top = push(top, 3);
    // top = push(top, 4);
    // top = push(top, 5);

    // int a = pop(&top);
    // printf("poped element is %d \n", a);

    // printf("LINKED LIST IS....\n");
    // printStackList(top);
    // printf("ENTER THE INDEX \n");
    // scanf("%d",&index);

    // printf("ELEMENT AT INDEX %d is %d",index,peep(top,index));

    // printf("ELEMENT IS %d", top->data);

    return 0;
}