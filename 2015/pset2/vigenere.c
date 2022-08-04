#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include <aio.h>


                                            //int key_x(string key, int i, int dd, int n);
int main(int argc, string argv[])

{
    string key = argv[1];

    for (int i = 0; i < strlen(key); i++)
    {
        char kk = key[i];
        if (!isalpha(kk))    // проверяем чтобы были только буквыы // int x = (int)n[i];   // if (x < 65 || (x > 90 && x < 97) || x > 122)
        {
            printf("Only English words\nrenurn 1\n");
            return 1;
        }
    }
    if  (argc != 2)   //  если аргументов ком строки не два, то ошибка //  (argc < 2 || argc > 2)         // (argc != 2). // не больше 2 аргументов в командной строке
    {
        printf("return 1 1\n");
    }
    else
    {
        string word = get_string("get string\n");   // запрашиваем слово для кодирования
        int n = strlen(word);       // количество символов в кодируемом слове
        char m_key[n];              //подготовака маассива кода. символы в цифровом выражении
        for (int f = 0, a = 0; a < n; f++ )
        {
            for(int g = 0, ks = strlen(key); g < ks; a ++, g++)
            {
                m_key[a] = (int)key[g];                               // printf("%c  %i  %c\n", m_key[a], a, (char)word[a]);
            }
        }

        for (int i = 0, b = 0; i < n; i++)
        {
            if (isalpha((char)word[i] )) // если символ wird[i] алфавитный
            {
                int dd = i - b;
                int key_code[n];
                if (isupper( (char)word[i] ) )                       //    сделано для заглавных букв
                {
                    if (islower( (char)m_key[dd] ) )                  // подготовка ключа из слова
                    {
                        key_code[i] = ((int)m_key[dd] - 97);
                    }
                    else if (isupper( (char)m_key[dd] ) )
                    {
                        key_code[i] = ((int)m_key[dd] - 65);
                    }
                                                                                  // ключ подготовка
                    int cc = (int)word[i] + key_code[i];                         // кодируемый символ + ключ
                    int x =  cc % 90;                                           //остаток от целочисленного диления суммы цифровых значение символи и ключ
                    float cw = (int)word[i] + key_code[i];                     // суммы цифровых значение символи и ключ в ввиде float для дальнейшего определения пути в функции if
                    float yr = cw / 90;                                       // определение выхода за пределы цыфровых обозначений символов
                    if ( yr < 1 || yr == 1)
                    {
                        printf("%c", ((char) ( ((int)word[i] + key_code[i]) )));    // printf("%c(%i) ", ((char) ( ((int)word[i] + key_code[i]) )), key_code[i] );
                    }
                    else if ( yr > 1 )
                    {
                        printf("%c",((((char) ((int)word[i] + key_code[i]) % 90) + 64)));  //   printf("%c(%i) ",((((char) ((int)word[i] + key_code[i]) % 90) + 64)), key_code[i] );
                    }
                }
                else if (islower( (char)word[i] ) )                         // прописные буквы
                {
                    if (islower( (char)m_key[dd] ) )                         // подготовка ключа из слова
                    {
                        key_code[i] = ((int)m_key[dd] - 97);
                    }
                    else if (isupper( (char)m_key[dd] ) )
                    {
                        key_code[i] = ((int)m_key[dd] - 65);
                    }                                                      // ключ
                    int cc = (int)word[i] + key_code[i];                                 // кодируемый символ + ключ
                    int x =  cc % 122;                                                    //остаток от целочисленного диления суммы цифровых значение символи и ключ
                    float cw = (int)word[i] + key_code[i];                             // суммы цифровых значение символи и ключ в ввиде float для дальнейшего определения пути в функции if
                    float yr = cw / 122;                                                   // определение выхода за пределы цыфровых обозначений символов
                    if ( yr < 1 || yr == 1)
                    {
                        printf("%c", (char)(((int)word[i] + key_code[i])));     //printf("%c(%i) ", ((char) ( ((int)word[i] + key_code[i]) )), key_code[i] );
                    }
                    else if ( yr > 1 )
                    {
                        printf("%c", (((char) (((int)word[i] + key_code[i]) % 122) + 96)));   // printf("%c(%i)(%i) ",(((char) (((int)word[i] + key_code[i]) % 122) + 96)), key_code[i], ((char) ((int)word[i] + key_code[i]) ) );
                    }
                }
            }
            else            //  если символ wird[i]  не алфавитный  // символы. не кодирем
            {
                printf("%c", (char)(((int)word[i])));
                b++;
            }
        }
        printf("\n");
        return 0;
    }
}

