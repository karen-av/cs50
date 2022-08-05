#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

bool search(int nn, char array[], int lower, int upper);
void sort(char s [], int start, int end);
void merge (char s [], int start, int mid, int mid1, int end);
int main(void)

{
    string linee = get_string ("Число: \n");
    int n = strlen(linee);
    sort(linee, 0, n-1);
    int sea = get_int("Get int for search in array: ");
    if (search(sea, linee, 0, n -1))
    {
        printf("Search !!! \n");
    }
    else
    {
    printf("No search\n");
    }
    for(int i = 0; i < n; i++)
    {
        printf("%i ", (char)(int)linee[i] - 48);
    }
    printf("\n");

}



void sort(char s[], int start, int end)
{
    if(end > start)
    {
        int mid = (start + end) / 2;
        sort(s, start, mid);
        sort(s, mid + 1, end);
        merge(s, start, mid, mid + 1, end);
    }
}

void merge(char s[], int start, int smid, int mid1, int end)
{
    char news[end + 1];
    for(int i = start, j = mid1, l = 0, n = end - start + 1; l < n;)
    {
        if (s[i] <= s[j] && i <= smid && j <= end)
        {
            news[l] = s[i];
            i++;
            l++;
        }
        if (s[j] <= s[i] && i <= smid && j <= end)
        {
            news[l] = s[j];
            j++;
            l++;
        }
        if (i > smid && j <= end)
        {
            news[l] = s[j];
            j++;
            l++;
        }
        if (j > end && i <= smid)
        {
            news[l] = s[i];
            i++;
            l++;
        }
    }
    for(int i = 0, t = start; t < end + 1; )
    {
        s[t] = news[i];
        t++;
        i++;
    }
}


bool search(int nn, char array[], int lower, int upper)
{
    int mid = (lower + upper) / 2;
    printf(" mid = %i, lower = %i, upper = %i, (int)array[mid] = %i, (int)array[mid+1] = %i \n", mid, lower, upper, (int)(array[mid] - 48), (int)(array[mid+1]-48));

    if (lower == 0 && upper == 1 && ((int)array[0] - 48) != nn && ((int)array[1] - 48) != nn)
    {
        return false;
    }
    else if (nn == (int)array[mid] - 48)
    {
        return true;
    }
    else if (nn == (int)array[mid + 1] - 48)
    {
        return true;
    }
    else if (nn > (int)array[mid] - 48)
    {
        return search(nn, array, mid + 1, upper);
    }
    else if (nn < array[mid] - 48)
    {
        return search(nn, array, lower, mid);
    }

return false;
}

