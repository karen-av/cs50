#include<stdio.h>
#include<cs50.h>

void swapp(int* a, int* b);
int main(void)

{
    int x = 1;
    int y = 2;
    int z = 3;
    printf("x is %i\n", x);
    printf("y is %i\n", y);
    printf("Swapping...\n");
    swapp(&x, &y);
    printf("Swapped!\n");
    printf("x is %i\n", x);
    printf("y is %i\n", y);
}

void swapp(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}