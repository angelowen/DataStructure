#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n,i,j,graph[500][500],k;
    freopen("3input_3.txt","r",stdin);
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n ;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }

    for (int k=0; k<n; k++)
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if (graph[i][k] && graph[k][j]){
                    graph[i][j] = 1;
                }

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d",graph[i][j]);
        }
        printf("\n");
    }



    return 0;
}
