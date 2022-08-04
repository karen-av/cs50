#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main(void)  //пузырьковая сортировакасв
{
    char massive[] = "8647452";
    int l = strlen(massive);
    int k = 0;
    int j = k + 1;
    int c = 0;
        do
        {
            k = 0;
            j = k + 1;
            c = 0;
            do
            {

                if (massive[j] < massive[k])
                {
                    char temp = massive[k];
                    massive[k] = massive[j];
                    massive[j] = temp;
                    c++;
                }
                j++, k++;
            }
            while (j < l);
        }
        while (c > 0);




   for (int y = 0; y < l; y++)
        {
            printf("%c", massive[y]);
        }
   printf("\n");
}

