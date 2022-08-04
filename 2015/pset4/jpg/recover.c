/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>  
#include <stdint.h>

// Создаем константу размером в файл jpg
#define JPG_SIZE 512

int main(void)
{
    unsigned char check [JPG_SIZE]; // массив bp 512 символов от 0 до 255
    FILE *inptr = fopen("card.raw", "r");
    if (inptr == NULL)
    {
        printf("Could not open.\n");
        return 1;
    }
    FILE *outptr = 0;
    char n [10]; // массив из 10 символов для названия нового файла
    int i = 1;  // порядковый номер нового файла
  
    //Читаем исходный файл и продолжаем чиать пока не проситаем весь
    while(fread(&check, JPG_SIZE, 1, inptr) == 1)
    {   
        //если первые 4 байта прочитанного куска соответсвуют jpg, то заходим 
        if((check[0] == 0xff && check[1] == 0xd8 && check[2] == 0xff) && (check[3] >= 0xe0 &&  check[3] <= 0xef))
        {
            // Если файл уже создан, то закрываем его
            if(outptr != 0)
            {     
                fclose(outptr);
            }     

            // Cоздаем новый файл
            sprintf(n, "%i.jpg", i); //записываем номер файла в массив n
            outptr = fopen(n, "w"); //создаем новый файл с именем n
            i++;                    // готовим номер для след файла

            // Если файл не создался, возвращаем ошибку
            if(outptr == 0)
            {
                printf("Не удалось создать файл\n");
                fclose(inptr);
                return 2;
            } 

            // Записываем прочитанный кусок в новый файл
            fwrite(&check, JPG_SIZE, 1, outptr); 
        }  

        else
        {
            // если файл открыт, дописываем прочитанныйе байты в него
            if(outptr != 0) 
            {
                fwrite(&check, JPG_SIZE, 1, outptr);     
            }
            // если файла еще нет (ищем начало первого файла), то ищем нвчало файла перемещаясь по одному байту
            else 
            {
                fseek(inptr, -(JPG_SIZE - 1), SEEK_CUR);
            }
        }
    }
    
    fclose(inptr);
    fclose(outptr);
    return 0;
}
