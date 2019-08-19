#include<stdio.h>
#include<string.h>
#include<ctype.h>
typedef struct t
{
    char c;
    struct t *r;
    struct t *l;
} word;
int main(){
    char str[100];
    int i,j,n;
    word *cur,*tmp,*pre,*fir,*last;
    freopen("18input.txt","r",stdin);
    while(scanf("%s",str)!=EOF){
        for(i=0;i<strlen(str);i++){
                cur=malloc(sizeof(word));
                cur->r=NULL;
                cur->c=tolower(str[i]);
            if(i==0){
                fir=cur;
                cur->l=NULL;
            }
            else{
                pre->r=cur;
                cur->l=pre;
            }
            pre=cur;
        }
        printf("%s",str);
        last=cur;

            while(last->c==cur->c){
                cur=cur->l;
            }
        while(cur!=NULL){
            printf("%c",cur->c);
            cur=cur->l;
        }
        printf("\n");
    }
return 0;
}
