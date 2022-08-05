/**
 * @file struct-3.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-09
 * 
 * @copyright Copyright (c) 2022
 * 
 * Тип данных очередь
 * Первый пришел и первый ушел
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    int front;
    int *x;
    int size;
}
queue;

void print(queue *h);
int create(queue *h);
int add(queue *h);
int del(queue *h, int *t);



int main(void)
{
    queue * st = (queue*) malloc(sizeof(queue));
    st->x = malloc(10 * sizeof(int));
    st->size = 0;
    st->front = 0;
    int *t = malloc(sizeof(int));

    create(st);
    print(st);

    add(st);
    print(st);

    printf("Del 1-st int...\n");
    del(st, t);
    print(st);
    printf("(del)x = %i\n", *t);

    free(t);
    free(st->x);
    free(st);
    return 0;
}

//Del
int del(queue *h, int *t)
{
    
    if (h->size > 0)
    {
        *t = h->x[h->front];
        h->size--;
        h->front++;

        return 0;
        
    }
    else
    {
        printf("Have not array\n");
        return 1;
    }
}

//Adding
int add(queue *h)
{
    int *x = (int*)malloc(sizeof(int));
    if(!x)
    {
        printf("Err add\n");
        return 4;
    }
    if(h->size < 10)
    {
        printf("Get int to add: ");
        scanf("%i", x);
        h->x[h->size] = *x;
        h->size++;
    return 0;
    }

    else
    {
        printf("Err add 2\n");
        return 12;
    }

    free(x);
    
}

//Create
int create(queue *h)
{
    int *n = (int *) malloc(sizeof(int));
    if (!n) 
    {
        return 2;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("Giv in: ");
        scanf("%d", n);
        h->x[h->size] = *n;
        h->size++;
    }

    printf("\n");
    free(n);
    return 0;
}

//Выводим на печать стек
void print(queue *h)
{
    printf("Printing ...\n");
    for(int i = 0; i < h->size; i++)
    {
        printf("n[%i] - %i\n", h->front + i, h->x[i + h->front]);
    }
    printf("Size %i\n\n", h->size);
}
