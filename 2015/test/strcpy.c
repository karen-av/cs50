//Передаем значение char  в другой char

typedef struct node
{
    char *s;
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
    head->s = malloc(sizeof(char));
   
    char *ds = malloc(sizeof(char));
    printf("Get: ");
    scanf("%s", ds);

    printf("head->s = %s\n", head->s);
    //Функция передает из одного char в другой по одному символу до /0
    strcpy(head->s, ds);
    printf("head->s = %s\n", head->s);


    return 0;

}
