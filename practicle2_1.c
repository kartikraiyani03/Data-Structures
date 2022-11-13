#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

struct stack
{
    int top;
    int size;
    int *arr;
};

int isEmpty(struct stack *st)
{
    if (st->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *st)
{
    if (st->top == st->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *st, int val)
{
    if (isFull(st))
    {
        printf("can not able to push");
    }

    else
    {
        st->top++;
        st->arr[st->top] = val;
    }
}

int pop(struct stack *st)
{
    int a;

    if (isEmpty(st))
    {
        printf("Can not able to pop");
    }

    else
    {
        st->top--;
        return st->arr[st->top];
    }
}

int peep(struct stack *st)
{
    int p;
    printf("ENTER THE POSITION \n");
    scanf("%d", &p);

    if (st->top - p + 1 < 0)
    {
        printf("not valid \n");
    }

    else
    {

        return st->arr[st->top - p + 1];
    }
}

int change(struct stack *st)
{
    int p;
    int element;

    printf("ENTER THE POSITION AT YOU WANT TO CHANGE \n");
    scanf("%d", &p);

    printf("ENTER THE VALUE WHICH YOU WANT TO CHANGE \n");
    scanf("%d", &element);

    if (st->top - p + 1 < 0)
    {
        printf("not valid \n");
        return -1;
    }

    else
    {
        return st->arr[st->top - p + 1] = element;
    }
}

int display(struct stack *st)
{
    if (st->top >= -1)
    {
        printf("ELEMENTS \n \n");

        for (int i = st->top; i > -1; i--)
        {
            printf("%d \n", st->arr[i]);
        }
    }
    else
    {
        printf("EMPTY");
    }
}

int main()
{

    int p;
    int element;
    int num;

    struct stack st;

    st.top = -1;
    st.size = 5;
    st.arr = (int *)malloc(sizeof(int) * st.size);

    int choice;

    while (1)
    {

        printf("\n");
        printf("NAME : KARTIK RAIYANI   ENROLLMENT NO. : 210210116019   \n");
        printf("\n");
        
        printf("1. PUSH \n");
        printf("2. POP \n");
        printf("3. PEEP \n");
        printf("4. DISPLAY \n");
        printf("5. CHANGE \n");
        printf("6. EXIT \n");
        printf("\n");

        printf("ENTER THE CHOICE \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("ENTER THE NUMBER WHICH YOU WANT TO PUSH \n");
            scanf("%d", &num);
            push(&st, num);
            system("cls");
            break;

        case 2:

            pop(&st);
            system("cls");
            break;

        case 3:

            printf("value is %d\n", peep(&st));

            break;

        case 4:

            display(&st);

            break;

        case 5:

            change(&st);
            system("cls");
            break;

        case 6:
            system("cls");

            return 0;
        }
    }

    // push(&st, 1);
    // push(&st, 2);
    // push(&st, 3);
    // push(&st, 4);
    // push(&st, 5);

    // pop(&st);
    // pop(&st);
    // pop(&st);
    // pop(&st);
    // pop(&st);

    // printf("Top is %d \n", st.top);

    // if (isEmpty(&st))
    // {
    //     printf("finally stack is empty \n");
    // }

    // if (isFull(&st))
    // {
    //     printf("finally stack overflow \n");
    // }

    return 0;
}
