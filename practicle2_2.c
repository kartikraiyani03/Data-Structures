#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void push(struct stack *st, char str)

{
    if (isFull(st))
    {
        printf("can not able to push  \n");
    }

    else

    {
        st->top++;
        st->arr[st->top] = str;
    }
}

int pop(struct stack *st)
{

    if (isEmpty(st))
    {
        printf("Can not able to pop \n");
    }

    else
    {
        st->top--;
        return st->arr[st->top];
    }
}

int main()
{
    int i;
    printf("\n");
    printf("NAME : KARTIK RAIYANI   ENROLLMENT NO. : 210210116019   \n");

    char str[30];

    struct stack st;

    st.top = -1;
    st.size = 10;
    st.arr = (int *)malloc(sizeof(int) * 5);

    printf("ENTER THE STRING \n");
    scanf("%s", str);

    for (i = 0; i <= strlen(str); i++)
    {
        push(&st, str[i]);
    }

    for (i = 0; i < strlen(str); i++)
    {
        str[i] = pop(&st);
    }

    printf("%s", str);

    return 0;
}