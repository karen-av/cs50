/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 * 
 * сделано на префиксном дереве
 * 
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//#include<crtdbg.h>

#include "dictionary.h"

int hash_fun(const char *k);
int add(node *h, char *key);
int createTrie (node *h);
bool load(const char* dictionary);
bool search(node *h, char *s);
bool unload(void);
void freeFunc(node *h);


/**
 * Returns true if word is in dictionary else false.
 * Взял реалиацию своей функции search
 */
bool check(const char* word)
{
    
    int n = 0;
    int l = strlen(word);
    node *st = head;
    int hash; 
    //printf("\n1\n");
    while (n < l && n < 46)
    {
       // printf("2\n");
        hash = hash_fun(&word[n]);
        if(st->next[hash])
        {
           //printf("3\n");
            st= st->next[hash];
            if((int)tolower(st->s[0]) == (int)tolower(word[n]) || (int)(st->s[0]) == (int)(word[n]))
                n++;  
            else
                n = l + 2;           
        }
        else 
            n = l + 2;
    }
    if(n != l + 2 && st->is_word == 1)
         return true;       
    else 
        return false;

     //  return true;
        
} //strcat соединяте две строки

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 * загружаем библиотеку в струкуру данных
 */
bool load(const char* dictionary)
{
      //Создаем структуру данных
    head = (node*) malloc(sizeof(node)); 
    if(!head) //Проверка
        {
            printf("Err create head\n");
            return 1;
        }
    createTrie (head);
    //Переменная для приема слов из словаря
    char *word = malloc(sizeof(char));
    //Открываем файл для чтения
    FILE *fp = fopen(dictionary, "r");
    if(!fp)//Проерка на ошибку открытия
    {
        printf("Ошибка при открытии файла\n");
        return 1;
    }
    int c = 0;
    do 
    {
        //Считываем символы и сохраняем в char до \0 или конца строки
        fgets(word, 46, fp);    
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
    free(word);

   /** //Ищем слово для проверки
    char *str = malloc(sizeof(char));
    printf("Какое слово будем искать? ");
    scanf("%s", str);

    if(search(head, str) == true)
        printf("Слово найдено!\n");
    else
        printf("Слово не найдено!\n");
    free(str); 
    */
    
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{

    unsigned int x = 0;
    char *wor = malloc(sizeof(char));
    FILE *ff = fopen("dictionaries/large", "r");
    if(!ff)//Проерка на ошибку открытия
    {
        printf("Ошибка при открытии файла\n");
        return 1;
    }
    int cc = 0;
    do 
    {
        fgets(wor, 45, ff);    
        cc = fgetc(ff);
        x++;
    }
    while(cc != EOF); // делаем пока не дойдем до конца файла
    
    //Закрываем файл
    fclose (ff);
    free(wor);
    return x;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    freeFunc(head);
    return true;
}


int hash_fun(const char *k)
{
    //Проставя функция по разнице значений заглавных букц в таблице ASCII
    int hash;
    if(isalpha (k[0]))
        hash = toupper(k[0]) - 'A'; 
    if(!isalpha (k[0]))
        hash = 26;
    return hash;
}

//Добавляем слова из файла в структуру префиксное дерево
int add(node *h, char *key)
{
    node *st = h;
    int hash, str = strlen(key) - 1;
    for(int i = 0; i < str; i++)
    {
        hash = hash_fun(&key[i]);
        if(!st->next[hash])
            st->next[hash] = (node*) malloc(sizeof(node));          
        //st = st->next[hash];
        if(!isalpha(st->next[hash]->s[0]))
            st->next[hash]->s[0] = (char)(int)key[i]; 
        if( i + 1 == str)
            st->next[hash]->is_word = 1;
    }
    return 0;
}

// создаем первые 27 st->next для префиксного дерева
int createTrie (node *h)
{
    node *st = h;
    for(int i = 0; i < 26; i++)
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
            if((int)tolower(st->s[0]) == (int)tolower(s[n]))
                n++;
            else
                n = l + 1;             
        }
        else 
            n = l + 1;
    }
    if(n != l + 1 && st->is_word == 1)
         return true;       
    else
        return false;
}

void freeFunc(node *h)
{
  if(h)
  {
    for(int i = 0; i < 27; i++)
    {
        if(h->next[i])
        {
            freeFunc(h->next[i]);
            h->next[i] = NULL;
        }
    }
    free(h);
    }
}