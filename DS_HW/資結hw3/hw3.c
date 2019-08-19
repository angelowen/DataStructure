#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct link{
    char str[100];
    struct link *r;
    struct link *l;
}node;

int all=0;
node *first;

void right(int skip){
    node *ptr=first,*del=first;
    int cnt=0;
    while(del->r!=del){
        printf("list length is : %d\n",all);
        while(cnt!=skip+1){
            ptr=del;
            del=del->r;
            cnt++;
        }
        printf("the data is poped: %s\n",del->str);
        ptr->r=del->r;
        ptr=del;//->r
        del=ptr;
        all--;
        cnt=0;
    }
    printf("the last data is: %s\n",del);
}
void left(){

}
void read_com(){
    node *ptr,*pre,*tmp;
    int i;
    printf("how many node do you want to append\n");
    scanf("%d",&all);
    for(i=0;i<all;i++){
              ptr=malloc(sizeof(node));
              scanf("%s",ptr->str);
              if (i==0){
                  first=ptr;                 
              }
              else{
                  pre->r=ptr;
              }
              pre=ptr;
              printf("%s is appended\n",ptr->str);                   
    }
       ptr->r=first;

       printf("[");
       printf("%s",first->str);
       tmp=first->r;
       while(tmp!=first){
           printf(", %s",tmp->str);
           tmp=tmp->r;
       }
       printf("]\n"); 
}

void Load_CSV()
{
    printf("Start read data from a file\n");
       FILE *fp;
       char a[100];
       node *ptr,*pre,*tmp;
       if( ( fp = fopen( "data.csv", "r")) == NULL) 
       {
              printf("Cannot oepn the file\n");
       }
       while (!feof(fp))
       {
              ptr=malloc(sizeof(node));
              fscanf( fp, "%s",ptr->str);
              if (all==0){
                  first=ptr;                 
              }
              else{
                  pre->r=ptr;
              }
              pre=ptr;
              all++;
              printf("%s is appended\n",ptr->str);
                      
       }
       ptr->r=first;
       fclose(fp);
       printf("The list datas are :\n");
       printf("[");
       printf("%s",first->str);
       tmp=first->r;
       while(tmp!=first){
           printf(", %s",tmp->str);
           tmp=tmp->r;
       }
       printf("]\n");      
}

int main(int argc, char const *argv[])
{
    int com,dir,skip;
    while(1){
        printf("What do you want to do?\n");
        printf("\t\t(1)Read data from a file\n");
        printf("\t\t(2)Append new nodes\n");
        printf("\t\t(0)Exit\n");
        scanf("%d",&com);
        if(com==0){
            return 0;
        }
        else if(com==1){
            Load_CSV();
        }
        else if(com==2){
            read_com();
        }
        printf("choose direction\n\n");
        printf("\t\t(1)right\n");
        printf("\t\t(2)left\n");
        scanf("%d",&dir);
        printf("the skip number is:");
        scanf("%d",&skip);
        if(dir==1){
            right(skip);
        }
        else {
            left(skip);//左邊未連線
        }
    }
    return 0;
}
