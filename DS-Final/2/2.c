#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int num=0,i,j,a[500][500],in[1000],out[1000];

    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    freopen("2input_3.txt","r",stdin);

    //freopen("out1.txt","w",stdout);
    scanf("%d",&num);

    for(i=1; i<=num; i++)
    {
        for(j=1; j<=num; j++)
        {
            scanf("%d",&a[i][j]);

            if(a[i][j])
            {
                in[j]++;
                out[i]++;
            }
        }
    }
    for(i=1; i<=num; i++)
    {
        printf("%d %d %d\n",i,in[i],out[i]);
    }
    return 0;
}
