/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 * Увеличиваем через перемещение  курсора
 */
       
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>  

#include "bmp.h"

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        printf("Введите число, начальный файл и название нового файла\n");
        return 1;
    }
    char* s = argv[1];
    int str = strlen(s);
    for (int i = 0; i < str; i++)
    {
        if((isdigit(s[i])))
        {
            
        }
        else
        {
            printf("Нельзя увеличить на букву, отрицательное или нецелое число. Попробуйте еще раз.\n");
            return 1;
        }
    }
    int n = atoi(argv[1]);
    if (n%1 != 0 || n < 1 || n > 100)
        {
            printf("Введите целое число от 1 до 100. Попробуйте еще раз.\n");
            return 1;
        }
     
    char* infile = argv[2];
    char* outfile = argv[3];

    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    FILE* outptr = fopen(outfile, "w+");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    
    bi.biWidth *= n;
    bi.biHeight *= n;
    int biHeight = abs(bi.biHeight);
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int paddingS =  (4 - (bi.biWidth / n * sizeof(RGBTRIPLE)) % 4) % 4;
    bi.biSizeImage = ( (bi.biWidth * sizeof(RGBTRIPLE) + paddingS) * biHeight);
    
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    RGBTRIPLE triple;

    fseek(inptr, 54, SEEK_SET);
    fseek(outptr, 54, SEEK_SET);
    int kf = (bi.biWidth / n);

    for (int i = 0, dd = 0; i < biHeight;)  
    {
        for(int u = 0; u < n; u++, i++ )  // n раз дублируем строку
        {   
            for(int j = 0; j < kf; j++) // дублируем пиксели в ряду
            {
                for(int a = 0; a < n ; a++) // дублируем пиксель n раз
                {
                    fread(&triple, sizeof(triple), 1, inptr);
                    fwrite(&triple, sizeof(triple), 1, outptr);
                    fseek(inptr, -sizeof(triple), SEEK_CUR);
                }
                fseek(inptr, (sizeof(triple)), SEEK_CUR);
            }
            for (int k = 0; k < padding; k++)  // Дописываем байты кратно четырем
            {
                fputc(0x00, outptr);
            } 
            fseek(inptr, (54 + (kf * sizeof(triple) + paddingS) * dd), SEEK_SET);
        }
        dd++;
        fseek(inptr, (54 + (kf * sizeof(triple) + paddingS) * dd), SEEK_SET);
    }
    fclose(inptr);
    fclose(outptr);
   
    return 0;
}