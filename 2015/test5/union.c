/**
 * @file union.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-04
 * 
 * @copyright Copyright (c) 2022
 * 
 * Union - объединения  
 * Можно использовать только что-то одно из объединения в конкретном месте  
 */

#include<stdio.h>

int main()
{
    union mix
    {
        char *x;
        float y;
        int i;
    };

    union mix k;
    k.i = 38;
    k.y = 3.4;
    k.x = "Hi";
    printf("union mix i - %d\n", k.i);
    printf("union mix y - %.3f\n", k.y);
    printf("union mix y - %s\n", k.x);
    
}