#include<stdio.h>


int swap(int *i, int *j);
int main(void)
{
    int a, b; 

    a = 5;
    b = 10;
    printf("a = %d, b = %d\n", a, b);

    //передаем адреса
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);
}

int swap(int *i, int *j) // функция принимает указатели
{
    int t;

    t = *i;
    *i = *j;
    *j = t;
    return *i;
    return *j; 
}