
/**
 * @file struct-1.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-05-07
 *
 * @copyright Copyright (c) 2022
 *
 * linked list
 * Связанный список
 * добавление и удаление узлов
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// структура данных связанный список linked list
typedef struct node
    {
        int val;
        struct node* next;
    } node_t;

    bool search(node_t *h, int n);
    int print_list(node_t * h);
    int push(node_t * h, node_t ** hh, int v);
    int push_start(node_t **h, int v);
    int pop(node_t ** h);
    int remove_last(node_t * h);
    int add_search(node_t * h, node_t ** hh, int n);
    int del_search(node_t * h, node_t ** hh, int n);


int main(void)
{
    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));

    if (head == NULL)
    {
        return 1;
    }

    head -> val = 1;
    head -> next = (node_t *) malloc(sizeof(node_t));
    head -> next -> val = 2;
    head -> next -> next = (node_t *) malloc(sizeof(node_t));
    head -> next -> next -> val = 3;
    head -> next -> next -> next = (node_t *) malloc(sizeof(node_t));
    head -> next -> next -> next -> val = 4;

    printf("%p %p %p\n", head, head->next, head->next->next);
    

    printf("\n");
    print_list(head);

    

    //Добавляем последний узел
    printf("\nList finished, adding new value 5...\n\n");
    push(head, &head, 5);
    //print update list
    print_list(head);
    printf("\n");

    //Добавляем узел в начало
    printf("\nList finished, adding new value 0...\n\n");
    push_start(&head, 0);
    print_list(head);
    printf("\n");

     //Удаляем первый узел
    printf("\nList finished, del value 0...\n\n");
    pop(&head);
    print_list(head);
    printf("\n");

    //Удаляем последний узел
    printf("\nList finished, del value 5...\n\n");
    remove_last(head);
    print_list(head);
    printf("\n");

    //Добавляем узел в любое место

    int *x = (int*) malloc(sizeof(int));
    printf("Giv int to add\n");
    scanf("%i", x);
    printf("\nList finished, add some value...\n\n");
    add_search(head, &head, *x);
    print_list(head);
    printf("\n");
    free(x);


    //Удаляем выбранный узел
    int *y = (int *) malloc(sizeof(int));
    printf("Giv int to DEL\n");
    scanf("%i", y);
    printf("\n");
    del_search(head, &head, *y);
    print_list(head);
    printf("\n");
    free(y);

    //Ищем нужный элемент в списке
    int *s = (int *) malloc(sizeof(int));
    printf("Giv int to search\n");
    scanf("%i", s);
    printf("\n");
    if(search(head, *s))
    {
        printf("Search. %i include in list\n", *s);
    }
    else
    {
        printf("Search. %i have not in list\n", *s);
    }
    printf("\n");
    free(s);

    free(head -> next -> next -> next->next);
    free(head -> next -> next -> next);
    free(head -> next -> next);
    free(head -> next);
    free(head);
    return 0;

}


//Поиск
bool search(node_t *h, int n)
{
    node_t * carr = h;
    while ( carr != NULL)
    {
        if (n == carr->val)
        {
            return true;
        }
        carr = carr->next;
    }    
    return false;
}

// выводим на экран значение переменной и адрес каждого узла
int print_list(node_t * h)
{
    if(h == NULL)
    {
        printf("Can't open now 1\n");
        return 1;
    }
    node_t * current = h;
    while (current != NULL)
    {
        printf("Value: %d\n", current -> val);
        printf("Address: %p\n", current -> next);
        current = current -> next;
    }
    return 0;
}

// Добавляем последний узел
int push(node_t * h, node_t ** hh, int v)
{
    //создаем новый указатель на тип данных node_t и он указывает на полученный аргумент head
    // следовательно он указывает на задынный узел
    node_t * current = h;

    //Если узел был удален и узлов нет, создаем узел
    if(h== NULL)
    {
        printf("test 1\n");
        h = (node_t *) malloc(sizeof(node_t));
        h->val = v;
        h -> next = NULL;
    }
    else
    {
        // Идем к последнему узлу связанного списка
        while( current -> next != NULL )
        {
            current = current -> next;
        }
        // теперь мы можем добавить новый узел
        current -> next = malloc(sizeof(node_t));
        if(current -> next == NULL)
        {
            printf("Can't allocate now\n");
            return 2;
        }
        current -> next -> val = v;
        current ->next ->next = NULL;
    }
   return 0;

}

// добавляем узел н начало
int push_start(node_t **h, int v)
{
    node_t * new_node = malloc(sizeof(node_t));
    if(new_node == NULL)
    {
       printf("Can't allocate now\n");
       return 3;
    }
    if(*h == NULL)
    {
        new_node ->val = v;
        new_node ->next = NULL;
    }
    else
    {
        new_node -> val = v;
        new_node -> next = *h;
        *h = new_node;
    }

    //free(new_node);
    return 0;
}

//удаление первого элемента
int pop(node_t ** h)
{
    if(*h == NULL)
    {
        return 4;
    }

    //Если узел удален и узлов нет, создаем узел
    if((*h)->next == NULL)
    {
        printf("one node only\n");
        *h = NULL;
    }
    else
    {
        //Создаем новый указатель на узел и передаем ему адрес указателя next из узла, который будем удалять
        node_t * new_node = (*h) -> next;

        //Передаем головному указателю значение из иказателя узла, который будем удалять
        *h = new_node;

        // Теперь указатель на начало связанного списка указывает на второй узел
    }
    return 0;
}

//Удаляем последний узел
int remove_last(node_t * h)
{
    if (!h)
    {
        printf("Can't open h\n");
        return 5;
    }

    node_t * carr = h;
    if (carr -> next == NULL)
    {
        printf("Only one node\n");
        return 6;
    }

    //Ищем последний узел, в предпоследнем
    while (carr -> next -> next != NULL)
    {
        carr = carr -> next;
    }

    free(carr -> next);
    //Меняем значение next предпоследнего узла на NULL. Тем самым просто забывая последний узел
    carr -> next = NULL;

    return 0;
}

//Добавляем искомый узел
int add_search(node_t * h, node_t ** hh, int n)
{
    node_t * carr = h;

    //Если добавляем перед первым узлом
    if (n <= carr->val)
    {
        node_t * new = (node_t*) malloc(sizeof(node_t));
        if(!new)
        {
            printf("Error search\n");
            return 8;
        }
        new -> next = *hh;
        new -> val = n;
        *hh = new;
        printf("1-st\n");
    }

    //Если узел единственный и добавляем за ним
    else if (carr->next == NULL)
    {
        carr->next = (node_t*) malloc(sizeof(node_t));
        carr->next->next = NULL;
        carr->next->val = n;
    }

    //если узел не первый
    else if(carr->next != NULL)
    {
        //двигаемся до нужного узла или конца списка
        while (n > carr->next->val && carr->next->next != NULL)
        {
            carr =  carr->next;
        }
        // Если не последний
        if(n <= carr->next->val)
        {
            node_t * new = (node_t*) malloc(sizeof(node_t));
            if(!new)
            {
                printf("Error search\n");
                return 8;
            }
            new -> next = carr->next;
            new -> val = n;
            carr -> next = new;
            printf("if \n");
        }

        //Если последний узел
        else
        {
            carr -> next ->next = (node_t *) malloc(sizeof(node_t));
            if (carr -> next == NULL)
            {
                printf("Error search\n");
                return 7;
            }
            carr -> next -> next -> next= NULL;
            carr -> next -> next -> val = n;
            printf("Else\n");
        }
    }

    return 0;
}

//Удаляем найденный узел
int del_search(node_t *h, node_t ** hh, int n)
{
    node_t * car = *hh;
    node_t * carr = h;

    //Если первый
    if(n == carr->val)
    {
        *hh = car->next;
        return 0;
    }

    else if(n != carr->val && carr->next == NULL)
    {
        printf("Search result = 0. Only one node\n");
        return 0;
    }

    else if(n != carr->val && carr->next != NULL)
    {
        printf("Search node\n");
        //Если не первыый, то ищем нужный узел
        while (n != carr->next->val && carr->next->next != NULL)
        {
            carr = carr->next;
        }

        //Если нашли нужный узел
        if(n == carr->next->val)
        {
            carr->next = carr->next->next;
        }

        //Если нужного узла нет в списке
        else if(carr->next->next == NULL)
        {
            printf("Search result = 0\n");
        }

        //Иначе оштбка
        else
        {
            printf("Err 10\n");
            return 10;
        }
    }
    return 0;
}

