#include<cs50.h>
#include<stdio.h>

int main(void)
{
    //проверяет четное или нечетное число, которое ввел пользователь

    printf("I'd like an integer please: ");
    int n = get_int("");

    if (n % 2 == 0)
    {
        printf("You picked CHEY!\n");
    }
    else
    {
        printf("You picked NE CHET!\n");
    }

}