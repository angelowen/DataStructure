#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int count(char c)
{
    if(c=='+'||c=='-')
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
int main()
{
    char c,stack[100];
    int max=0,s=0,i;
    freopen("6.txt","r",stdin);
    while((c=getchar())!=EOF)
    {
        if(isalpha(c))
        {
            printf("%c ",c);
        }
        else if(c==' '||c=='\n')
        {
            continue;
        }
        else
        {
            if(s==0)
            {
                stack[s]=c;
                s++;
            }
            else
            {
                if(count(c)>count(stack[s-1]))
                {
                    stack[s]=c;
                    s++;
                }
                else
                {
                    while(count(c)<=count(stack[s-1]))
                    {
                        printf("%c ",stack[s-1]);
                        s--;
                        if (s == 0)
                        {
                            break;
                        }
                    }
                    stack[s]=c;
                    s++;

                }
                if(s>max)
                {
                    max=s;
                }
            }

        }

    }
    for(i=s-1; i>=0; i--)
    {
        printf("%c ",stack[i]);
    }
    printf("\n");
    printf("%d", max);
    return 0;
}
