#include<stdio.h>
#include<string.h>
int main(){
    int n,i,j;
    char a[100];
    freopen("19input-2.txt","r",stdin);
    while(scanf("%d %s",&n,a)!=EOF){
        if(n>strlen(a)){
            printf("%s",a);
        }
        else{
            for(i=0;i<strlen(a);i+=n){
                for(j=i+n-1;j>=i;j--){
                    printf("%c",a[j]);
                }
            }
            printf("\n");
        }

    }

return 0;
}
