#include<cs50.h>
#include<stdio.h>

int main(void) //просит положительное число и печатает столько же знаков вопроса

{
int n;

    do
    {
        n = get_int("Width: ");
    }
    while (n < 1);

    // return n; если оставить эту стрку, то будет просто возвращать "n" и не делать код дальше

   for (int i = 0; i < n; i++)
   {
        printf("?");
   }
   printf("\n");
}
