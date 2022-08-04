 /**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 * Убираем шум и заменяем пустые пиксели
 */

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 3)
    {
        printf("Usage: ./copy infile outfile\n");
        return 1;
    }
    // remember filenames
    char* infile = argv[1];
    char* outfile = argv[2];

    // open input file
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");  
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

    int biHeight = abs(bi.biHeight);
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
  //  bi.biSizeImage = ( (bi.biWidth * sizeof(RGBTRIPLE) + padding) * biHeight );
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
 
    int xx[(biHeight * bi.biWidth) * 3 + 3];
    xx[0] = 0xff;
    xx[1] = 0xff;
    xx[2] = 0xff;
    RGBTRIPLE triple;
    
    for (int i = 0; i < biHeight; i++) //   Переписываем исходный файл в массив
    {
        for (int j = 1; j <= bi.biWidth; j++)
        {
            int rr = i * sizeof(RGBTRIPLE) * bi.biWidth + sizeof(RGBTRIPLE) * j;
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            xx[rr - 3] = triple.rgbtBlue; 
            xx[rr - 2] = triple.rgbtGreen;
            xx[rr - 1] = triple.rgbtRed;
        }
        fseek(inptr, (padding), SEEK_CUR);  // исключаем из массива последний кратный 4-ем пиксель
    }
    fseek(inptr, 54, SEEK_SET);

    for (int i = 0; i < biHeight; i++) // переписыввем массив заменяя красный цвет на цвет предъидущего пикселя
    {
        for (int j = 1; j <= bi.biWidth; j++)
        {
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            if (triple.rgbtBlue == 0x00 && triple.rgbtGreen == 0x00 && triple.rgbtRed == 0xff)
            {
                int rr = i * sizeof(RGBTRIPLE) * bi.biWidth + sizeof(RGBTRIPLE) * j;
                xx[rr - 3] = xx[rr - 6];
                xx[rr - 2] = xx[rr - 5];
                xx[rr - 1] = xx[rr - 4];
            }
            fseek(inptr, (padding), SEEK_CUR);
        }
    } 

    fseek(inptr, 54, SEEK_SET);    
    for (int i = 0; i < biHeight; i++) // записываем в новый файл и меняем при чтении старго байты красного на байты из нового массива
    {
        for (int j = 1; j <= bi.biWidth; j++)
        {
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            if (triple.rgbtBlue == 0x00 && triple.rgbtGreen == 0x00 && triple.rgbtRed == 0xff)
            {
                int rr = i * sizeof(RGBTRIPLE) * bi.biWidth + sizeof(RGBTRIPLE) * j;
                triple.rgbtBlue  = xx[rr - 3];
                triple.rgbtGreen = xx[rr - 2];
                triple.rgbtRed   = xx[rr - 1];
            }
            if (triple.rgbtBlue >= 0xf0 ) // все что не белое меняем на серое
            {
                triple.rgbtBlue = triple.rgbtGreen = triple.rgbtRed;
            }
            fwrite(&triple, sizeof(triple), 1, outptr);
        }

        fseek(inptr, padding, SEEK_CUR); //   кратность 4
        for (int k = 0; k < padding; k++) // Дописываем байты кратно 4
        {
            fputc(0x00, outptr);
        }
    }
    fclose(inptr);
    fclose(outptr);
    printf("int xx[%i];\n", (biHeight * bi.biWidth) * 3);

    return 0;
}



            /**printf("Столбец: %i  Пиксель: %i \n", i, j);
            printf("Текущий пиксель: %i %i %i \n", (((i * bi.biWidth) + j) * 3 - 2), (((i * bi.biWidth) + j) * 3 - 1), (((i * bi.biWidth) + j) * 3 - 0));
            printf("Предъид пиксель:  %i %i %i \n", (((i * bi.biWidth) + j) * 3 - 5), (((i * bi.biWidth) + j) * 3 - 4), (((i * bi.biWidth) + j) * 3 - 3));
            printf("Цвет текущ пикс RGB: %i %i %i\n", triple.rgbtBlue, triple.rgbtGreen, triple.rgbtRed);
            printf("Цвет текущ пикс XX: %i %i %i \n", xx[((i * bi.biWidth) + j) * 3 - 2], xx[((i * bi.biWidth) + j) * 3 - 1], xx[((i * bi.biWidth) + j) * 3 - 0]);
            printf("Цвет предъид пикс XX: %i %i %i \n", xx[((i * bi.biWidth) + j) * 3 - 5], xx[((i * bi.biWidth) + j) * 3 - 4], xx[((i * bi.biWidth) + j) * 3 - 3]);
            printf(" /// \n");  */


/**
                    printf("%i %i %i\n", triple.rgbtBlue, triple.rgbtGreen, triple.rgbtRed);
                    printf("%ld\n", ftell(inptr));
                    printf(" \n");
                    printf("%ld\n", ftell(inptr));
                    printf("Reading... \n");
                    printf("%ld\n", ftell(inptr));
                    printf("%i %i %i\n", triple.rgbtBlue, triple.rgbtGreen, triple.rgbtRed);
                    printf(" \n"); */

                    /**printf("Столбец: %i  Строка: %i \n", ii, jj);
                printf("Номер тек пикс:  %i %i %i \n", (((ii * bi.biWidth) + jj) * 3 - 2), (((ii * bi.biWidth) + jj) * 3 - 1), (((ii * bi.biWidth) + jj) * 3 - 0));
                printf("Номер пред пикс: %i %i %i \n", (((ii * bi.biWidth) + jj) * 3 - 5), (((ii * bi.biWidth) + jj) * 3 - 4), (((ii * bi.biWidth) + jj) * 3 - 3));
                printf("Цвет тек пикс RGB    %i %i %i\n", triple.rgbtBlue, triple.rgbtGreen, triple.rgbtRed);
                printf("Цвет тек пикс XX:    %i %i %i \n", xx[((ii * bi.biWidth) + jj) * 3 - 2], xx[((ii * bi.biWidth) + jj) * 3 - 1], xx[((ii * bi.biWidth) + jj) * 3 - 0]);
                printf("Цвет пред пикс XX:   %i %i %i \n", xx[((ii * bi.biWidth) + jj) * 3 - 5], xx[((ii * bi.biWidth) + jj) * 3 - 4], xx[((ii * bi.biWidth) + jj) * 3 - 3]);
                */

               /**printf("Цвет тек пикс после замены: %i %i %i \n", xx[((ii * bi.biWidth) + jj) * 3 - 2], xx[((ii * bi.biWidth) + jj) * 3 - 1], xx[((ii * bi.biWidth) + jj) * 3 - 0]);
                printf(" /// \n"); */