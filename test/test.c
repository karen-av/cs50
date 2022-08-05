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
    if ( m <= 0)
    {
        return 0;
    }
    else
    {
        return (m + sigma(m - 1));
    }
}



