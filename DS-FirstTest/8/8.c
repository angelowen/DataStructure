#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int com,i,j,n=0,start=0,val,all=0;
    int queue[100];
    freopen("8_1.txt","r",stdin);
    while(scanf("%d",&com)!=EOF)
    {
        if(com==1)
        {
            scanf("%d",&val);
            if(all==5)
            {
                printf("The queue is full.\n");
                continue;
            }
            queue[n]=val;
            n++;
            all++;
        }
        else if(com==2)
        {
            if(all==0){
                continue;
            }
            start++;
            all--;
        }
        else
        {
            if(n>5)
            {
                printf("The queue is full.\n");
            }
            else if(n<=0)
            {
                printf("The queue is empty.\n");
            }
            else
            {
//                    printf("%d %d\n",start,n);
                for(i=start; i<(start+all); i++)
                {
                    printf("%d ",queue[i]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
