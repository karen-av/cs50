#include<cs50.h>
#include<stdio.h>
// ноемра соответсвия буквам алфавита
int main(void)
{

for (int i = 65; i < 65 + 26; i++)
    {
        printf("%c: %i\n", (char) i, i);
    }
    printf("\n");
for (int i = 97; i < 97 + 26; i++)
    {
        printf("%c: %i\n", (char) i, i);
    }
}