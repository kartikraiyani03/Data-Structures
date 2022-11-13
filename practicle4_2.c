#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

struct Circularlist
{
    int data;
    struct Circularlist *next;
};

struct Circularlist *head = NULL;

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
            struct Circularlist *node;
            struct Circularlist *temp;
            node = (struct Circularlist *)malloc(sizeof(struct Circularlist));
            head = node;
            temp = head;

            printf("ENTER THE NUMBER WHICH YOU WANT TO INSERT \n");
            scanf("%d", num);

            head->data = num;

            for (int i = 1; i < n; i++)
            {
                node = malloc(sizeof(struct Circularlist));
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


void printlist(struct Circularlist *ptr)
{
    struct Circularlist *p = ptr;

    printf("CIRCULAR LIST IS..\n");

    do
    {
        printf("%d \n", ptr->data);
        ptr = ptr->next;

    } while (p != ptr);

    // while (p != ptr)
    // {
    //    printf("%d \n", ptr->data);
    //    ptr = ptr->next;
    // }
    
    printf("\n");
}

struct Circularlist *insertAtFirst(struct Circularlist *first, int val)
{
    struct Circularlist *ptr = (struct Circularlist *)malloc(sizeof(struct Circularlist));
    struct Circularlist *p = first->next;

    ptr->data = val;

    while (p->next != first)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = first;
    first = ptr;
    return first;
}

struct Circularlist *insertAtEnd(struct Circularlist *first, int val)
{

    struct Circularlist *ptr = (struct Circularlist *)malloc(sizeof(struct Circularlist));
    struct Circularlist *p = first;
    ptr->data = val;

    while (p->next != first)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = first;

    return first;
}

struct Circularlist *insertAtIndex(struct Circularlist *first, int val, int index)
{
    struct Circularlist *ptr = (struct Circularlist *)malloc(sizeof(struct Circularlist));
    struct Circularlist *p = first;

    int i = 1;
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

struct Circularlist *insertAfterNode(struct Circularlist *first, struct Circularlist *beforeNode, int val)
{
    struct Circularlist *ptr = (struct Circularlist *)malloc(sizeof(struct Circularlist));
    ptr->data = val;
    ptr->next = beforeNode->next;
    beforeNode->next = ptr;
    return first;
}

 struct Circularlist *insertBeforeNode(struct Circularlist *first, struct Circularlist *AfterNode, int val)
{
    struct Circularlist *ptr = (struct Circularlist *)malloc(sizeof(struct Circularlist));
    struct Circularlist *p = first;
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

struct Circularlist *delation(struct Circularlist *first)
{

    struct Circularlist *ptr = first;
    first = first->next;
    free(ptr);

    return first;
}

 struct Circularlist *delationatEnd(struct Circularlist *first)
{
    struct Circularlist *p = first;
    struct Circularlist *q = p->next;

    while (q->next != first)

    {
        p = p->next;
        q = q->next;
    }

    p->next = first;
    free(q);

    return first;

}

struct Circularlist *delationatNode(struct Circularlist *first, int val)
{
    struct Circularlist *p = first;
    struct Circularlist *q = first->next;

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

 struct Circularlist *delationBeforeNode(struct Circularlist *first, struct Circularlist *AfterNode)
{
    struct Circularlist *p = first;
    struct Circularlist *q = first->next;

    while (q->next != AfterNode)
    {
        p = p->next;
        q = q->next;
    }
    p->next = AfterNode;
    free(q);
    return first;
}

 struct Circularlist *delationAfterNode(struct Circularlist *first, struct Circularlist *BeforeNode)
{
    struct Circularlist *p = first->next;
    struct Circularlist *q = first;

    while (p->next != BeforeNode->next)
    {
        p = p->next;
        q = q->next;
    }
    BeforeNode->next = p;
    free(q);

    return first;
}

 struct Circularlist *search(struct Circularlist *first, int val)
{
    struct Circularlist *ptr = first;
    int i = 0;

    while (ptr->data != val)
    {
        ptr = ptr->next;
        i++;
    }

    if (ptr->data == val)
    {
        printf("The data of the Node is %d \n", ptr->data);
        printf("The Index of the Node is %d \n", i);
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

    struct Circularlist *first;
    struct Circularlist *second;
    struct Circularlist *third;
    struct Circularlist *fourth;
    struct Circularlist *fifth;

    first = (struct Circularlist *)malloc(sizeof(struct Circularlist));
    second = (struct Circularlist *)malloc(sizeof(struct Circularlist));
    third = (struct Circularlist *)malloc(sizeof(struct Circularlist));
    fourth = (struct Circularlist *)malloc(sizeof(struct Circularlist));
    fifth = (struct Circularlist *)malloc(sizeof(struct Circularlist));

    first->data = 1;
    first->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = first;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = first;



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
            first = insertAtFirst(first, element);
            system("cls");
            break;

        case 3:

            printf("ENTER THE ELEMENT WHICH YOU WANT TO INSERT \n");
            scanf("%d", &element);
            first = insertAtEnd(first, element);
            system("cls");
            break;

        case 4:
            printf("ENTER THE INDEX AT WHICH YOU WANT TO INSERT \n");
            scanf("%d", &index);
            printf("ENTER THE ELEMENT WHICH YOU WANT TO INSERT \n");
            scanf("%d", &element);
            first = insertAtIndex(first, element, index);
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
    // first = insertAtfirst(first,45);
    // first = insertAtEnd(first,45);
    // first = insertAtIndex(first, 34, 2);
    // first = insertAfterNode(first, second, 56);
    // first = insertBeforeNode(first , first, 678);
    // first = delation(first);
    // first = delationatEnd(first);
    // first = delationatNode(first,2);
    // first = delationBeforeNode(first,third);
    // first = delationAfterNode(first,third);
    // first = search(first,2);
    // printlist(first);


    return 0;
}