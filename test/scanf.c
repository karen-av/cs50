/**
 * @file scanf.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-07
 * 
 * @copyright Copyright (c) 2022
 *  Принимаем вводс с клавиатуры и присваеваем значение переменнойй
 */

#include<stdio.h>
#include<stdlib.h>

int main(void)

{
    // первый вариант через указатель
    int *x = (int *) malloc(sizeof(int));
    printf("Get int x: ");
    scanf("%i", x);
    printf("Thanks for x: %i\n", *x);

    //второй вариант через запрос адреса &x
    int i;
    printf("Get int i: ");
    scanf("%i", &i);
    printf("Thanks for i: %i\n", i);



}