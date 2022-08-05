#include<stdio.h>

int main()
{
    FILE *file;
    char r [12];
    for(int i = 0; i < 2; i++)
    {   
        //sprintf(r, "file_%i.txt", i); // название файла через char
        printf("Введите название файла\n");
        scanf("%s", r);
        //puts(r);
        file = fopen(r, "w");
        fprintf(file, "Hellocc world %i!", i);
    }
    for(int i = 5; i < 7; i++)
    {   
        sprintf(r, "file_%i.txt", i); // название файла через char
        //printf("Введите название файла\n");
        //scanf("%s", r);
       // puts(r);
        file = fopen(r, "w");
        fprintf(file, "Hellocc world %i!", i);
    }


    
    fclose(file);
}