#include<stdio.h>
#include<cs50.h>

int sigma(int);


int main(void)
{
    int x = get_int("Get int positive:  ");
    int y = sigma(x);
    printf("%i\n", y);
}

int sigma(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    else
    {
      return (n + sigma(n-1));
    }
}

