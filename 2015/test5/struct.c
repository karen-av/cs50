/**
 * @file struct.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-29
 * 
 * @copyright Copyright (c) 2022
 * Структуры данных
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int main()
{
    // структура
    struct car
    {
        int speed;
        char name[50];
        float weight;
    } bmw, ford; // объекты можно создавать сразу
    

    struct car vw = {120, "vw", 1200.00f};
    printf("Марка %s, скорость %d, Вес %0.1f\n", vw.name, vw.speed, vw.weight);
    bmw.speed = 100;
    ford.speed = 24;
    strcpy(bmw.name, "bmw");
    printf("Скорость %d, Имя %s\n", bmw.speed, bmw.name);

    // псевдоним структуры
    typedef struct car carl;
    
    carl na;
    na.speed = 10;
    printf("Скорость na %d\n", na.speed);

    // псевдоним структуры / структура типа данных
    typedef struct
    {
        int speed;
        int w;
        char name[10];
    } New;
    
    New fr;
    fr.speed = 12;
    New fe;
    fe.speed = 16;
    printf("Скорость fe %d\n", fe.speed);




    return 0;
}