/*
Cколько воды уходит на душ в зависимости от времени
1 Программа запрашивает у пользователя количество минут, проведенных в душе
2 Пользователь вводит положительное целое число
3 Программа выводит на экран количество бутылочек, израсходованных пользователем.
1 бутылка = 0,5 л
минимально 6 л/мин
*/

// расчет воды c проверкой вводимых хначений

#include<cs50.h>
#include<stdio.h>

int get_min_int(); // обявляем функцию
int get_pow_int();
int main(void)

{
    int m = get_min_int(""); //вызываем функцию
    int p = get_pow_int("");
    int k = p + m; // количество литров за период
    int botl = k*2;
    printf("Вы потратите %i бутылки\n", botl);
}


int get_min_int(void) // задаем функцию для ввода пользователем числа
{
    int x;
    do
    {
    x = get_int("how many minutes (1-10)?:");
    }
    while (x < 1 || x > 10);
    return x;
}

int get_pow_int(void) // задаем функцию для ввода пользователем числа
{
    int x;
    do
    {
        x = get_int("how many power (6-15)?: ");
    }
    while (x < 6 || x > 15);
    return x;
}


