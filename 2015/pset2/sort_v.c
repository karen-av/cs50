#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main(void)  //пузырьковая сортировакасв
{
    char array[] = "2431";
    for (int i = 0, l = strlen(array); i < l - 1; i++)
    {
        int j = i + 1;
        if (array[j] < array[i])
        {
            while (j > 0 && array[j] < array[j-1])
            {
                int e = array[j];
                array[j] = array[j-1];
                array[j-1] = e;
                j = j - 1;
            }

        }
    }

    for (int y = 0, l = strlen(array); y < l; y++)
   {
       printf("%c", array[y]);
   }
   printf("\n");
}
