#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void sort(char s [], int start, int end);
void merge (char s [], int start, int mid, int mid1, int end);
int main(void)
{
    string line = get_string ("Число: \n");
    int n = strlen(line);
    sort(line, 0, n-1);
    printf("%s\n", line);
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




