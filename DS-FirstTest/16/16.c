#include<stdio.h>
#include<string.h>
typedef struct t
{
    char str[100];
    struct t *r;
} ppl;
int main()
{
    char a[2000],*token;
    int i,j,n,all=0;
    ppl *tmp,*first,*pre;
    int cnt=0;
    freopen("16.txt","r",stdin);
    fgets(a,2000,stdin);
    a[strlen(a)-1]='\0';
    token=strtok(a,",");
    while(token!=NULL)
    {
        tmp=malloc(sizeof(ppl));
        strcpy(tmp->str,token);
        tmp->r=NULL;

        if(all==0)
        {
            first=tmp;
        }
        else
        {
            pre->r=tmp;
        }
        token=strtok(NULL,",");
        pre=tmp;
        all++;
    }
    tmp->r=first;

    scanf("%d",&n);
//    tmp=first;
//    pre=first;
    while(all>1)
    {
        cnt=0;
        while(cnt<n)
        {
            pre=tmp;
            tmp=tmp->r;
            cnt++;
        }
        printf("%s is killed\n",tmp->str);
        pre->r=tmp->r;
        all--;
    }
    printf("%s is survived\n",tmp->r);

    return 0;
}
