/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 * Увеличиваем через массив
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
    int paddingS = (4 - (bi.biWidth / n * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    bi.biSizeImage = ( (bi.biWidth * sizeof(RGBTRIPLE) + paddingS) * biHeight );

    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
   
    
    int xx[(biHeight/n * bi.biWidth/n) * 3 + 6]; // масси для оригинальной картинки
    RGBTRIPLE triple;

    fseek(inptr, 54, SEEK_SET);
    
    for (int i = 0, k = 0, nn = biHeight / n; i < nn; i++) // сохраняем в массив исходное изображение
    {
        for (int j = 0, ww = bi.biWidth/n; j < ww; j++)
        {
            fread(&triple, sizeof(triple), 1, inptr);
            xx[k    ] = triple.rgbtBlue;
            xx[k + 1] = triple.rgbtGreen;
            xx[k + 2] = triple.rgbtRed;

            k += 3;
        }
        fseek(inptr, (paddingS), SEEK_CUR);  // исключаем из массива последний кратный 4-ем пиксель
    }

    fseek(inptr, 54, SEEK_SET);
    fseek(outptr, 54, SEEK_SET);

    for (int i = 0, dd = 0, ll = 0; i < biHeight; dd += bi.biWidth / n * 3)  // заполняем новый файл из  массива
    {
        for(int u = 0; u < n; u++, i++)  // n раз дублируем строку
        { 
            ll = 0;
            for(int j = 0, kf = (bi.biWidth / n); j < kf; j++) // дублируем пиксели в ряду
            {
                for(int a = 0; a < n ; a++) // дублируем пиксель n раз
                {
                    fread(&triple, sizeof(RGBTRIPLE), 1, outptr);

                    triple.rgbtBlue  = xx[dd + ll    ];
                    triple.rgbtGreen = xx[dd + ll + 1];
                    triple.rgbtRed   = xx[dd + ll + 2];

                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
                    ll += 3; 
            }
            for (int k = 0; k < padding; k++)  // Дописываем байты кратно четырем
            {
                fputc(0x00, outptr);
            } 
        }
    }
    fclose(inptr);
    fclose(outptr);

    return 0;
}

 /** 
printf("Кур: %ld | ", ftell(outptr));
printf("%i.%i.%i | ", xx[dd + ll    ], xx[dd + ll + 1], xx[dd + ll + 2]);  
printf("%i.%i.%i | ", dd + ll, dd + ll + 1, dd + ll + 2);  
printf("\n"); */