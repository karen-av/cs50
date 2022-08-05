#include<stdio.h>

int main()
{
    FILE* f;
    f= fopen("new", "r");
    char s[1000];
    while (fgets(s, 1000, f) != NULL)
    {
        printf("%s", s);
    }

    fclose(f);
    return 0;
    
}