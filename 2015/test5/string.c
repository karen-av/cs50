#include<stdio.h>
#include<string.h>

int main()
{
    char s1[100], s2[100];
    gets(s1);
    gets(s2);
    if(strcmp(s1, s2) == 0)
    {
        printf("s1 & s2 equal\n");
        return 0;
    }
    else if(strcmp(s1, s2) > 0)
    {
        printf("s1 greater s2 equal\n");
        return 0;
    }
     else if(strcmp(s1, s2) < 0)
    {
        printf("s1 less s2 equal\n");
        return 0;
    }
}