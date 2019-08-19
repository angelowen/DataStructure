#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print(int a[],int len){
    int i;
    for(i=0;i<len;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
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
        print(b,len);
    }
    swap(&b[left], &b[j]);
    print(b,len);
    quick(b, left, j - 1,len);
    quick(b, j+ 1, right,len);

}
int main()
{
    int len=0,a[1000];
    freopen("4input_3.txt","r",stdin);
    while(scanf("%d",&a[len])!=EOF){
        len++;
    }
    quick(a,0,len-1,len);
    return 0;
}

