#include<cs50.h>
#include<stdio.h>
#include<string.h>
// печатает инициалы имени. ввод через командную строку
//int arr (int argc, string argv);
void aA( string n, int i);
void probel(string n, int i);
int main(void)
{

string n = get_string("Wtat is yoy are name?: ");

for (int i = 0, r = strlen(n); i < r; i++)
    {
        if ( i == 0 )
        {
            if (n[i] == ' ') // если пробел, то заходит в функцию
            {
                probel(n, i);
            }
            else if ((int) n[i] > 96) // заходит сюда если в первое имя начинается с маленькой буквы
            {
                aA(n, i);
                //printf("%c", (char)((int) n[i]-32)); // переводит маленькую букву в большую
            }
            else // если перед первым именем нет пробела и оно начинается с большой буквы
            {
                printf("%c", n[i]);
            }
        }
        else if (n[i] == ' ') // если пробел, то заходит в функцию
        {
            probel(n, i);
        }
    }
    printf("\n");
}

//
void probel(string n, int i)
{
if ((int) n[i+1] > 96) // если второе имя начиается с маленькой буквы
{
    printf("%c", (char)((int) n[i+1]-32)); //переводит ее в большую
}
else // если имя после пробела начинается с заглавной буквы
{
    printf("%c", n[i+1]);
}
}
//
void aA( string n, int i)
{
    printf("%c", (char)((int) n[i]-32)); // переводит маленькую букву в большую
}


