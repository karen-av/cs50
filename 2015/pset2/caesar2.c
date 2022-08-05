#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char string_to_char(string n);
int main(int argc, string argv[])

{
    int r = atoi(argv[1]);
   // printf("%i\n", r);
    if (argc != 2) // если аргументов не два, то ошибка
    {
        printf("Print the rey next time\n");
        return 1;
    }
    else if (r < 1)
    {
        printf("Print the key positive integer nex time\n");
        return 1;
    }
    else
    {
                                             // int r = atoi(argv[1]);            // целое число из аргумента. код
        char c = string_to_char(argv[1]); // символ из аргумента
        if (isdigit (c)) // если код цыфра, то идем в функцтию
        {
            string word = get_string("Get string ");
            for (int i = 0; i < strlen(word); i++)
            {
                if (isupper( (char)(word[i])))
                {
                    int cc = (int)word[i] + (r % 26);      // закодированный символ
                    int x = cc % 90;                 // остаток от целочисленного диления
                    if (cc < 90 || cc == 90)
                    {
                        printf("%c", (char)cc);
                    }
                    else if (cc > 90)
                    {
                        printf("%c", (char) ((cc % 90) + 64));
                    }
                }
                else if (islower((char)(word[i])))
                {
                    int cc = (int)word[i] + (r % 26);      // закодированный символ
                    int x = cc % 122;                 // остаток от целочисленного диления
                    if (cc < 122 || cc == 122)
                    {
                        printf("%c", (char)cc);
                    }
                    else if (cc > 122)
                    {
                        printf("%c", (char) ((cc % 122) + 96));
                    }
                }
                else
                {
                    printf("%c", (char)(int)word[i]);
                }

            }
            printf("\n");
            return 0;

        }
        else // иначе ошибка
        {
        printf("Print integer nex time\n");
        return 1;
        }
    }
}


char string_to_char(string n)  // делаемиз аргумента командной строки символ. в дальнейшем проверяемБ чтобы символ был числом
{
    char x;
    for (int j = 0; j < strlen(n); j++)
    {
        x = n[j];
    }
    return x;

}
