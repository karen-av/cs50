#include<cs50.h>
#include<stdio.h>

int swap(int a, int b);
int main(void)
{
    int x = 10, y = 2;
    y = swap(x, y);
    
    printf("x it is %i\n", x);
    printf("y it is %i\n", y);

}

int swap(int a, int b)
{
    int swp = a;
    a = b;
    b = swp;
    printf("x - %i\n", a);
    printf("y - %i\n", b);

    return a;
    return b;

}
