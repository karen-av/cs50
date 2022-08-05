#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


int main(int argc, string argv[])

{
    string key = (argv[1]);
    for (int q = 0; q < strlen(key); q++)
    {
        char kkk = key[q];
        if (!isalpha(kkk))    // проверяем чтобы были только буквыы
        {
            printf("Print only english words\n");
            return 1;
        }
    }
    if (argc != 2)          // если аргументов не два, то ошибка
    {
        printf("Print only one key word next time\n");
        return 1;
    }
    else //if (isalpha (key))          // если аргумент ком строк это буквы алфавита, то идем сюда         // если аргументов два, то идем сюда
    {
        string word = get_string("Get text: \n");  // запрашиваем текст для кодирования
        int n = strlen(word);
        char m_key[n];
        for (int f = 0, a = 0; a < n; f++)
        {
            for(int g = 0, ks = strlen(key); g < ks; a++, g++)
            {
                m_key[a] = (int)key[g]; // массив симвлов цыфры
            }
        }
        for (int i = 0, b = 0; i < n; i++)
        {
            if (isalpha((char)word[i])) //если символ wird[i] алфавитный
            {
                int kk = i - b;
                int key_code[n];
                if (islower((char)word[i])) //если символ wird[i] лижний регистр
                {
                    if (islower((char)m_key[kk]))  // если символ ключа  имеет ничний регистр
                    {
                        key_code[i] = (int)m_key[kk] - 97;
                    }
                    else if (isupper((char)m_key[kk]))                                     // если символ ключа  имеет верхний регистр
                    {
                        key_code[i] = (int)m_key[kk] - 65;
                    }

                    int cc = (int)word[i] + (key_code[i] % 26);            // закодированный символ
                    int x = cc % 122;                           // остаток от целочисленного диления
                    if (cc < 122 || cc == 122)
                    {
                        printf("%c", (char)cc);
                    }
                    else if (cc > 122)
                    {
                        printf("%c", (char) ((cc % 122) + 96));
                    }

                }
                else if (isupper((char)word[i]))          // если символ wird[i] верхний регистр
                {
                    if (islower((char)m_key[kk]))  // если символ ключа  имеет ничний регистр
                    {
                        key_code[i] = (int)m_key[kk] - 97;
                    }
                    else if (isupper ((char)m_key[kk]))                                     // если символ ключа  имеет верхний регистр
                    {
                        key_code[i] = (int)m_key[kk] - 65;
                    }
                    int cc = (int)word[i] + (key_code[i] % 26);            // закодированный символ
                    int x = cc % 90;                           // остаток от целочисленного диления
                    if (cc < 90 || cc == 90)
                    {
                        printf("%c", (char)cc);
                    }
                    else if (cc > 90)
                    {
                        printf("%c", (char) ((cc % 90) + 64));
                    }
                }
            }
            else if (!isalpha((char)word[i])) // если символ wird[i] не алфавитный
            {
                printf("%c", (char)(((int)word[i])));
                b++;
            }
        }
    printf("\n");
    return 0;
    }
}



