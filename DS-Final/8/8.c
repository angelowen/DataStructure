#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX   100
#define INF    0X3F3F3F3F
void swap(int *a,int *b){
    if(*a>*b){
        int tmp=*a;
        *a=*b;
        *b=tmp;
    }
}
void prim(int matrix[][500], int start,int vexnum)
{
    int min,i,j,k,m,n,sum,min_m,min_n;
    int index=0,cnt=1;         // 即prims数组的索引
    int prims[MAX];     // 结果数组
    int weights[MAX];
    prims[index++] = start;
    // 将每个顶点的权值初始化为"第start个顶点"到"该顶点"的权值。
    for (i = 1; i <= vexnum; i++ ){
        weights[i] = matrix[start][i];
    }
    weights[start] = 0;
    for (i = 1; i <= vexnum; i++)
    {
        if(start == i)
            continue;
        k = 1;
        min = INF;
        // 在未被加入到最小生成树的顶点中，找出权值最小的顶点。

        for(j=1;j<=vexnum;j++)
        {
            // 若weights[j]=0，意味着"第j个节点已经被排序过"(或者说已经加入了最小生成树中)。
            if (weights[j] != 0 && weights[j] < min)
            {
                min = weights[j];
                k = j;
            }
        }

        prims[index++] = k;
        weights[k] = 0;
        // 更新其它顶点的權值
        for (j = 1 ; j <= vexnum; j++)
        {
            // 当第j个节点没有被处理，并且需要更新时才被更新。
            if (weights[j] != 0 && matrix[k][j] < weights[j])
                weights[j] = matrix[k][j];
        }
    }
    // 计算最小生成树的权值
    sum = 0;
    for (i = 1; i < index; i++)
    {
        min = INF;
        n =prims[i];
        // 在vexs[0...i]中，找出到j的权值最小的顶点。
        for (j = 0; j < i; j++)
        {
            m = prims[j];
            if (matrix[m][n]<min){
                min = matrix[m][n];
                min_m=m;
                min_n=n;
            }

        }
        swap(&min_m,&min_n);
        printf("%d %d %d %d\n",cnt,min_m,min_n,matrix[min_m][min_n]);
                cnt++;
    }

}
int main(){
    int matrix[500][500],n,i,j,min=INF,st;
    freopen("8input_3.txt","r",stdin);
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&matrix[i][j]);
            if(matrix[i][j]==0){
                matrix[i][j]=INF;
            }
            else{
                if(matrix[i][j]<min){
                    min=matrix[i][j];
                    st=i;
                }
            }

        }
    }
    prim(matrix,st,n);

return 0;
}
