#include<cs50.h>
#include<stdio.h>

int main(void)

//просит число и определяет положительное или нет. пишет ответ 

{
    printf("I'd like an integer please: ");
    int n = get_int(" ");

   if (n > 0)
    {
        printf("You picked a positive number!\n");
    }
    else if (n == 0)
    {
        printf("You picked zero!\n");
    }
    else if (n < 0)
    {
        printf("You picked a negative number!\n");
    }
}