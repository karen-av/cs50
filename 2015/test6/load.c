#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include<stdlib.h> 

#define BYTES 512
typedef char BYTE;

bool load(FILE* file, BYTE** content, size_t* length);
int main(void)

{

/**
 * Читала все доступные байты из file.
Сохраняла эти байты в динамически распределенной памяти в куче.
Сохраняет адрес первого из этих байтов в *content.
Хранила количество байтов в * length.
 * 
 */

    FILE *file = fopen("123.txt", "w+");
    size_t length;
    char* content;
    if(load(file, &content, &length))
        printf("OK\n");
    else
        printf("NO\n");


}

bool load(FILE* file, BYTE** content, size_t* length)
{

    BYTE buffer[BYTES];
    size_t read;
    *length = 0;
    *content = malloc(1);

    while (feof(file) == 0)
    {
        read = fread(buffer, sizeof(BYTES), BYTES, file);
        *length += read;
        *content = realloc(*content, *length);
        if(*content == NULL)
            return false;
    }

    return true;
    
}