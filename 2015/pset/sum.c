#include<cs50.h>
#include<stdio.h>

// спрашивает имя и два числа. считает сумму

int main(void)

{
    string s = get_string("What is your name? ");
    printf("Hello, %s!\n", s);

    printf("Give me integer: ");
    int x = get_int("");

    printf("Give me another integer: ");
    int y = get_int("");

    printf("The sum of %i and %i is %i!\n", x, y, x+y);
}
