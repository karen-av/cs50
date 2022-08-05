#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"students.h"

#define STUDENTS 3

int main(void)
{   
    char *x = malloc(sizeof(char));

    FILE* file = fopen("students.csv", "w");
        if(file == NULL)
        {
            printf("Err file\n");
            return 1;
        }
    

    for(int i = 0; i < STUDENTS; i++)
    {
        students nn[i];
        printf("Student's name:   ");
        nn[i].name = get_string("");

        printf("Student's dorm:   ");
        nn[i].dorm = get_int("");

        fprintf(file, "%s, %i\n", nn[i].name, nn[i].dorm);   
         
    }
    fclose(file);
    //free(nn[0].name);  
    free(x);
}