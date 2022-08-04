#include<cs50.h>
#include<stdio.h>

int main(void)

{
   printf("State your name?\n");                     // спрашивает имя
   string n = get_string("");

   printf("hello, %s! How many ears old you?\n", n); // спрашивает возраст
   int old = get_int("");

   if (old > 18 || old == 18)                      //если 18 и более. то все
   {
      printf("Welkom, %s!\n", n);
   }
   else                                           //если меньше 18. то все
   {
      printf("Fack Off, %s!\n", n);
   }
}
