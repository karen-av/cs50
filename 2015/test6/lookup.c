#include <string.h>
#include <stdio.h>
#include <ctype.h>

const char* lookup(const char* path);

int main(void)

{
    const char* path = "123.jpg";
    const char* type = lookup(path);
    if (type)
        printf("%s\n", type);
    else if (!type)
        printf("NO\n");

    
}

const char* lookup(const char* path)
{
    const char *ext[] = {".css", ".html", ".gif", ".iso", ".jpg", ".js", ".php", ".png"};
    const char *my[] = {"text/css", "text/html", "image/gif", "image/x-icon", "image/jpeg", "text/javascript", "text/x-php", "image/png"};
    
    char *pathext = strrchr(path, '.');

    for (int i = 0; i < 8; i++)
    
         if (strcmp(ext[i], pathext) == 0)
            return my[i];
    
    return NULL;

}