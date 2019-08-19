#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int dfn[1000], low[1000], ap[1000], num = 0, n;
int graph[1000][1000];
int min(int x, int y)
{
    return x < y ? x : y;
}
void dfnlow(int u, int v)
{
    int w, child = 0, ap_flag = 0, i;
    dfn[u] = low[u] = num++;
    for(i = 0; i < n; i++)
    {
        if(!graph[u][i])
            continue;
        w = i;
        if(dfn[w] < 0)
        {
            child++;
            dfnlow(w, u);
            low[u] = min(low[u], low[w]);
            if(low[w] >= dfn[u])
                ap_flag = 1;
        }
        else if(w != v)
            low[u] = min(low[u], dfn[w]);
    }
    if((u == v && child > 1) || (u != v && ap_flag == 1))
        ap[u] = 1;
}
int main()
{
    int i, j, x;
    freopen("10input.txt", "r", stdin);
    memset(dfn, -1, sizeof(dfn));
    memset(low, -1, sizeof(low));
    memset(ap, 0, sizeof(ap));
    scanf("%d %d", &x, &n);
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    dfnlow(x - 1, -1);
    for(i = 0; i < n; i++)
        printf("%d ", dfn[i]);
    printf("\n");
    for(i = 0; i < n; i++)
        printf("%d ", low[i]);
    printf("\n");
    for(i = 0; i < n; i++)
        if(ap[i] == 1)
            printf("%d ", i + 1);
    printf("\n");
    return 0;
}
