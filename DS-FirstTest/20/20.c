#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int all = 0;
char final[1000] = "";
void table(char pattern[], int prefix[], int n)    // making prefix table
{
    prefix[0] = 0;                                          // set the first =0
    int len = 0, i = 1, j;

    while (i < n)    // i<pattern len
    {
        if (pattern[i] == pattern[len])    // if the char is same len++¡Aput len in prefix
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
void insert(char a[])
{
    int i, j, k = 0;
    char tmp[1000];

    if (!strlen(final))
    {
        strcpy(final, a);
    }
    else
    {
        // strncpy(tmp,final,all);
        // strcat(tmp, a);
        // strcat(tmp, final + all);
        // strcpy(final, tmp);
        for (i = 0; i < strlen(final); i++)
        {
            if (i == all)
            {
                for (j = 0; j < strlen(a); j++)
                {
                    tmp[k] = a[j];
                    k++;
                }
                tmp[k] = final[i];
                k++;
            }
            else
            {
                tmp[k] = final[i];
                k++;
            }
        }
        tmp[k]='\0';
        strcpy(final, tmp);
    }

    printf("%s\n", final);
}
int main()
{
    int i, j, n;
    char a[1000], *ptr, *qtr, pop[100];
    int prefix[100];
    freopen("20input.txt","r",stdin);
    while (fgets(a, 1000, stdin) != NULL)
    {
        if (a[1] == ':')
        {
            printf("Final string : %s\n", final);
            a[strlen(a) - 1] = '\0';
            ptr = strstr(a, ":");
            ptr++;
            strcpy(pop, ptr);
            table(pop,prefix,strlen(pop));
            ptr = strstr(final, pop);
            printf("Last string : ");
            qtr = final;
            while (*qtr != '\0')
            {
                if (qtr == ptr)
                {
                    qtr += strlen(pop);
                }
                else
                {
                    printf("%c", *qtr);
                }
                qtr++;
            }
            printf("\n");

        }
        else
        {
            ptr = strtok(a, ",");
            qtr = strtok(NULL, ",");
            insert(ptr);
            all += atoi(qtr);
        }
    }
    printf("lps:{");
    for(i=0; i<strlen(pop); i++)
    {
        printf("%d ",prefix[i]);
    }
    printf("}\n");
    return 0;
}
