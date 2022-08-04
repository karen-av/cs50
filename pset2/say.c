#include<cs50.h>
#include<stdio.h>
// функция защита в функцию
void cough(int n);
void say(string wodr, int n);
void seenze(int n);
int main(void)
{
    seenze(3);
    cough(3);
    say("achoo", 3);

}


void cough(int n) // прописываем функцию и внутри вставляем еще одну функцию
{
    say("cough", n);
}

void say(string word, int n) // эту функцию вставляе в другую функцию
{
    for(int i = 0; i < n; i++)
    {
        printf("%s\n", word);
    }
}
void seenze(int n)
{
    say("achoo", n);
}