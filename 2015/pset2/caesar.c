#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char proverka(string n);
int main(int argc, string argv[])
{
    string k = argv[1];
    int r = atoi(argv[1]); //делает целое число до точки из string
    char c = proverka(k);
                             //printf("%i значение r\n", r);
    if (r < 0)           //  если r отрицательное чсло выдает ошбку
    {
        printf("return 1\n");
    }
    else if (argc > 2) // (argc != 2)
    {
        printf("return 2\n");
    }
    else if (isdigit (c)) // если  символ С число, то заходим в функцию
    {
        string word = get_string("get string\n");
        for (int i = 0, n = strlen(word); i < n; i++)
        {                                                          //    сделано для заглавных букв
            if (isupper((char)word[i]))             //( (int)word[i] < 91 && (int)word[i] > 64 )
            {                                                       // printf("%c", (char)(((int)word[i] + r ) % 90) ) ;
                int cc = (int)word[i] + r;                           // кодируемый символ + ключ
                int x =  cc % 90;                                    //остаток от целочисленного диления суммы цифровых значение символи и ключ
                float cw = (int)word[i] + r;                        // суммы цифровых значение символи и ключ в ввиде float для дальнейшего определения пути в функции if
                float yr = cw / 90;                                // определение выхода за пределы цыфровых обозначений символов
                if ( yr < 1 || yr == 1)
                {
                    printf("%c", (char)(((int)word[i] + r)));
                }
                else if ( yr > 1 )
                {
                    printf("%c",  ((((char)(((int)word[i] + r) % 90) + 64))));
                }
            }
            else if (islower( (char)word[i] ) )          // ((int)word[i] < 123 && (int)word[i] > 96)
            {                               //    сделано для прописных букв
                int cc = (int)word[i] + r;
                int x =  cc % 122;
                float cw = (int)word[i] + r;
                float yr = cw / 122;

                if ( yr < 1 || yr == 1)
                {
                     printf("%c", (char)(((int)word[i] + r)));
                }
                else if ( yr > 1 )
                {
                    printf("%c",  ((((char)(((int)word[i] + r) % 122) + 96))));
                }
            }
            else
            {                                   // для остальных символовю их не кодируем
                printf("%c", (char)(((int)word[i])));
            }
        }
        printf("\n");
        printf("return 0\n");
    }
    else
    {
        printf("return 3\n");
    }
}

char proverka(string n)
{
    char x;
    for (int j = 0; j < strlen(n); j++)
    {
        x = n[j];
    }
    return x;
}
