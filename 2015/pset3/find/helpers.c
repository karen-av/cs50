/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if (n > 0)
    {
        for (int start = 0, end = n - 1, mid = (start + end) / 2; n >= 1;)
        {
            if (value == values[mid])
            {
                return true;
            }
            else if (value == values[mid + 1])
            {
                return true;
            }
            else if (value > values[mid + 1])
            {
               start = mid + 1;
               mid = ( (mid + 1) + end ) / 2 ;
               n = n / 2;
            }
            else if (value < values[mid])
            {
                end = mid;
                mid = ( start + mid ) / 2 ;
                n = n / 2;
            }
            else
            {
                return false;
            }
        }

    }
    else
    {
        return false;
    }
    return false;
}

/**
bool search(int value, int values[], int n)
{
    if (n > 0)
    {
        for(int i = 0; i < n; i++)
        {
            if ( value == values[i])
            {
                return true;
            }
        }
    }
    else
    {
        return false;
    }
    return false;
}  */

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
   for (int i = 0; i < n - 1 ; i++)
   {
       int j = i + 1;
       do
       {
           if (values[j] < values[i])
           {
               int temp = values[i];
               values[i] = values[j];
               values[j] = temp;
           }
           j++;
       }
       while (j < n);
   }

}