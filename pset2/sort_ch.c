#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main(void)  // сортировака выбором
{
   char massive[] = "41142755403";
   for (int i = 0, l = strlen(massive); i < l - 1; i++)
   {
       int j = i + 1;
       do
       {
           if (massive[j] < massive[i])
           {
               char temp = massive[i];
               massive[i] = massive[j];
               massive[j] = temp;
           }
           j++;
       }
       while (j < l);
   }
   for (int y = 0, l = strlen(massive); y < l; y++)
   {
       printf("%c", massive[y]);
   }
   printf("\n");

}
