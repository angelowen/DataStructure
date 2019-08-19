#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void print(int a[],int len){
    int i;
    for(i=0;i<len;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main(){
    int i,j,len=0,a[1000];
    freopen("9input_1.txt","r",stdin);
    while(scanf("%d",&a[len])!=EOF){
        len++;
    }
    for(i=0;i<len-1;i++){
        for(j=0;j<len-1-i;j++){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
            }
        }
        print(a,len);
    }
    print(a,len);


return 0;
}
