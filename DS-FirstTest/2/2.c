#include <ctype.h>  //DONE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_SIZE 20
int all = 0;  // index the result of plus one by one

struct a
{
    char word[100];
    int index;
} list[100];  // create struct array，one string& one int

void prefix_table(char pattern[], int prefix[], int n)    // making prefix table
{
    prefix[0] = 0;                                          // set the first =0
    int len = 0, i = 1, j;

    while (i < n)    // i<pattern len
    {
        if (pattern[i] ==
                pattern[len])    // if the char is same len++，put len in prefix
        {
            len++;
            prefix[i] = len;
            i++;
        }
        else
        {
            if (len > 0)              // avoid the situation of len=0
            {
                len = prefix[len - 1];  // len change
            }
            else
            {
                prefix[i] = 0;  // if len=0,prefix[i]=0
                i++;
            }
        }
    }
}
void move(int prefix[],
          int n)    // move all the value beyound and make prefix[0]=-1
{
    int i;
    for (i = n - 1; i >= 0; i--)
    {
        prefix[i] = prefix[i - 1];
    }
    prefix[0] = -1;
}
int search(char text[], char pattern[])
{
    int i = 0, j = 0, prefix[100];  // i and j represented the position of
    // text,pattern array respectively
    int len_p = strlen(pattern);
    int len_text = strlen(text);
    prefix_table(pattern, prefix, len_p);  // make prefix table
    move(prefix, len_p);                   // move
    while (i < len_text)
    {
        if (j == len_p - 1 && pattern[j] == text[i])
        {
            // printf("found pattern in %d\n",i-j);
            return (i - j);
            // j=prefix[j];
        }
        if (text[i] == pattern[j])    //(text,pattern)is equall
        {
            i++;
            j++;
        }
        else
        {
            j = prefix[j];  // kmp way，move pattern forword to  prejix[j] blank
            if (j == -1)
            {
                i++;
                j++;
            }
        }
    }
    return -1;
}

int main()
{
    char text[100], pattern[100];
    int prefix[100];
    int i, j, n, pos;
    scanf("%s", text);
    scanf("%s", pattern);
    n = strlen(pattern);
    prefix_table(pattern, prefix, n);  // count prefix table to use kmp
    printf("F:");
    for (i = 0; i < n; i++)    // print prefix table
    {
        if (i == 0)
            printf("%d", prefix[i] - 1);
        else
        {
            printf(" %d", prefix[i] - 1);
        }
    }
    printf("\n");
    pos = search(text, pattern);
    if (pos == -1)
    {
        printf("Not found\n");
    }
    else
    {
        printf("Yes,%d,%d\n", pos, pos + n);
    }
    return 0;
}
