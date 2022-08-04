

#include <ctype.h>
#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>
#include<stdlib.h> 
#include<stdbool.h>



int hash_fun( char *k);
int add(node *h, char *key);
int createTrie (node *h);
bool load( char* dictionary);
bool search(node *h, char *s);

typedef struct node
{
    char s[2];
    bool is_word;
    struct node * next[27];
} node; 

int main()
{
    node *head = malloc(sizeof(node));
    
    FILE* fp = fopen("texts/shakespeare.txt", "r");
    FILE* fn = fopen("new.txt", "r");
    if (fp == NULL)
    {
        printf("Could not open \n");
        
        return 1;
    }
    int index = 0, misspellings = 0, words = 0;
    char word[45+1];
    for (int c = fgetc(fp); c != EOF; c = fgetc(fp))
        {
            //разрешать только буквы алфавита и апострофы
            if (isalpha(c) || (c == '\'' && index > 0))
            {
                // добавить символ к слову
                word[index] = c;
                index++;
                // игнорировать алфавитные строки, слишком длинные, чтобы быть словами
                if (index > 45)
                {
                    // использовать остаток алфавитной строки
                    while ((c = fgetc(fp)) != EOF && isalpha(c));

                    // prepare for new word / подготовиться к новому слову
                    index = 0;
                }
            }

            // игнорировать слова с цифрами (как MS Word)
            else if (isdigit(c))
            {
                // использовать остаток буквенно-цифровой строки
                // isalnum является ли десятичной цифрой или символом алфавита, прописной или строчной буквой
                while ((c = fgetc(fp)) != EOF && isalnum(c));

                // prepare for new word / подготовиться к новому слову
                index = 0;
            }

            // we must have found a whole word / мы должны были найти целое слово
            else if (index > 0)
            {
                // terminate current word / завершить текущее слово '\0' конец строки
                word[index] = '\0';
                // update counter / обновить счетчик слов
                words++;
               
                bool misspelled = !check(word);
                if (misspelled)
                {

                    fputs(word, fn);
                    printf("%s\n", word);
                    misspellings++;
                    
                }

                // prepare for next word / подготовка к следующему слову
                index = 0;
                //printf("%ld\n", ftell(fp)); 
            }
        }
}


bool check( char* word)
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
    for(int i = 0; i < str; i++)
    {
        hash = hash_fun(&key[i]);
        if(!st->next[hash])
            st->next[hash] = (node*) malloc(sizeof(node));          
        st = st->next[hash];
        if(!isalpha(st->s[0]))
            st->s[0] = (char)(int)key[i]; 
        if( i + 1 == str)
            st->is_word = 1;
    }
    return 0;
}

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

bool load( char* dictionary)
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