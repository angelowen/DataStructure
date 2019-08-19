#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int adj[100][100]; // adjacency matrix
int ref[100];     // 記錄圖上每一個點目前仍被多少條邊連到

void topological_ordering(int n)
{
    // 開始找出一個合理的排列順序
    for (int i=1; i<=n; ++i)
    {
        // 尋找沒有被任何邊連向的點
        int s = 1;
        while (s <= n && ref[s] != 0) ++s;
        if (s >n) break;  // 找不到。表示目前殘存的圖是個環。
        ref[s] = -1;        // 設為已找過（刪去s點）
        printf("%d ",s);         // 印出合理的排列順序的第i點
        // 更新ref的值（刪去由s點連出去的邊）
        for (int t=1; t<=n; ++t)
            if (adj[s][t])
                ref[t]--;
    }
}
int main(){
    int i,j,n;
    freopen("1input_2.txt","r",stdin);
    scanf("%d",&n);
    memset(ref,0,sizeof(ref));
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&adj[i][j]);
            if (adj[i][j])
                ref[j]++;// 累計圖上每一個點被幾條邊連到
        }
    }
    topological_ordering(n);
return 0;
}
