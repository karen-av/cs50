#include<cs50.h>
#include<stdio.h>

int sigma(int);
int main(void)
{
    int a = 5;
    int b = 2;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    printf("%i\n", a);
    printf("%i\n", b);
}
