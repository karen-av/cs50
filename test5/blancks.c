/**
 * @file blancks.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-30
 * 
 * @copyright Copyright (c) 2022
 * Удаляет начальные пробелы без перемещения
 */

#include <stdio.h>
#include <string.h>

int main()
{
    char s[100],*p;
     gets(s);
    p=s;
    while (*p==' ')
    
    p++;
    printf("%s\n",p);
    
    return 0;
}