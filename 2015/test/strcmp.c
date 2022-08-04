
//Сравнение слов (последовательных символов в char*)


#include<stdio.h>
#include<string.h>
#include<cs50.h>


int main(void)
{
    printf("Say something:  ");
    //scanf();
    char* s = get_string("");

    printf("Say something:   ");
    char* t = get_string("");

    if(s != NULL && t != NULL)
    {
        if(strcmp(s, t) == 0)
        {
            printf("You typed the same thing!\n");
        }
        else
        {
            printf("You typed the not same thing!\n");
        }
    }
}