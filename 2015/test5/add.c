/**
 * @file add.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-29
 * 
 * @copyright Copyright (c) 2022
 * 
 * Указатели на структуруб содержащую указатели
 * https://computer.howstuffworks.com/c32.htm
 * 
 * Если s название структуры, то ставим .
 * Если sd указатель на структуру, то ставим ->
 * 
 * struct mystrucr s;
 * struct mystruct *sd;
 * 
 * s.fild = 1;
 * sd->fild = 1;
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>


int main()
{
    typedef struct
    {
        char name[21];
        char sity[21];
        char phone[21];
        char *comment;
        /**
         * этот же тип, то его необходимо объявлять явно с 
         * использованием служебного слова struct
         * Струткура указывает на структуру
         * */
        struct Addr *next; 
    } Addr;

    Addr * first;
    Addr *s;
    
    char comm[100];
     s = (Addr *) malloc(sizeof(Addr));
     strcpy(s->name, "20");
     strcpy(s->sity, "20");
     strcpy(s->phone, "20");
     strcpy(comm, "100");
     s->comment = (char *) malloc(sizeof(char[strlen(comm) + 1]));
     
     // strcpy копирует строку и вставляет строку  (куда, откуда)
    strcpy(s->comment, comm);

    
}
