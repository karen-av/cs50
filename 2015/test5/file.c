#include<stdio.h>

#define MAX 10

int main()
{
    int i;
    FILE* f;
    f = fopen("new", "w");
    if(!f)
    {
        printf("Err create new.txt\n");
        return 1;
    }
    for(i = 1; i < MAX; i++)
    {
        fprintf(f, "%d\n", i);
    }

    fclose(f);
    return 0;
}