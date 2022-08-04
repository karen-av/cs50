
#include<cs50.h>
#include<stdio.h>

float get_positive_float();
int main(void)

{
printf("O Hai! ");

    float f = get_positive_float("");   // получаем от пользователя
    int g = f * 100;


        int k = g % 25; // остаток
        int l = g / 25; // шт по 25 центов

        int h = k % 10; // остаток
        int d = k / 10; // шт по 10 центов

        int w = h % 5;
        int e = h / 5;

        int t = w % 1;
        int y = w / 1;

        //int how = l + d + e + y; // общее количество монет

        //printf("%.2f\n", f); // выводит мелочь с двумя знаками после ,
        printf("%i\n", l + d + e + y); // выводит количество монет
}

float get_positive_float(void)    // функция параметров запрашиваемого числа
{
    float x;
    do
    {
    x = get_float("How much change is owed?: \n");
    }
    while (x < 0 || x > 1 || x == 1);
    return x;
}