/** меняем символ на заглывную букву через выделение памяти
 */

#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(void)

{
    printf("Say something:  ");
    char* s = get_string("");
    if(s == NULL) // проверка на ошибку
    {
        return 1;
    }
    char* t = malloc((strlen(s) + 1) * sizeof(char)); //выделяем объем памяти с заданным размером и умножаем на величину char
    if(t == NULL)
    {
        return 1;
    }

    for(int i = 0, n = strlen(s); i <= n; i++)
    {
        *(t + i) = *(s + i); // через * указывает адресъ. иди по данному адресу
       // t[i] = s[i]; // копируем char в выделеную память
    }
    printf("Capitalizing copy...\n");
    if(strlen(t) > 0)
    {
        *t = toupper(*t);  //через * идет по адресу и непосредсвенно к символу в массиве
        // t[0] = toupper(t[0]);  // меняем пурвую букву на заглавную
    }
    printf("Original: %s\n", s);
    printf("Change: %s\n", t);



}