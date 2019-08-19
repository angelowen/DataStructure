#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 0X3F3F3F3F
int matrix [500][500],vexnum=0,edgenum=0;
typedef struct Edge
{
    int start; // 边的起点
    int end;   // 边的终点
    int weight; // 边的权重
}edge;
void sorted_edges(edge edges[], int n)
{
    int i,j;

    for (i=1; i<=n; i++)
    {
        for (j=i+1; j<=n; j++)
        {
            if (edges[i].weight > edges[j].weight)
            {
                edge tmp = edges[i];
                edges[i] = edges[j];
                edges[j] = tmp;
            }
        }
    }
}
edge* get_edges(int G[])
{
    int i,j;
    int index=1;
    edge *edges;

    edges = malloc(edgenum*sizeof(edge));
    for (i=1;i <=vexnum;i++)
    {
        for (j=i;j <= vexnum;j++)
        {
            if (matrix[i][j]!=INF)
            {
                edges[index].start  = i;
                edges[index].end    = j;
                edges[index].weight = matrix[i][j];
                index++;
//                printf("...%d %d %d\n",i,j,matrix[i][j]);
            }
        }
    }

    return edges;
}
int get_end(int vends[], int i)
{
    while (vends[i] != 0)
        i = vends[i];
    return i;
}

void kruskal(int G[])
{
    int i,m,n,p1,p2;
    int length;
    int index = 0;          // rets数组的索引
    int vends[1000]={0};     // 用于保存"已有最小生成树"中每个顶点在该最小树中的终点。
    edge rets[1000];        // 结果数组，保存kruskal最小生成树的边
    edge *edges;           // 图对应的所有边

    // 获取"图中所有的边"
    edges = get_edges(G);
    // 将边按照"权"的大小进行排序(从小到大)
    sorted_edges(edges, edgenum);

    for (i=1; i<=edgenum; i++)
    {
        p1 = edges[i].start;   // 获取第i条边的"起点"的序号
        p2 = edges[i].end;     // 获取第i条边的"终点"的序号

        m = get_end(vends, p1);                 // 获取p1在"已有的最小生成树"中的终点
        n = get_end(vends, p2);                 // 获取p2在"已有的最小生成树"中的终点
        // 如果m!=n，意味着"边i"与"已经添加到最小生成树中的顶点"没有形成环路
        if (m != n)
        {
            vends[m] = n;                       // 设置m在"已有的最小生成树"中的终点为n
            rets[index++] = edges[i];           // 保存结果
        }
    }
    //free(edges);

    for (i = 0; i < index; i++)
        printf("%d %d %d\n", rets[i].start, rets[i].end,matrix[rets[i].start][rets[i].end]);
    printf("\n");
}

int main(){
    int i,j,n;
    freopen("5input_3.txt","r",stdin);
    scanf("%d",&n);
    vexnum=n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&matrix[i][j]);
            if(matrix[i][j]!=0){
                edgenum++;
            }
            else{
                matrix[i][j]=INF;
            }
        }

    }
    edgenum/=2;
    kruskal(matrix);


return 0;
}
//https://www.cnblogs.com/skywang12345/p/3711496.html
