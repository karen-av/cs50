#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
/**
 * указаетль и указуемое создаются отдельно
 * */


int main(void)
{
    int* x;  //указатель
    int* y;

    x = malloc(sizeof(int)); // указуемое
    *x = 42;
    y = x; // храним в y тот же адрес, что и в x
    *y = 13;

}