#include<cs50.h>
#include<stdio.h>

int get_positive_int(); //объявляем функцию
int main(void)

//просим пользователя написать положительное число

{
    int n = get_positive_int(""); // вызываем функцию
    printf("Thanks for the %i!\n", n);
}

int get_positive_int(void) // прописываем функцию
{
    int n;
    do
    {
    n = get_int("Give me positive int: ");
    }
    while (n < 1);
    return n;
}