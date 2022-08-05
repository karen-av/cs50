/**
 * @file struct-6.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-05-14
 *
 * @copyright Copyright (c) 2022
 *
 * Хеш таблица
 * Решение коллюзий линейное
 */

typedef struct node
{
    char *s;
    struct node * down;
}node;

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>

void print(node* h, char *n);
int add_create(node *h, char *n);
bool search(node *h, char *str, char *n);
int create (node* h, char *n);
void freFunc(node *h, char *n);
int hash_f(char* k);
int add(node*h, char* str, char *n);
void free_fn (node *h);

int main(void)
{
    //Создаем указатель на массив
    node *head = (node*) malloc(sizeof(node));
    head->s = malloc(sizeof(char));
    if(!head || !head->s) // Проверка
    {
        printf("Not create 1\n");
        return 1;
    }
    //Запрашиваем количество строк в хеш таблице
    char *n = malloc(sizeof(char));
    if(!n) // Проверка
    {
        printf("Not create 2\n");
        return 2;
    }
    printf("Размер таблицфы?: ");
    scanf("%s", n);
    while(!isdigit(*n))
    {
        printf("1. Get int one more time: ");
        scanf("%s", n);
    }
    create(head, n);

    //Принимаем слово для добавления
    printf("Сколько слов добавим в таблицу? ");
    char* k = malloc(sizeof(char));
    if(!k) // Проверка
    {
        printf("Not create 3\n");
        return 3;
    }
    scanf("%s", k);
    //Проверка на букву алфавита
    while(!isdigit(*k) || atoi(k) > atoi(n))
    {
        printf("Get int one more time: ");
        scanf("%s", k);
    }
    int kk = atoi(k);

    //Добавляем слова
    for(int v = 0; v < kk; v++)
    {
        printf("What word do you wont to add? ");
        //Добавить проверку на слово
        add_create(head, n);
    }

    print(head, n);

    //Поиск
    char *ser = malloc(sizeof(char));
    if(!ser) // Проверка
    {
        printf("Not create 4\n");
        return 4;
    }
    printf("Введите слово для поиска: ");
    scanf("%s", ser);
    //Проверка введенного слова
    while(!isalpha(*ser))
    {
        printf("Введите слово, начинающееся с буквы алфавита: ");
        scanf("%s", ser);
    }
    if(search(head, ser, n))
    printf("Слово %s найдено!\n", ser);
    else
    printf("Слово %s не найдено!\n", ser);

    //Добавляем отдельное слово
    printf("Какое слово вы хотите добавить? ");
    char* sew = malloc(sizeof(char));
    if(!sew) // Проверка
    {
        printf("Not create 5\n");
        return 5;
    }
    scanf("%s", sew);
    while(!isalpha(*sew))
    {
        printf("Введите слово, начинающееся с буквы алфавита: ");
        scanf("%s", ser);
    }
    // Добавляем введенное слово через функцию
    add(head, sew, n);

    print(head, n);

    // Еще один поиск
    printf("Введите слово для поиска: ");
    scanf("%s", ser);
    //Проверка введенного слова
    while(!isalpha(*ser))
    {
        printf("Введите слово, начинающееся с буквы алфавита: ");
        scanf("%s", ser);
    }
    if(search(head, ser, n))
    printf("Слово %s найдено!\n", ser);
    else
    printf("Слово %s не найдено!\n", ser);

    //freFunc(head, n);
    free_fn(head);
    free(sew);
    free(ser);
    free(k);
    free(n);

    return 0;
}

//Добавляем отдельное слово
int add(node*h, char* str, char *n)
{
    node* st = h;
    int hash = hash_f(str);
    int i = 0;
    int nn = atoi(n) - 1;
    printf("hash %i\n", hash);

    //Идем к строке по функции если создано достаточно звеньев
    while(i < hash && i < nn && hash <= nn)
    {
        st = st->down;
        i++;
    }
    //Проверяем наличие слова начиная с ячеки по ключу и если создано достаточно звеньев
    int r = 0;
    while(st && r == 0 && hash <= nn)
    {
        //Если логичное место свободно, записываем знаечение в него
        if(!isalpha(*st->s))
        {
            strcpy(st->s, str);
            r++;
        }
        // Если не свободно, ищем следущею свободную ячейку. Пока не закончица таблица
        else
            st = st->down;
    }
    if (r == 1)
    printf("Слово добавлено!\n");
    if (r == 0)
    printf("Слово не добавлено!\n");
    return 0;
}

//Хеш функция
int hash_f(char* k)
{
    int hash;
    if(isalpha (k[0]))
        hash = toupper(k [0]) - 'A'; 
    if(!isalpha (k[0]))
        hash = 26;
    return hash;
}

//Зобавляем слова при создании хеш таблицы
int add_create(node *h, char *n)
{
    char* str = malloc(sizeof(char));
    if(!str) // Проверяем на ошибку
    {
        printf("Error create S\n");
        return 2;
    }

    scanf("%s", str); //Запрашиваем слово
   
    while(!isalpha(*str)) //Проверяем на букву
    {
        printf("Get string one more time: ");
        scanf("%s", str);
    }

    node* st = h;
    int hash = hash_f(str);
    int k = atoi(n) - 1;
    int nn = 0;
    int jj = 0;
    int i = 0;
    //Идем к строке по функции если создано достаточно звеньев
    // i < h контролирует нужное место, i<k чтобы не выйти за пределы таблицы, hash<=k результат функции заведомо в границах таблицы
    while(i < hash && i < k && hash <= k)
    {
        st = st->down;
        i++;
       // printf("i - %i, hash - %i, k - %i\n", i, hash, k);
    }
    // идем к нужной строке, но не далее чем у нас создано звеньев (строк в таблице)
    // nn для контроля факта записи, hash <= k заведомо не выходить за пределы таблицы
    while(nn == 0 && hash <= k)
    {
        while(nn == 0)
        {
            //Если нужная ячейка не занята, заполняем ее. Если ячейка не занята, то в ней нет буквенного симвоала
            if(!isalpha(*st->s))
            {
                strcpy (st->s, str);   
                nn++;
                jj++;
            }
            //Если нужная ячейка занята идем к следующей  Если она создана
            else if(st->down)
            {
                st = st->down;
            }
            //Иначе создаем условие для выхода из while
            else
            {
                nn++;
            }
        }
    }
    //Выводим результат добавления слова
    if (jj == 1)
    printf("Слово добавлено!\n");
    if (jj == 0)
    printf("Слово не добавлено!\n");
    free(str);
    return 0;
}

//Поиск
bool search(node *h, char *str, char *n)
{
    //Создаем указатель на принятый массив
    node *st = h;

    //Расчитывам ключь через функцию
    int hash = hash_f(str);

    //Идем к ячейке по ключу
    int i = 0;
    int nn = atoi(n) - 1;
    while(i < hash && i < nn)
    {
        st = st->down;
        i++;
    }

    //Проверяем наличие слова начиная с ячеки по ключу
    while(st)
    {
        if(st->s != NULL && strcmp(st->s, str) == 0)
            return true;
        // Если нет совпадения идем в след ячейку. Пока не закончица таблица
        else
            st = st->down;
    }
    return false;
}

//Создание хеш таблицы
int create (node* h, char *n)
{
    node* st = h;
    int nn = atoi(n) - 1; 
    
    //Первый создали руками двлее по заданному количеству
    for (int i = 0; i < nn; i++)
    {
        st->down = (node*) malloc(sizeof(node));
        st->down->s = malloc(sizeof(char));
        
        if(!st->down || !st->down->s) //Проверка на ошибку
        {
            printf("Not create st\n");
            return 4;
        }
        st = st->down;
    }
    return 0;
}

//Освобождение памяти
void freFunc(node *h, char *n)
{
    node* st = h;
    int i = 1;
    int l = atoi(n);
    int d = atoi(n);
    for(int k = 1; k < d; k++)
    {
        while(i < l)
        {
            st = st->down;
            i++;
        }
        l--;
        i = 1;
        free(st->s);
        free(st);
        st = h;
    }
    free(st->s);
    free(st);
}

//Печать таблицы
void print(node* h, char* n)
{
    node *st = h;
    int nn = atoi(n);
    int i = 0;
    while(i < nn)
    {
        printf("%i - %s\n", i , st->s);
        st = st->down;
        i++;
    }
}

void free_fn (node *h)
{
    if(h)
    {
        while(h->down)
        {
            free_fn(h->down);
            h->down->s = NULL;
            h->down = NULL;
        }
    }
    free(h->s);
    free(h);
}