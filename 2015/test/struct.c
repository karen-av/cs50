#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#include"struct.h"

#define ST 2
char checkname(char *ch);
char checkid(char *ch);
int main()
{
    char *std = malloc(sizeof(char));
    printf("How many students in the class?: ");
    scanf("%s", std);
    int xx = atoi(std);

    FILE *fileopen = fopen("struct.txt", "w");
    if (fileopen == NULL)
    {
        printf("Err create file. Try again.\n");
        return 1;
    }

    char *getname = malloc(sizeof(char));  
    char *getid = malloc(sizeof(char));
    char *getphone = malloc(sizeof(char));
    char *gethouse = malloc(sizeof(char));
    int n = 0;
    

    for(int i = 0; i < xx; i++)
    {
        student ko[i];

        printf("Get name %i: \n", i + 1);
        scanf("%s", getname);
        checkname(getname);
        ko[i].name = *&getname;

        printf("Get id %i: \n", i + 1);
        scanf("%s", getid);
        checkid(getid);
        ko[i].id = *&getid;

        printf("Get phone %i: \n", i + 1);
        scanf("%s", getphone);
        checkid(getphone);
        ko[i].phone_nomber = *&getphone;

        printf("Get house %i: \n", i + 1);
        scanf("%s", gethouse);
        ko[i].house = *&gethouse;

        //printf("Name: %s, id: %s, Phone: %s, House: %s\n", *&ko[i].name, ko[i].id, ko[i].phone_nomber, *&ko[i].house);
        fprintf(fileopen, "Student #%i.\nName: %s\nid: %s\nPhone: %s\nHouse: %s\n",  (i + 1), ko[i].name, ko[i].id, ko[i].phone_nomber, ko[i].house);
    }
    fclose(fileopen);
    free(getname);  
    free(getid);
    free(getphone);
    free(gethouse);
}

//Функция проверки вводимых значений
char checkname(char *ch)
{
    for (int i = 0; i < strlen(ch); )
    {
       if(isdigit(ch[i]) || (strlen(ch) > 10))
        {
            printf("Try again: ");
            scanf("%s", ch);
            i = 0;
        }
        else
        {
            i++;
        }
    }
        return *ch;
}

//Функция проверки вводимых значений
char checkid(char *ch)
{
    for (int i = 0; i < strlen(ch); )
    {
       if(isalpha(ch[i]) || (strlen(ch) > 5))
        {
            printf("Try again: ");
            scanf("%s", ch);
            i = 0;
        }
        else
        {
            i++;
        }
    }
    return *ch;
}



 /** printf("%p,\n%s,\n%c.\n", getname, getname, *getname);
    char y[10]; */

     /**  typedef struct 
    {
        char *name;
        char *id;
        char *phone_nomber;
        char *house;
    }
    student; */