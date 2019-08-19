#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct aa{
    int vertex;
    struct aa *link;
}G;
G *graph[1000];
int ap[1000],ap_num=0,dfn[1000],low[1000],num=0;
int min(int x,int y){
    return x<y ?x:y;
}
int cmp(const void *a,const void *b){
    return *(int *)a - *(int *)b;
}
void insert(int a,int b){
    G *pre=graph[a],*cur=malloc(sizeof(G));
    cur->vertex=b;
    cur->link=NULL;
    if(pre==NULL){
        graph[a]=cur;
        return;
    }
        while(pre->link!=NULL){
            pre=pre->link;
        }
        pre->link=cur;
}
void dfnlow(int now ,int parent){
    G *ptr;
    int w, son = 0, ap_flag = 0;
    dfn[now] = low[now] = num++;
    for(ptr = graph[now]; ptr != NULL; ptr = ptr->link)
    {
        w = ptr->vertex;
        if(dfn[w]<0){
            son++;
            dfnlow(w,now);
            low[now] = min(low[now], low[w]);
            if(low[w] >= dfn[now])
                ap_flag = 1;
        }
        else if(w!=parent){
            low[now]=min(low[now],dfn[w]);
        }
    }
    if((now>parent&& son>1)||ap_flag==1){
        ap[ap_num] = now;
        ap_num++;
    }
}
int main(){
    int i,j,n,st,tmp,x;
    freopen("10input.txt","r",stdin);
    memset(ap,0,sizeof(ap));
    memset(dfn,-1,sizeof(dfn));
    memset(dfn,-1,sizeof(low));
    scanf("%d %d",&st,&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&tmp);
            if(tmp){
                insert(i,j);
            }
        }
    }
    dfnlow(st,-1);
    for(i=1;i<=n;i++){
        printf("%d ",dfn[i]);
    }
    printf("\n");
    for(i=1;i<=n;i++){
        printf("%d ",low[i]);
    }
    printf("\n");
    qsort(ap, ap_num, sizeof(ap[0]), cmp);
    for(i=0;i<ap_num;i++){
        printf("%d ",ap[i]);
    }
    printf("\n");
    return 0;
}
