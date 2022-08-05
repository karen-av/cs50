/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 * Уменьшаем изображение
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
    
    int biWidthN = bi.biWidth / n;
    int biHeightN = abs(bi.biHeight / n);

    int biWidthO = bi.biWidth;
    int biHeightO = abs(bi.biHeight);

    int paddingN =  (4 - (biWidthN * sizeof(RGBTRIPLE)) % 4) % 4;
    int paddingO =  (4 - (biWidthO * sizeof(RGBTRIPLE)) % 4) % 4;

    bi.biSizeImage = ((biWidthN * sizeof(RGBTRIPLE) + paddingN) * biHeightN);
    bi.biWidth /= n;
    bi.biHeight /= n;

    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    RGBTRIPLE triple;

    fseek(inptr, 54, SEEK_SET);
    fseek(outptr, 54, SEEK_SET);

        for(int u = 0; u < biHeightN; u++)  // на n раз сокращаем и  записываем строку
        {   
            for(int j = 0; j < biWidthN; j++) // записываем пиксели в ряду
            {   
                fread(&triple, sizeof(triple), 1, inptr);
                fwrite(&triple, sizeof(triple), 1, outptr);
                fseek(inptr, sizeof(triple) * (n -1), SEEK_CUR);
            }
            for (int k = 0; k < paddingN; k++)  // Дописываем байты кратно четырем
            {
                fputc(0x00, outptr);
            }
            fseek(inptr, paddingO, SEEK_CUR);
            fseek(inptr, ((biWidthO * sizeof(RGBTRIPLE) + paddingO) * (n - 1)), SEEK_CUR);
        }
    fclose(inptr);
    fclose(outptr);
   
    return 0;
}