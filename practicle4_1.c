#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

struct linkedlist
{
    int data;
    struct linkedlist *next;
};

struct linkedlist *head = NULL;

void CreateLinkedList()
{
    if (head == NULL)
    {

        int num;
        int n;

        printf("ENTER THE NUMBER OF NODES \n");
        scanf("%d", &n);

        if (n != 0)
        {
            struct linkedlist *node;
            struct linkedlist *temp;
            node = (struct linkedlist *)malloc(sizeof(struct linkedlist));
            head = node;
            temp = head;

            printf("ENTER THE NUMBER WHICH YOU WANT TO INSERT \n");
            scanf("%d", num);

            head->data = num;

            for (int i = 1; i < n; i++)
            {
                node = malloc(sizeof(struct linkedlist));
                temp->next = node;
                printf("ENTER THE NUMBER WHICH YOU WANT TO INSERT \n");
                scanf("%d", &num);
                node->data = num;
                temp = temp->next;
            }

            printf("LIST CREATED SUCCESFULLLY !! \n");
        }
    }
    else
    {
        printf("LIST IS ALREADY EXIST \n");
    }
}

void printlist(struct linkedlist *ptr)
{

    printf("LIST IS..\n");

    while (ptr != NULL)
    {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct linkedlist *insert(struct linkedlist *first, int val)
{

    struct linkedlist *ptr = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    ptr->next = first;
    ptr->data = val;
    return ptr;
}

struct linkedlist *insertatEnd(struct linkedlist *first, int val)
{

    struct linkedlist *ptr = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    struct linkedlist *p = first;
    ptr->data = val;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;

    return first;
}

struct linkedlist *insertatIndex(struct linkedlist *first, int val, int index)
{
    struct linkedlist *ptr = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    struct linkedlist *p = first;

    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    ptr->data = val;

    return first;
}

struct linkedlist *insertAfterNode(struct linkedlist *first, struct linkedlist *beforeNode, int val)
{
    struct linkedlist *ptr = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    ptr->data = val;
    ptr->next = beforeNode->next;
    beforeNode->next = ptr;
    return first;
}

struct linkedlist *insertBeforeNode(struct linkedlist *first, struct linkedlist *AfterNode, int val)
{
    struct linkedlist *ptr = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    struct linkedlist *p = first;
    while (p->next != AfterNode)
    {
        p = p->next;
    }
    ptr->data = val;
    ptr->next = p->next;
    p->next = ptr;

    // ptr->data = val;
    // AfterNode = first->next;
    // ptr->next = AfterNode;
    // first = ptr;
    return first;
}

struct linkedlist *delation(struct linkedlist *first)
{
    struct linkedlist *ptr = first;
    first = first->next;
    free(ptr);

    return first;
}

struct linkedlist *delationatEnd(struct linkedlist *first)
{
    struct linkedlist *p = first;
    struct linkedlist *q = p->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);

    return first;
}

struct linkedlist *delationatNode(struct linkedlist *first, int val)
{
    struct linkedlist *p = first;
    struct linkedlist *q = first->next;

    while (q->data != val)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == val)
    {
        p->next = q->next;
        free(q);
    }
    else
    {
        printf("VALUE NOT FOUND \n");
    }

    return first;
}

struct linkedlist *delationBeforeNode(struct linkedlist *first, struct linkedlist *AfterNode)
{
    struct linkedlist *p = first;
    struct linkedlist *q = first->next;

    while (q->next != AfterNode)
    {
        p = p->next;
        q = q->next;
    }
    p->next = AfterNode;
    free(q);
    return first;
}

struct linkedlist *delationAfterNode(struct linkedlist *first, struct linkedlist *BeforeNode)
{
    struct linkedlist *p = first->next;
    struct linkedlist *q = first;

    while (p->next != BeforeNode->next)
    {
        p = p->next;
        q = q->next;
    }
    BeforeNode->next = p;
    free(q);

    return first;
}

struct linkedlist *search(struct linkedlist *first, int val)
{
    struct linkedlist *ptr = first;
    int i = 0;

    while (ptr->data != val)
    {
        ptr = ptr->next;
        i++;
    }

    if (ptr->data == val)
    {
        printf("The data of the Node is %d \n", ptr->data);
        printf("The Index of the Node is %d", i);
    }
    else
    {
        printf("NODE NOT FOUND \n");
    }
}

int main()

{

    int index;
    int value;
    int ch;
    int element;

    struct linkedlist *first;
    struct linkedlist *second;
    struct linkedlist *third;
    struct linkedlist *fourth;
    struct linkedlist *fifth;

    first = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    second = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    third = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    fourth = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    fifth = (struct linkedlist *)malloc(sizeof(struct linkedlist));

    first->data = 1;
    first->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = NULL;

    while (1)
    {

        printf("\n");
        printf("NAME : KARTIK RAIYANI   ENROLLMENT NO. : 210210116019   \n");
        printf("\n");
        
        printf("1.  CREATE A LIST \n");
        printf("2.  INSERT THE ELEMENT AT BEGINING \n");
        printf("3.  INSERT THE ELEMENT AT THE END \n");
        printf("4.  INSERT AT INDEX \n");
        printf("5.  INSERT AFTER A NODE \n");
        printf("6.  INSERT BEFORE A NODE \n");
        printf("7.  DELATION AT BEGINING \n");
        printf("8.  DELATION AT END \n");
        printf("9.  DELATION AT INDEX \n");
        printf("10. DELATION BEFORE NODE \n");
        printf("11. DELATION AFTER NODE \n");
        printf("12. SEARCH THE NODE \n");
        printf("13. DISPLAY \n");
        printf("14. EXIT \n \n");

        printf("ENTER YOUR CHOICE.. \n");
        scanf("%d", &ch);

        switch (ch)

        {

        case 1:
            CreateLinkedList();
            break;

        case 2:
            printf("ENTER THE ELEMENT WHICH YOU WANT TO INSERT \n");
            scanf("%d", &element);
            first = insert(first, element);
            system("cls");
            break;

        case 3:

            printf("ENTER THE ELEMENT WHICH YOU WANT TO INSERT \n");
            scanf("%d", &element);
            first = insertatEnd(first, element);
            system("cls");
            break;

        case 4:
            printf("ENTER THE INDEX AT WHICH YOU WANT TO INSERT \n");
            scanf("%d", &index);
            printf("ENTER THE ELEMENT WHICH YOU WANT TO INSERT \n");
            scanf("%d", &element);
            first = insertatIndex(first, element, index);
            system("cls");
            break;

        case 5:
            printf("ENTER THE ELEMENT WHICH YOU WANT TO INSERT AFTER NODE \n");
            scanf("%d", &element);
            first = insertAfterNode(first, second, element);
            system("cls");
            break;

        case 6:
            printf("ENTER THE ELEMENT WHICH YOU WANT TO INSERT BEFORE NODE \n");
            scanf("%d", &element);
            first = insertBeforeNode(first, second, element);
            system("cls");
            break;

        case 7:
            delation(first);
            system("cls");
            break;

        case 8:
            delationatEnd(first);
            system("cls");
            break;

        case 9:
            printf("ENTER THE INDEX AT WHICH YOU WANT TO DELATION \n");
            scanf("%d", index);
            delationatNode(first, index);
            system("cls");
            break;

        case 10:
            delationBeforeNode(first, second);
            system("cls");
            break;

        case 11:
            delationAfterNode(first, second);
            system("cls");
            break;

        case 12:
            printf("Enter the value of the node you want to found \n");
            scanf("%d", value);
            search(first, value);

        case 13:
            system("cls");
            printlist(first);
            printf("PRESS ANY KEY TO CONTINUE \n");
            getch();
            system("cls");
            break;

        case 14:
            exit(1);

        default:
            printf("invalid choicen \n");
        }
    }

    // printlist(first);
    // first = insert(first, element);
    // first = insertatIndex(first,element,2);
    // printlist(first);
    // first = insertatEnd(first, element);
    // first = insertAfterNode(first,second,element);
    // first = delation(first);
    // printlist(first);
    // first = delationBetween(first ,2);
    // first = delationatEnd(first);
    // printlist(first);

    return 0;
}
