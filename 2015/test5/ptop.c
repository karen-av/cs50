/**
 * @file ptop.c
 * @author your name (4010488)
 * @brief 
 * @version 0.1
 * @date 2022-04-29
 * 
 * @copyright Copyright (c) 2022
 * 
 * Указатель на указатель
 * https://computer.howstuffworks.com/c32.htm
 */

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int **p;
    int *q;

    p = (int **) malloc (sizeof(int));
    *p = (int *) malloc (sizeof(int));

    **p = 12;
    q = *p;
    printf("%d\n", *q);

    free(q);
    free(p);

    return 0;

}