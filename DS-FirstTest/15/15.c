#include<stdio.h>
int count(int n){
    int sum=0;
    while(n/10!=0){
        sum+=n%10;
        n/=10;
    }
    sum+=n;
    if(sum>=10){
        count(sum);
    }
    else {
        return sum;
    }

}
int main(){
    int n,i,j;
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",count(n));
    }


return 0;
}
