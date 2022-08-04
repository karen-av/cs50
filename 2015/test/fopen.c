#include <stdio.h>

int main(void)
{
    char line[255];
    FILE *file = fopen("test.txt", "r");
    FILE *ofile = fopen("123.txt", "w");
    char str[5];
    
   while(fgets(line, 255, file) != NULL) // построчной записывает данный из файла в массив
    {
       fputs(line, ofile);
    }
      
    
    /**
    * puts(line); // выводит значение масива
    * printf("That is your name? ");
    * fgets(str, 5, stdin);  // принимает в масси ввод с клавиатуры
    * printf("Your name is: "); 
    * fflush(stdin); // отчищает поток ввода
    * puts(str); // выводит в консоль
    * char d[] = "Hi";
    * printf("do %s \n", d);
    * scanf("%s", d); // ввод с клавы
    * printf("posle %s \n", d);
    */

    /**
    gets(strr);       // принимает в массив ввод с клавиатуры. небезопасный
    puts(strr);                 //выводи в терминал данные массива    
    fread(&line, 2, 1, file);
    fwrite(&line, 2, 1, ofile);
    fgets(line, 255, file); // читает по строкам и записывает в указанный массив
    printf("%s", line);
    fprintf(file, "3\n2"); */

    fclose(file);
    fclose(ofile);
    return 0;
}