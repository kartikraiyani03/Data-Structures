#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

void menu();
void search();
void adddetail();
void display();
void change();

struct student
{
    char name[50];
    long long int rollno;
    char mobile[10];
    char course[5];
    char branch[25];
};

int main()
{

    printf("\n");
    printf("NAME : KARTIK RAIYANI  ENROLLMENT NO. : 210210116019");
    printf("\n");
    printf("STUDENT RECORDES");
    printf("\n");
    printf("PRESS ANY KEY FOR OPRATION");
    getch();
    menu();
    return 0;
}
void menu()
{

    int choice;
    system("cls");

    printf("MENU - ENTER ONE OF THEM");
    printf("\n");
    printf(" PRESS 1 : ADD DETAIL");
    printf("\n");
    printf("PRESS 2 : DISPLAY");
    printf("\n");
    printf("PRESS 3 : SEARCH");
    printf("\n");
    printf("PRESS 4 : CHANGE RECORD");
    printf("\n");
    printf("PRESS 6 : EXIT");
    printf("\n");
    printf("\n ENTER YOUR CHOICE");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        adddetail();
        break;
    case 2:
        display();
        break;
    case 3:
        search();
        break;
    case 4:
        change();
        break;

    case 6:
        exit(1);
        break;

    default:
        printf("\n");
        printf("PRESS ANY KEY FOR ANOTHER OPERATION ");
    }
}
void add()
{
    FILE *fptr;
    struct student std;

    char loop = 1;

    system("cls");

    fptr = fopen("student.txt", "a");
    if (fptr == NULL)
    {
        printf("\n");
        printf("CAN'T ABLE TO OPEN FILE");
        exit(1);
    }
    fflush(stdin);
    while (loop == 1)
    {
        printf("\n");
        printf("ADD DETAIL OF ANOTHER STUDENT \n");
        printf("\n");
        printf("ENTER DETAILS OF STUDENT");
        printf("\n");
        printf("ENTER THE NAME :");

        gets(std.name);
        printf("\n");
        printf("ENTER MOBILE NUMBER :");
        gets(std.mobile);
        printf("\n");
        printf("ENTER THE ROLL NUMBER :");
        scanf("%lld", &std.rollno);
        fflush(stdin);
        printf("\n");
        printf("ENTER THE COURSE :");
        gets(std.course);
        printf("\n");
        printf("ENTER THE BRANCH :");
        gets(std.branch);
        fwrite(&std, sizeof(std), 1, fptr);
        printf("\n");
        printf("PRESS 1 FOR ADDD DETAILS OR ELSE EXIT");
        fflush(stdin);
        loop = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fptr);
    printf("\n");
    printf("PRESS ANY KEY FOR ANOTHER OPERATION \n");
    getch();
    menu();
}
void display()
{
    FILE *fptr;
    int i = 1, j;
    struct student std;
    system("cls");
    printf("\n");
    printf("DISPLAY THE RECORDE \n");
    printf("\n");
    printf("NO.   NAME       MOBILE NO.    ROLL NO.    COURSE    BRANCH");
    printf("\n");

    fptr = fopen("student.txt", "r");

    if (fptr == NULL)
    {
        printf("\n");
        printf("CAN'T ABLE TO OPEN FILE \n");
    }

    while (fread(&std, sizeof(std), 1, fptr) == 1)
    {

        printf("%-7d%-22s%-12s%-19lld%-12s%-12s", i, std.name, std.mobile, std.rollno, std.course, std.branch);
    }
    fclose(fptr);
    printf("\n");
    ;
    printf("PRESS ANY KEY FOR ANOTHER OPERATION \n");
    getch();
    menu();
}
void search()
{
    FILE *fptr;
    struct student std;
    char stname[20];
    system("cls");
    printf("\n");
    printf("SEARCH THE STUDENT \n");
    printf("\n");
    printf("ENTER NAME OF STUDENT :");
    fflush(stdin);
    gets(stname);
    fptr = fopen("student.txt", "r");
    if (fptr == NULL)
    {
        printf("\n");
        printf("CAN'T ABLE TO OPEN FILE \n");
    }
    while (fread(&std, sizeof(std), 1, fptr) == 1)
    {
        if (strcmp(stname, std.name) == 0)
        {
            printf("\n");
            printf("NAME IS : %s", std.name);
            printf("\n");
            printf("MOBILE NUMBER IS: %s", std.mobile);
            printf("\n");
            printf("ROLL NO IS : %lld", std.rollno);
            printf("\n");
            printf("\n");
            printf("BRANCH IS : %s", std.branch);
        }
        fclose(fptr);
        printf("\n");
        printf("CAN'T ABLE TO OPEN FILE \n");
        getch();
        menu();
    }
}
void change()
{
    char stname[30];
    FILE *fptr;
    struct student std;
    system("cls");
    printf("\n");
    printf("CHANGE THE RECORD \n");
    printf("\n");
    printf("ENTER NAME OF STUDENT TO CHANGE :");
    fflush(stdin);
    gets(stname);
    fptr = fopen("student.txt", "rb+");
    if (fptr == NULL)
    {

        printf("CAN'T ABLE TO OPEN FILE \n");
        exit(1);
    }
    rewind(fptr);
    fflush(stdin);

    while (fread(&std, sizeof(std), 1, fptr) == 1)
    {
        if (strcmp(stname, std.name) == 0)
        {
            printf("\n");
            printf("ENTER NAME :");
            gets(std.name);
            printf("\n");
            printf("ENTER MOBILE NUMBER :");
            gets(std.mobile);
            printf("\n");
            printf("ENTER ROLL NO. :");
            scanf("%lld", &std.rollno);
            printf("\n");
            printf("ENTER COURSE :");
            fflush(stdin);
            gets(std.course);
            printf("\n");
            printf("ENTER BRANCH :");
            fflush(stdin);
            gets(std.branch);
            fseek(fptr, -sizeof(std), SEEK_CUR);
            fwrite(&std, sizeof(std), 1, fptr);
            break;
        }

        fclose(fptr);
        printf("\n");
        printf("CAN'T ABLE TO OPEN FILE \n");
        getch();
        menu();
    }
}
