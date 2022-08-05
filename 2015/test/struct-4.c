/**
 * @file struct-4.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-11
 * 
 * @copyright Copyright (c) 2022
 * 
 * binary search rtee
 * бинарное дерево поиска
 * 
 *                55
 *        33              77
 *    22    44         66    88 
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 

typedef struct node
{
    int x;
    struct node * rigth;
    struct node *left;
}node;


void print(node *h);
bool sear(node *h, int n);

int main(void)
{
    node * head = malloc(sizeof(node));
    head->x = 55;

    head->left = malloc(sizeof(node));
    head->left->x = 33;
    head->left->left = malloc(sizeof(node));
    head->left->rigth = malloc(sizeof(node));
    head->left->left->x = 22;
    head->left->rigth->x = 44;
    head->left->left->left = NULL;
    head->left->left->rigth = NULL;
    head->left->rigth->left = NULL;
    head->left->rigth->rigth = NULL;

    head->rigth = malloc(sizeof(node));
    head->rigth->x = 77;
    head->rigth->left = malloc(sizeof(node));
    head->rigth->rigth = malloc(sizeof(node));
    head->rigth->left->x = 66;
    head->rigth->rigth->x = 88;
    head->rigth->left->left = NULL;
    head->rigth->left->rigth = NULL;
    head->rigth->rigth->left = NULL;
    head->rigth->rigth->rigth = NULL;

        print(head);

    int *s = (int *) malloc(sizeof(int));
    printf("Giv int to search\n");
    scanf("%i", s);
    if (!sear(head, *s))
    {
         printf("Not search\n");
    }
    else      
    {
        printf("Search\n");        
    }

    free(s);
    free(head->rigth->rigth);
    free(head->rigth->left);
    free(head->rigth);
    free(head->left->rigth);
    free(head->left->left);
    free(head->left);
    free(head);
    return 0;

}

bool sear(node *h, int n)
{
    node * st = h;
    while(st)
    {
        if (n == st->x)
        {
            return true;
        }
        else if(n > st->x)
        {
            st = st->rigth;
        }
        else if(n < st->x)
        {
           st = st->left;
        }
    }
       return false;
}

void print(node *h)
{
    node * sl = h;
    node * sr = h;

    
    while (sl != NULL || sr != NULL)
    {            
        printf("%i %i\n", sl->x, sr->x);
        sl = sl->left;
        sr = sr->rigth;

    }


        
}
