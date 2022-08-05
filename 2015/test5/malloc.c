/**
 * @file malloc.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-29
 * 
 * @copyright Copyright (c) 2022
 * 
 * Варианты использования указателя и malloc
 */

#include<stdio.h>
#include<stdlib.h>

int main()
{
    //one way
	int *p;
	p = (int *)malloc(sizeof(int));
	if (p == 0)
	{
		printf("ERROR: Out of memory\n");
		return 1;
	}
	*p = 5;
	printf("1st. %d\n", *p);
	free(p);

    //second way
    int *q, *w;
    q = (int *) malloc(sizeof(int));
    *q = 11;
    w = q;
    printf("2nd. - %d\n", *w);
    free(q);

    //third way
    int i = 9;
    int *r;
    r = &i;
    printf("3rd. %d\n", *r);

    //fourth way
    int *d = (int*)malloc(sizeof(int));
    d = 0;
    //*d = 5;
    // проверка выделилась ли памяти  
    if (!d)
    {
        printf("4th. Segmentation fault\n");
    }
    free(d);

    struct rec
    {
        int ii;
        float ff;
        char cc;
    };

    struct rec *pp;
    pp = (struct rec *) malloc (sizeof(struct rec));

    //проверка на выделенную память
    if(!pp)
    {
        printf("Oops! Not Enough Memory!\n");
        return 3;
    }
    pp->ii = 10;
    (*pp).ff = 3.314;
    (*pp).cc = 'a';
    printf("rec. %d, %.3f, %d\n", (*pp).ii, (*pp).ff, (*pp).cc);
    free(pp);

	return 0;
}