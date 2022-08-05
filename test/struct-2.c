/**
 * @file struct-2.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-09
 * 
 * @copyright Copyright (c) 2022
 * 
 * Steck
 * Структура данных стек
 * Последний пришел и первым ушел
 * Как подносы в столовой
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int *x;
    int size;
}
stack;

void print(stack *h);
int create(stack *h);
int add(stack *h);
int del(stack *h);

int main(void)
{
    stack st;
    int *nom = (int*)malloc(sizeof(int));
    if (!nom)
    {
        printf("nom error.\n");
        return 1;
    }
    printf("How manu value? ");
    scanf("%i", nom);
    st.x = (int *) malloc(*nom * sizeof(int));
    st.size = 0;

    //Создаем
    for(int i = 0; i < *nom; i++)
    {
        create(&st);
    }
    printf("\nPrinting stack ...\n");
    //Печатаем содержимое стека
    print(&st);
    printf("\n");

    // добавляем
    add(&st); 
    printf("Printing stack ...\n");
    print(&st);
    printf("\n");

    //Удаляем
    printf("Del last in\n");
    printf("Printing stack ...\n");
    del(&st);
    print(&st);
    printf("\n");

    free(st.x);
    free(nom);
    return 0;
    
}

// Функции 

//Добавляем в стек
int create(stack *h)
{
    int * s = (int*) malloc(sizeof(int));
    if (!s)
    {
        printf("Create new error.\n");
        return 2;
    }
    printf("Giv int: ");
    scanf("%i", s);
    h->x[h->size] = *s;
    h->size++;
    free(s);
    return 0;
}

//Добавляем данные в стек
int add(stack *h)
{
    int *i = (int*) malloc(sizeof(int));
    if (!i) 
    {
        printf("Add i error.\n");
        return 3;
    }

    printf("Giv me int to add: ");
    scanf("%i", i);
    h->x[h->size] = *i; 
    h->size += 1;

   
    free(i);
    return 0;
}

//Удаляем данные
int del(stack *h)
{
    h->size --;
    return 0;
}

//Выводим на печать стек
void print(stack *h)
{
    for(int i = 0; i < h->size; i++)
    {
        printf("n[%i] - %i\n", i, h->x[i]);
    }
    printf("Size %i\n", h->size);
}

