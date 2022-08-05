/**
 * @file scanf-1.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-07
 * 
 * @copyright Copyright (c) 2022
 * 
 * Принимаем строкове значение от пользователя  
 * Считывает до пробела
 * Замена get_string
 */

#include<stdio.h>
#include<stdlib.h>

int main()

{
    // Первый вариант через массив  заранее выделяем блок памяти
    char word[16];
    printf("Get word: ");
    scanf("%s", word);
    printf("Thanks for word: %s\n", word);

    // вариант через указатель и malloc
    char *wor = malloc(sizeof(char));
    printf("Get wor: ");
    scanf("%s", wor);
    printf("Thanks for wor: %s\n", wor);
    


}