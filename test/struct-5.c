/**
 * @file struct-4.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-05-11
 *
 * @copyright Copyright (c) 2022
 *
 * хеш таблица
 * коллизия решина мотодом цепочек (связанным списком)
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>

// структура данных linked
typedef struct node
{
    char *s;
    struct node * next;
    struct node * down;
}node_t;

int add(node_t *h);
int addTab(node_t *h, char* n);
void print(node_t *h);
int hash_fun(char *k);
int linked(node_t *h, char* s);
bool search(node_t *h, char* s);
bool search2(node_t *h, char* s, char *n);
void freeFunc(node_t *h, char *n);

int main(void)
{
    // указатель на структуру данных
    node_t * head = (node_t *) malloc(sizeof(node_t));
    head->s = malloc(sizeof(char));
    if(!head || !head->s) // проверяем ошибку при создании
    {
        printf("Not creade!\n");
        return 1;
    }
   
   //Создаем таблицу        
   char *nn = malloc(sizeof(char));
   printf("Хеш таблица. Цепочки.\nСколько строк будкт в таблице? ");
   scanf("%s", nn);
   while(!isdigit(*nn))
   {
        printf("1. Get int one more time: ");
        scanf("%s", nn);
   }
   addTab(head, nn);

    // Запрашиваем у пользователя сколько слов он хочет внести с таблицу
    char n[100];
    printf("Сколько слов сразу добавить в таблицу? ");
    scanf("%s", n);
    //Проверяем введенное число
    while (!isdigit(*n) || atoi(n) > 100 || atoi(n) < 1)
    {
        printf("2.Get positive int: ");
        scanf("%s", n);
    }

    int num = atoi(n);

    //Вносим слова в таблицу через вызов функции add
    for(int i = 0; i < num; i++)
    {
        add(head);
    }
    print(head);

    //Ищем слово в hash таблице
    char *s = malloc(sizeof(char));
    if(!s)
    {
        printf("Not creade!\n");
        return 31;
    }
    printf("What word do you wont  to search? ");
    scanf("%s", s);
    // Проверка  Воодимое слово долно начинаться с буквы
    while(!isalpha(*s))
    {
        printf("Get string one more time: ");  
        scanf("%s", s); 
    }
    if(search2(head, s, nn))
    printf("Search\n");
    else printf("Not search\n");


    free(s);
    free(nn);
    freeFunc(head, nn);
   
    return 0;
}

// hash функция
int hash_fun(char *k)
{
    //Проставя функция по разнице значений заглавных букц в таблице ASCII
    
    int hash;
    if(isalpha (k[0]))
        hash = toupper(k [0]) - 'A'; 
    if(!isalpha (k[0]))
        hash = 26;

    return hash;
}

//добавляем слова в хеш функцию
int add(node_t *h)
{
    // Создаем указатель на таблицу
    node_t * st = h; 

    //Запрашиваем у пользователя слово для добавления
    char *str = malloc(sizeof(char));
    if(!str) 
    {
        printf("Not creade!\n");
        return 2;
    }
    printf("Get string ");
    scanf("%s", str);

    // Проверка  Воодимое слово долно начинаться с буквы
    while(!isalpha(*str))
    {
        printf("Get string one more time: ");  
        scanf("%s", str); 
    }

    //Определяем индекс через хуш функцию
    int hash = hash_fun(str);
    int i = 0;
    int num = 0;

    ////С помощью индекса определяем в какую ячейку поместить слово
    while(st && num == 0)
    {
       if(hash == i)
       {
            while(isalpha(*st->s)) // Пока в ячейке есть буквенный символ
            {
                if(st->next != NULL)    //Если существует следущая структура с связанном списке, то переходим к ней
                {
                    st = st->next;
                }
                
                else   //Если следующей структуры нет, то создаем еее
                {
                    st->next = (node_t*) malloc(sizeof(node_t));
                    st->next->s = malloc(sizeof(char));
                    if(!st->next || !st->next->s) //Проверка     
                    {
                        printf("Not creade linked!\n");
                        return 3;
                    }

                    st = st->next;  //Переходим к созданной структуре
                }
            }
                strcpy (st->s, str);  //записываем слово
                num++;
       }
       else if(st->down)
       {
           st = st->down;
           i++;
       }
       else
       {
           printf("Слово не добавлено!\n");
           num++;
       }
    }
/**
    //С помощью индекса определяем в какую ячейку поместить слово
    if(hash == 0)
    {
        // использем функцию
        linked(st, str);
    }

    else if(hash == 1)
    {
        st = st->down;
        linked(st, str);
    }

    else if(hash == 2)
    {
        st = st->down->down;
        linked(st, str);
    }
*/
    free(str);
    return 0;
}

//Печатаем хеш таблицу
void print(node_t *h)
{
    node_t * sd = h;
    int i = 0;
    while(sd)
    {
        node_t * sn = sd;
        printf("%i", i);
        while (sn)
        {
            printf("->%s", sn->s);
            sn = sn->next;
        }
        printf("\n");
        sd = sd->down;
        i++;
    }
}

//Горизонтальное увеличение списка
int linked(node_t *h, char* s)
{
    node_t* st = h;
    while(st->s)
        {
            //Если существует следущая структура с связанном списке, то переходим к ней
            if(st->next != NULL)
            {
                st = st->next;
            }
            //Если следующей структуры нет, то создаем еее
            else
            {
                st->next = (node_t*) malloc(sizeof(node_t));
                if(!st->next) 
                {
                    printf("Not creade linked!\n");
                    return 3;
                }
                //Переходим к созданной структуре
                st = st->next;
            }
        }
        //записываем слово
        st->s = s;
        return 0;
}

//Search ищем нужное слово в хеш таблице(плохо работает) переписать на поиск по всех таблице
bool search(node_t *h, char* str) 
{
    node_t *st = h;
    int k = hash_fun(str);

    //С помощью хеш функции определяем индекс и переходм к соответствующему связанному списку
    if (k == 0)
    {
        //если узлы закончились или узла нет, возвращаем false
        while(st)
        {
            //Проверяем слово  Если слово идентично, то возвращаем true
            if(strcmp(st->s, str) == 0)
            return true;
            
            //Если не идентично, то переходим к следующему узлу  
            else
            st = st->next;
        }
    }
    if(k == 1)
    {
        st = st->down;
        while(st)
        {
            if(strcmp(st->s, str) == 0)
            return true;

            else
            st = st->next;
        }
    }
    if(k == 3)
    {
        st = st->down->down;
        while(st)
        {
            if(strcmp(st->s, str) == 0)
            return true;

            else
            st = st->next;
        }
    }
    return false;
}

// Поиск(Хорошоо работает)
bool search2(node_t *h, char *str, char *n) 
{
    node_t *st = h;
    int hash = hash_fun(str);
    int i = 0;
    int nn = atoi(n);
    while( i < hash && hash <= nn)
    {
        st = st->down;
        i++;
    }
    while(st)
    {
        if((strcmp(st->s, str) == 0))
            return true;
        if (st->s != str)
            st = st->next;
    }
    return false;
}

//Создает таблицу
int addTab(node_t *h, char *n)
{
    node_t* st = h;
    int nn = atoi(n) - 1; 
    
    //Первый создали руками двлее по заданному количеству
    for (int i = 0; i < nn; i++)
    {
        st->down = (node_t*) malloc(sizeof(node_t));
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

void freeFunc(node_t *h, char *n)
{
    node_t *st = h;
    node_t *sd = h;
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
        
        sd = st;
        while (sd->next)
        {
            while (sd->next)
            {
                sd = sd->next;
            }
            free(sd->s);
            free(sd);
            sd = st;
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
