#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
int a[N];
int read(){
    int num=0;
    while(scanf("%d",&a[num])!=EOF){
        num++;
    }
    return num;
}
void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void print(int b[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%3d ",b[i]);
    }
    printf("\n");
}
void select(int b[],int len){
    int i,j,min=1000,pos,step=0;
    for(i=0;i<len;i++){
        min=1000;
        for(j=i;j<len;j++){
            if(b[j]<min){
                min=b[j];
                pos=j;
            }
        }      
        step++;
        swap(&b[i],&b[pos]);
        print(b,len);
    }
    printf("Total step: %d\n\n",step);
}
void insert(int b[],int len){
    int i,tmp,step=1,k;
    print(b,len);
    for(i=1;i<len;i++){
        tmp = b[i];
        k=i;//key point
        while(tmp < b[i-1]){
            b[i] = b[i-1]; 
            i--;
            if(i<=0){
                break;
            }   
        }
        b[i] = tmp;
        i=k;//key point
        step++;
        print(b,len);               
    }
    
    printf("Total step: %d\n\n",step);
}
void bubble(int b[],int n){
    int i,j,step=0;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(b[j]>b[j+1]){
                
                swap(&b[j],&b[j+1]);
            }
        }
        print(b,n);
        step++;
    }
    print(b,n);
    printf("Total step: %d\n\n",step);
}
void quick(int b[],int left,int right,int len){
    int pivot, i, j;
    if (left >= right) {
         return;
    }
    pivot = b[left];
    i = left + 1;
    j = right;
    while (1)
    {
        while (i <= right)
        {
            if (b[i] > pivot)
            {
                break;
            }
            i++;
        }
        while (j > left)
        {
            if (b[j] < pivot)
            {
                break;
            }
            j--;
        }
        if (i > j) { break; }
        swap(&b[i], &b[j]);
    }
    swap(&b[left], &b[j]);
    print(b,len);
    quick(b, left, j - 1,len);
    quick(b, j+ 1, right,len);
    
}
void copy(int b[],int len){
    int i;
    for(i=0;i<len;i++){
        b[i]=a[i];
    }
}
int main(){
    int len=0,b[N],i,j;
    freopen("test.txt","r",stdin);
    len=read();
    copy(b,len);
    printf("Input array:\n");
    print(b,len);
    printf("\n");
    printf("selection sort:\n");
    select(b,len);
    copy(b,len);
    printf("bubble sort:\n");
    bubble(b,len);
    copy(b,len);
    printf("insertion sort:\n");
    insert(b,len);
    copy(b,len);
    printf("quick sort:\n");
    quick(b, 0, len - 1,len);

    return 0;
}