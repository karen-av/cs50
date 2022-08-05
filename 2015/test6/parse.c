

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include<stdlib.h> 




bool parse(const char* line, char* abs_path, char* query);

int main()
{
    char* line = "GET /hello.php?q=Alice HTTP/1.1\r\n";
    char* abs_path = malloc(sizeof(char));
    char* query = malloc(sizeof(char));;


    if(parse(line, abs_path, query))
        printf("OK\n");
    else
    printf("NO\n");

}

bool parse(const char* line, char* abs_path, char* query)
{
    char *http_ver = strrchr(line, ' '); // Последние входжение символа
    strcpy(abs_path, strchr(line, ' ') + 1); // Первое вхождение символа
    *strrchr(abs_path, ' ') = '\0'; //найти последнее входжение и заисать завершающий строку символ
    
    if(strncmp( "GET", line, 3) != 0 )
    {
       // error(405);
       printf("1\n");
        return false;
    }
    else if ((strcmp(" HTTP/1.1\r\n", http_ver) != 0 ))
    {
        //error(505);
        printf("2\n");
        return false;
    }

    else if (abs_path[0] != '/')
    {
        //error(501);
        printf("3\n");
        return false;
    }

    else if(strchr(abs_path, ' ') || strchr(abs_path, '"'))
    {
        //error(400);
        printf("4\n");
        return false;
    }

    if(strchr(abs_path, '?'))
    {
        printf("11\n");
       //strcpy(query, strchr(line, '?'));
       strcpy(query, strchr(line, '?') + 1);
        printf("11.1\n");
        *strrchr(query, ' ') = '\0';
        printf("query - %s\n", query);
    }
    else 
    {
        printf("12\n");
        strcpy(query, "\0");
        printf("query - %s\n", query);
    }

    return true;
    
}

