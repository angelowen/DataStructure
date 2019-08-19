#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define IN 999
void dij(int cost[][100],int st,int end,int n)
{
    int i,j,dist[1000],visit[1000]= {0},pre[1000];
    int index=0,res[1000],d,min;
    for(i=1; i<=n; i++)
    {
        pre[i]=-1;
        dist[i]=IN;
    }
    dist[st]=0;
    while(!visit[end])
    {
        int m=0,min=IN;
        for(i=1; i<=n; i++)
        {
            d=dist[st]+cost[st][i];
            if(d<dist[i]&&!visit[i])
            {
                dist[i]=d;
                pre[i]=st;
            }
            if(dist[i]<min&&!visit[i])
            {
                min=dist[i];
                m=i;
            }
        }
            st=m;
            visit[m]=1;
        if(m==0)
        {
            printf("-1\n");
            return;
        }
    }
    st=end;
    while(st!=-1){
        res[index++]=st;
        st=pre[st];
    }
    for(j=index-1;j>=0;j--){
        printf("%d ",res[j]);
    }
}
int main()
{
    int i,j;
    int co,n;
    int source, target;
    int cost[100][100];
    freopen("7input_1.txt","r",stdin);
    scanf("%d",&n);
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            scanf("%d",&cost[i][j]);
            if (cost[i][j]==0)
                cost[i][j]=IN;
        }
    scanf("%d %d", &source,&target);
    dij(cost,source,target,n);
    return 0;
}
