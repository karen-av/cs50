/**
 * @file struct-7.c
 * @date 2022-05-17
 * Префиксное дерево (trie) * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>

#define NUM 26;

typedef struct node
{
    char s[2];
    bool is_word;
    struct node * next[26];
   
}node;

int add(node *h, char *key);
int hash_fun(char *k);
int createTrie (node *h);
void print(node *h);
bool search(node *h, char *s);
void freeFunc(node *h);



int main ()
{
    node* head = (node*) malloc(sizeof(node));
   // printf("head->s = %c\n", head->s[0]);
    if(!head) //Проверка
        {
            printf("Err create head\n");
            return 1;
        }

    createTrie (head);
    
    char *key = malloc(sizeof(char));
    printf("Какое слово добавить? ");
    scanf("%s", key);

    add(head, key);
    printf("Какое слово добавить? ");
    scanf("%s", key);
    add(head, key);
    printf("Какое слово добавить? ");
    scanf("%s", key);
    add(head, key);
    //print(head);

    printf("Какое слово будем искать?: ");
    char *string = malloc(sizeof(char));
    scanf("%s", string);
    if(search(head, string) == true)
    {
        printf("Слово найдено!\n");
    }
    else
    {
        printf("Слово не найдено.\n");
    } 
    
    free(string);
    free(key);
    freeFunc(head);
    return 0;
}

// создаем первые 27 st->next
int createTrie (node *h)
{
    node *st = h;
   // int n = NUM;
    for(int i = 0; i < NUM i++)
    {
       st->next[i] = (node*) malloc(sizeof(node));
        if(st->next[i] == NULL) // Проверка
        {
            printf("Err create st->next[%i]\n", i);
            return 2;
        }
        st = st->next[i];
    }
    printf("End creating!\n");
return 0;
}

//Добавляем слово
int add(node *h, char *key)
{
    printf("Adding...\n");
    node *st = h;
    int hash; 
    int str = strlen(key);
    for(int i = 0; i < str; i++)
    {
        //расчитаваем через хаш функцию
        hash = hash_fun(&key[i]);

        // Если цепоска не существует, то создаем ее
        if(st->next[hash] == NULL)
            st->next[hash] = (node*) malloc(sizeof(node));
        //Если существует, то отталкиваемся уже от нее
        st = st->next[hash];
        //если символ еще не вписан, то вписываем его
        //если символ уже записан, то идем к след символу
        if(!isalpha(st->s[0]))
        {
            st->s[0] = (char)(int)key[i]; 
        }   
        //После записи полго слова ставим логисеский флаг окончания слова
        if(i + 1 == str)
            st->is_word = true;
        

    }
    //После записи полго слова ставим логисеский флаг окончания слова
    //st->is_word = true; // так работало
    printf("And adding!\n");
    return 0;
}

// hash функция
int hash_fun(char *k)
{
    //Проставя функция по разнице значений заглавных букц в таблице ASCII
    int hash;
    if(isalpha (k[0]))
        hash = toupper(k [0]) - 'A'; 
    if(!isalpha (k[0])) // Если опостраф 
        hash = 26;

    //printf("%i \n", hash);
    return hash;
    
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
        //Расчитываем по хеш функции к какому номеру next  нужно обратиться для поиска символа в массивепод номером n
        hash = hash_fun(&s[n]);
        //Если этот узел существует заходим 
        if(st->next[hash])
        {
            //передаем указатель на этот узел
            st= st->next[hash];
            //Если значения в узле и значение в ключе совпадают, то переходим к следующему символу
            if((int)st->s[0] == (int)s[n])
                n++;
        }
        //Иначе выходим
        else 
            n = l + 1;
    }
    //Если прошли все слово и в последнем узле установлен логисекий флаг, то возвращаем true
    if(n != l + 1 && st->is_word == true )
        return true;
    else
        return false;
}

//Выводим на печать. Не работает
void print(node *h)
{
    printf("Printing...\n");
    node *st = h;
    int i = 0, b = 0;

    while (st)
    {
        while (i < 25)
        {
            printf(" i %i\n", i);
            if(st->next[i] && st->next[i]->s[0])
            {
                printf("%c i = %i\n", st->next[i]->s[0], i);
            }
            i++;
            //printf(" i %i\n", i);
            
        }
       // i = 0;
       //st = h->next[b];
    }
}

//Освобождение памяти
void freeFunc(node *h)
{
    if(h)
    {
        for (int i = 0; i < 26; i++)
        {
            if(h->next[i])
            {
                freeFunc(h->next[i]);
                h->next[i] = 0;
            }
        }
    free(h);
    }
}

