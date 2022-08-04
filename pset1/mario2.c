
#include<cs50.h>
#include<stdio.h>

int get_positive_int();
int main(void)

// строим наклонную стену по заданному пользователем числу у этажей
// правильный вариант

{
    int n = get_positive_int("");                                           //вызывает функцию прописанную внизу
    printf("Heigth %i!\n", n);

    for (int i = 0; i < n; i++)                                              //делает строки
    {
        for (int p = n - i; p > 1; p--)                                     //делает отступ слева. выравнивает по правому краю
            {
                printf(" ");
            }
        for (int f = i+1; f > 0 || f == 0; f--)                             //делает #
            {
                printf("#");
            }
        printf("\n");
    }
}


int get_positive_int(void)                                                  // функция параметров запрашиваемого числа
{
    int x;
    do
    {
    x = get_int("Positive int, please!: ");
    }
    while (x < 0 || x > 23);
    return x;
}