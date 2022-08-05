



#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#include "dictionary.h"
#define DICTIONARY "dictionaries/small"

typedef struct node
{
    char s[2];
    bool is_word;
    struct node * next[27];
} node;

int hash_fun(char *k);
int add(node *h, char *key);
int createTrie (node *h);
bool search(node *h, char *s);

int main ()
{
    node* head = (node*) malloc(sizeof(node));
    if(!head) //Проверка
        {
            printf("Err create head\n");
            return 1;
        }
    //Создаем структуру данных
    createTrie (head);
    
    //Переменная для приема слов из словаря
    char *word = malloc(sizeof(char));
    //Открываем файл для чтения
    FILE *fp = fopen(DICTIONARY, "r");
    if(!fp)//Проерка на ошибку открытия
    {
        printf("Ошибка при открытии файла\n");
        return 1;
    }
    int c = 0;
    do 
    {
        //Считываем символы и сохраняем в char до \0 или конца строки
        fgets(word, 45, fp);    
        //выводим на экрасн значение типа char
       // puts(word);
        //Передаем считанное слово в структуру данных для сохранения в дереве
        add(head, word);
        //Передаем переменной данные положения курсора
        c = fgetc(fp);
        //Сдвигаем курсор назад
        fseek(fp, -1, SEEK_CUR);
    } 
    while(c != EOF); // делаем пока не дойдем до конца файла
    
    //Закрываем файл
    fclose (fp);

    //Ищем слово 
    char *str = malloc(sizeof(char));
    printf("Какое слово будем искать? ");
    scanf("%s", str);

    if(search(head, str) == true)
        printf("Слово найдено!\n");
    else
        printf("Слово не найдено!\n");
    free(str);
    return 0;
}

int hash_fun(char *k)
{
    //Проставя функция по разнице значений заглавных букц в таблице ASCII
    int hash = toupper(k [0]) - 'A'; 
    return hash;
}

int add(node *h, char *key)
{
    node *st = h;
    int hash;
    int str = strlen(key) - 1;
    int ss;
    for(int i = 0; i < str; i++)
    {
        hash = hash_fun(&key[i]);
        if(!st->next[hash])
            st->next[hash] = (node*) malloc(sizeof(node));          
        st = st->next[hash];
        if(!isalpha(st->s[0]))
        {
            ss = (int)key[i];
            st->s[0] = (char)ss; 
        }    
        if( i + 1 == str)
        st->is_word = 1;
    }
    return 0;
}

// создаем первые 27 st->next
int createTrie (node *h)

{
    node *st = h;
    for(int i = 0; i < 27; i++)
    {
       st->next[i] = (node*) malloc(sizeof(node));
        if(st->next[i] == NULL) // Проверка
        {
            printf("Err create st->next[%i]\n", i);
            return 2;
        }
        st = st->next[i];
    }
    //printf("End creating!\n");
return 0;
}

//Поиск
bool search(node *h, char *s)
{
    int n = 0;
    int l = strlen(s);
    node *st = h;
    int hash; 
    while (n < l)
    {
        hash = hash_fun(&s[n]);
        if(st->next[hash])
        {
            st= st->next[hash];
            if((int)st->s[0] == (int)s[n])
                n++;             
        }
        else 
            n = l + 1;
    }
    if(n != l + 1 && st->is_word == 1 )
         return true;       
    else
        return false;
}


//printf("%ld\n", ftell(fp)); Вывод курсора на экран