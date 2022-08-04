//Передаем значение char  в другой char

typedef struct node
{
    char s[2];
    struct node * next;
}node;

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>

int main(void)
{
    node* head = (node*) malloc(sizeof(node));
    head->next = malloc(sizeof(node));
    // head->s = malloc(sizeof(char));
   strcpy(head->s, "A");

    char *ds = malloc(sizeof(char));
    printf("Get: ");
    scanf("%s", ds);

    printf("head->s = %s, ds - %c\n", head->s, ds[0]);

    int i = (int)ds[1];
    head->s[0] = (char)i;    
   // strcpy(head->s, &ds[1]);
    printf("head->s = %s, %i\n", head->s, i);

    return 0;
}
