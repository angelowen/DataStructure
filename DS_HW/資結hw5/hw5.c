#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX   100
#define INF         (~(0x1<<31))        // 最大值(即0X7FFFFFFF)
#define IN 999
int map[100][100],all=0;
typedef struct _graph
{
    int vexs[MAX];       // 頂點集合
    int vexnum;           // 顶點數
    int edgnum;           // 邊數
    int matrix[MAX][MAX];
} Graph, *PGraph;

//struct edge
typedef struct _EdgeData
{
    int start;
    int end;
    int weight;
} EData;
void print_graph(Graph G)
{
    int i,j;

    printf("Martix Graph:\n");
    for (i = 0; i < G.vexnum; i++)
    {
        for (j = 0; j < G.vexnum; j++)
            printf("%10d ", G.matrix[i][j]);
        printf("\n");
    }
}
static int get_position(Graph G, int k)
{
    int i;
    for(i=0; i<G.vexnum; i++)
        if(G.vexs[i]==k)
            return i;
    return -1;
}

void prim(Graph G, int start)
{
    int min,i,j,k,m,n,sum,head,tail;
    int index=0;         // prim最小树的索引，即prims数组的索引
    char prims[MAX];     // prim最小树的结果数组
    int weights[MAX];    // 顶点间边的权值
    start-=1;
    // prim最小生成树中第一个数是"图中第start个顶点"，因为是从start开始的。
    prims[index++] = G.vexs[start];

    // 初始化"顶点的权值数组"，
    // 将每个顶点的权值初始化为"第start个顶点"到"该顶点"的权值。
    for (i = 0; i < G.vexnum; i++ )
        weights[i] = G.matrix[start][i];
    // 将第start个顶点的权值初始化为0。
    // 可以理解为"第start个顶点到它自身的距离为0"。
    weights[start] = 0;

    for (i = 0; i < G.vexnum; i++)
    {
        // 由于从start开始的，因此不需要再对第start个顶点进行处理。
        if(start == i)
            continue;

        j = 0;
        k = 0;
        min = INF;
        // 在未被加入到最小生成树的顶点中，找出权值最小的顶点。
        while (j < G.vexnum)
        {
            // 若weights[j]=0，意味着"第j个节点已经被排序过"(或者说已经加入了最小生成树中)。
            if (weights[j] != 0 && weights[j] < min)
            {
                min = weights[j];
                k = j;
            }
            j++;
        }

        // 经过上面的处理后，在未被加入到最小生成树的顶点中，权值最小的顶点是第k个顶点。
        // 将第k个顶点加入到最小生成树的结果数组中
        prims[index++] = G.vexs[k];
        // 将"第k个顶点的权值"标记为0，意味着第k个顶点已经排序过了(或者说已经加入了最小树结果中)。
        weights[k] = 0;
        // 当第k个顶点被加入到最小生成树的结果数组中之后，更新其它顶点的权值。
        for (j = 0 ; j < G.vexnum; j++)
        {
            // 当第j个节点没有被处理，并且需要更新时才被更新。
            if (weights[j] != 0 && G.matrix[k][j] < weights[j])
                weights[j] = G.matrix[k][j];
        }
    }

    // 计算最小生成树的权值
    sum = 0;
    for (i = 1; i < index; i++)
    {
        min = INF;
        // 获取prims[i]在G中的位置
        n = get_position(G, prims[i]);
        // 在vexs[0...i]中，找出到j的权值最小的顶点。
        for (j = 0; j < i; j++)
        {
            m = get_position(G, prims[j]);
            if (G.matrix[m][n]<min)
            {
                min = G.matrix[m][n];
                head=m;
                tail=n;
            }

        }
        sum += min;
        printf("Edge %d: <%d,%d> cost: %d\n",i,G.vexs[head],G.vexs[tail],min);
    }
    printf("Minumum cost= %d\n", sum);

}


Graph* read_graph(int option,FILE *fin)
{
    int i,j,v,root;
    Graph* pG=malloc(sizeof(Graph));

    fscanf(fin,"%d",&pG->vexnum);
    for (i = 0; i <= pG->vexnum; i++)
        pG->vexs[i] =i+1 ;

    for(i=0; i<pG->vexnum; i++)
    {
        for(j=0; j<pG->vexnum; j++)
        {
            fscanf(fin,"%d",&pG->matrix[i][j]);
            if (i!=j && pG->matrix[i][j]!=0)
                pG->edgnum++;
            if (i!=j && option==2 && pG->matrix[i][j]==0)///////
                pG->matrix[i][j]=INF;

        }
    }
    pG->edgnum /= 2;
    if(option==2)
    {
        fscanf(fin,"%d",&root);
        prim(*pG, root);
    }
    return pG;
}
/*
 * 返回k在matrix矩阵中的位置
 */

void sorted_edges(EData* edges, int n)
{
    int i,j;
    for (i=0; i<n; i++)
    {
        for (j=i+1; j<n; j++)
        {
            if (edges[i].weight > edges[j].weight)
            {
                EData tmp = edges[i];
                edges[i] = edges[j];
                edges[j] = tmp;
            }
        }
    }
}
EData* get_edges(Graph G)
{
    int i,j;
    int index=0;
    EData *edges;

    edges = (EData*)malloc(G.edgnum*sizeof(EData));
    for (i=0; i < G.vexnum; i++)
    {
        for (j=i+1; j < G.vexnum; j++)
        {
            if (G.matrix[i][j]!=0)
            {
                edges[index].start  = G.vexs[i];
                edges[index].end    = G.vexs[j];
                edges[index].weight = G.matrix[i][j];
                //printf("%d %d %d\n",G.vexs[i],G.vexs[j],G.matrix[i][j]);
                index++;
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
void kruskal(Graph G)
{
    int i,m,n,p1,p2;
    int length;
    int index = 0;          // index for rets[]
    int vends[MAX]= {0};    // 用於保存"已有最小生成樹"中每個頂點在該最小樹中的終點
    EData rets[MAX];        // store the result
    EData *edges;
    // get all edges
    edges = get_edges(G);

    // small->big
    sorted_edges(edges, G.edgnum);

    for (i=0; i<G.edgnum; i++)
    {
        p1 = get_position(G, edges[i].start);   //獲取第i條邊的"起點"的序號
        p2 = get_position(G, edges[i].end);     //獲取第i條邊的"終點"的序號

        m = get_end(vends, p1);                 // 獲取p1在"已有的最小生成樹"中的終點
        n = get_end(vends, p2);                 // 獲取p2在"已有的最小生成樹"中的終點

        //printf("%d %d\n",m,n);

        if (m != n)// if m!=n，no loop
        {
            vends[m] = n;                       // 設置m在"已有的最小生成樹"中的終點為n
            rets[index++] = edges[i];           // store
        }
    }
    free(edges);

    length = 0;
    for (i = 0; i < index; i++)
    {
        printf("Edge %d: <%d,%d> cost: %d\n",i+1, rets[i].start, rets[i].end,rets[i].weight);
        length += rets[i].weight;
    }
    printf("Minumum cost= %d\n", length);
}
int dijsktra(int cost[][100],int source,int target,int N)
{
    int dist[1024],prev[1024],selected[1024]= {0},i,m,min,start,d,j;
    char path[N];
    for(i=1; i< N; i++)
    {
        dist[i] = IN;
        prev[i] = -1;
    }
    start = source;
    selected[start]=1;
    dist[start] = 0;
    while(selected[target] ==0)
    {
        min = IN;
        m = 0;
        for(i=1; i< N; i++)
        {
            d = dist[start] +cost[start][i];
            if(d< dist[i]&&selected[i]==0)
            {
                dist[i] = d;
                prev[i] = start;
            }
            if(min>dist[i] && selected[i]==0)
            {
                min = dist[i];
                m = i;
            }
        }
        start = m;
        if(m==0)
        {
            //printf("-1\n");
            break;
        }
        selected[start] = 1;
    }
    return dist[target];
}
int read(int cost[][100])
{
    int i,j,n;
    FILE *fin = fopen("input3.txt", "r");
    //freopen("input3.txt","r",stdin);
    fscanf(fin,"%d",&n);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            fscanf(fin,"%d",&cost[i][j]);
            if (cost[i][j]==0)
                cost[i][j]=IN;
        }
    }
    fclose(fin);
    return n;
}
int main()
{
    Graph* pG;
    FILE *fin;
    int i,j,option;
    int co,N;
    int source, target;
    int cost[100][100];
    fin=fopen("input1.txt","r");
    option=1;
    pG = read_graph(option,fin);
    kruskal(*pG);             // kruskal算法

    fin=fopen("input2.txt","r");
    option=2;
    pG = read_graph(option,fin);
    //----------

    N=read(cost);
    N++;
    while(1)
    {
        printf("Enter two vertices<start end>:");
        scanf(" %d %d", &source,&target);

        co = dijsktra(cost,source,target,N);
        if(co!=IN)
        {
            printf("The cost from %d to %d is : %d\n",source,target,co);
        }
        else
        {
            printf("The cost from %d to %d is : -1\n",source,target);
        }
    }
    return 0;
}

//https://goo.gl/LE9Ug8
