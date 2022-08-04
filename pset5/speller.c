/**
 * speller.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a spell-checker.
 */

#include <ctype.h>
#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>
#include<stdlib.h> 



#include "dictionary.h"
#undef calculate
#undef getrusage

// default dictionary / словарь по умолчанию
//Поменять на large
#define DICTIONARY "dictionaries/large"

// prototype / прототип функции, прописанной в конце
double calculate(const struct rusage* b, const struct rusage* a);

int main(int argc, char* argv[]) 
{
    
    // check for correct number of args
    // проверка количества арументов args
    if (argc != 2 && argc != 3)
    {
        printf("Usage: speller [dictionary] text\n");
        return 1;
    }

    // structs for timing data
    // структыры для временных данных
    struct rusage before, after;

    // benchmarks / ориентиры
    double time_load = 0.0, time_check = 0.0, time_size = 0.0, time_unload = 0.0;

    // determine dictionary to use/ определяет словарь для использования
    char* dictionary = (argc == 3) ? argv[1] : DICTIONARY;
   
    // load dictionary / загрузить словарь
    // прописать эту функцию  загрузка словаря
    getrusage(RUSAGE_SELF, &before);
    bool loaded = load(dictionary);
    getrusage(RUSAGE_SELF, &after);

    // abort if dictionary not loaded / если библиотеку не удалось загрузить
    if (!loaded)
    {
        printf("Could not load %s.\n", dictionary);
        return 1;
    }

    // calculate time to load dictionary / расчет времени загрузки библиотеки
    time_load = calculate(&before, &after);

    // try to open text / попытка открыть текст библиотеки
    char* text = (argc == 3) ? argv[2] : argv[1];
    FILE* fp = fopen(text, "r");
    if (fp == NULL)
    {
        printf("Could not open %s.\n", text);
        unload(); // прописать эту функцию
        return 1;
    }

    // prepare to report misspellings / подготовьтесь сообщить об опечатках
    printf("\nСЛОВА С ОШИБКАМИ\n\n");

    // prepare to spell-check / подготовиться к проверке орфографии
    // misspellings - опечатки
    int index = 0, misspellings = 0, words = 0;
    char word[LENGTH+1];

    //  проверка орфографии по буквам каждое слово
    // fgetc указатель 
    for (int c = fgetc(fp); c != EOF; c = fgetc(fp))
    {
        //разрешать только буквы алфавита и апострофы
        if (isalpha(c) || (c == '\'' && index > 0))
        {
            // добавить символ к слову
            word[index] = c;
            index++;
            // игнорировать алфавитные строки, слишком длинные, чтобы быть словами
            if (index > LENGTH)
            {
                // использовать остаток алфавитной строки
                while ((c = fgetc(fp)) != EOF && isalpha(c));

                // prepare for new word / подготовиться к новому слову
                index = 0;
            }
        }

        // игнорировать слова с цифрами (как MS Word)
        else if (isdigit(c))
        {
            // использовать остаток буквенно-цифровой строки
            // isalnum является ли десятичной цифрой или символом алфавита, прописной или строчной буквой
            while ((c = fgetc(fp)) != EOF && isalnum(c));

            // prepare for new word / подготовиться к новому слову
            index = 0;
        }

        // we must have found a whole word / мы должны были найти целое слово
        else if (index > 0)
        {
            // terminate current word / завершить текущее слово '\0' конец строки
            word[index] = '\0';
            // update counter / обновить счетчик слов
            words++;

            // check word's spelling / проверить правописание слова
            // прописать функцю check
            getrusage(RUSAGE_SELF, &before);
            bool misspelled = !check(word);
            getrusage(RUSAGE_SELF, &after);

            // update benchmark / обновить ориентир
            time_check += calculate(&before, &after);

            // print word if misspelled / напечатать слово, если оно написано с ошибкой
            if (misspelled)
            {   
                printf("%s\n", word);
                misspellings++;
            }

            // prepare for next word / подготовка к следующему слову
            index = 0;
            //printf("%ld\n", ftell(fp)); 
        }
    }

    // check whether there was an error / проверка была ли ошибка при чтении файла
    if (ferror(fp))
    {
        fclose(fp);
        printf("Error reading %s.\n", text);
        unload();
        return 1;
    }

    // close text / закрываем файл
    fclose(fp);

    // determine dictionary's size / определяем размер словоря
    // прописать функцию size
    getrusage(RUSAGE_SELF, &before);
    unsigned int n = size();
    getrusage(RUSAGE_SELF, &after);

    // calculate time to determine dictionary's size 
    // расчет времени определения словаря
    time_size = calculate(&before, &after);

    // unload dictionary / выгрузка словаря
    getrusage(RUSAGE_SELF, &before);
    bool unloaded = unload();
    getrusage(RUSAGE_SELF, &after);

    // abort if dictionary not unloaded / прервать, если словарь не выгружен
    if (!unloaded) 
    {
        printf("Could not unload %s.\n", dictionary);
        return 1;
    }

    // calculate time to unload dictionary
    // расчет времение выгрузки словаря
    time_unload = calculate(&before, &after);

    // report benchmarks / отчет показателей
    printf("\nWORDS MISSPELLED:   %d\n", misspellings);
    printf("WORDS IN DICTIONARY:  %d\n", n);
    printf("WORDS IN TEXT:        %d\n", words);
    printf("TIME IN load:         %.2f\n", time_load);
    printf("TIME IN check:        %.2f\n", time_check);
    printf("TIME IN size:         %.2f\n", time_size);
    printf("TIME IN unload:       %.2f\n", time_unload);
    printf("TIME IN TOTAL:        %.2f\n\n", 
     time_load + time_check + time_size + time_unload);

    // that's all folks / это все, ребята
    return 0;
}

/**
 * Returns number of seconds between b and a.
 * Возвращение количества секунд между в и а
 */
double calculate(const struct rusage* b, const struct rusage* a)
{
    if (b == NULL || a == NULL)
    {
        return 0.0;
    }
    else
    {
        return ((((a->ru_utime.tv_sec * 1000000 + a->ru_utime.tv_usec) -
                 (b->ru_utime.tv_sec * 1000000 + b->ru_utime.tv_usec)) +
                ((a->ru_stime.tv_sec * 1000000 + a->ru_stime.tv_usec) -
                 (b->ru_stime.tv_sec * 1000000 + b->ru_stime.tv_usec)))
                / 1000000.0);
    }
}
