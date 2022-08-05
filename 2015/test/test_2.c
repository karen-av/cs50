#include<cs50.h>
#include<stdio.h>

int sigma(int);
int main(void)
{
    int n;
    do
    {
        n = get_int("give me pos int: ");
    }
    while ( n < 1);
    
    int answer = sigma(n);
    printf("%i\n", answer);
}

int sigma(int m)
{
    int sum = 0;
    for(int i = 1; i <= m; i++)
    {
        sum += i;
    }
    return sum;
}