#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int step[100],queue[100];

int bfs(int now,int end,int max){
    int up,down,N=0,tmp,visit[100],cnt[100];
    int front=0,rear=0,i,j;
    memset(visit,0,sizeof(visit));
    memset(cnt,0,sizeof(cnt));
    queue[rear++]=now;
    visit[now]=1;
    while(front!=rear){
       tmp=queue[front++];
       N=cnt[tmp];
       if(tmp == end)
	{
	    return N;
	}
	up =tmp+step[tmp];
        down=tmp-step[tmp];

        if(!visit[up] && up<=max)
        {
            visit[up]=1;
            cnt[up]=N+1;
            queue[rear++]=up;
        }
        if(!visit[down] && down>0)
        {
            visit[down]=1;
            cnt[down]=N+1;
            queue[rear++]=down;
        }
    }
    return -1;
}
int main(){
    int start,end,n,cnt=0,i,j,ans;

    freopen("6input_3.txt","r",stdin);
    scanf("%d %d %d",&n,&start,&end);
    for(i=1;i<=n;i++){
        scanf("%d",&step[i]);
    }
    ans=bfs(start,end,n);
    printf("%d\n",ans);

return 0;
}
