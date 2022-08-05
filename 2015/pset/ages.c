#include<cs50.h>
#include<stdio.h>

int main(void)

{
    int n;
    do
    {
        n = get_int("How many people in the room?  "); // спрашивает сколько людей в комнате
    }
    while (n < 1);                                  // Проверят чтобы число было положительное

    int ages[n];                                    // обЬявляем массив N

    for (int i = 0; i < n; i++)
    {
        ages[i]=get_int("Age of #%i: ", i+1);
    }

    printf("wait...\n");

    for (int i = 0; i < n; i++)
    {
        printf("Afte ear #%i will be %i years old\n", i+1, ages[i]+1);
    }

    printf("all\n");



}