#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
typedef struct link{//define the struct
    char str[100];
    struct link *r;//point to right
    struct link *l;//point to left
}node;

int all=0;//total items
node *first;//point to first

void right(int skip){//if we choose to kill from right
    node *ptr=first,*del=first;
    int cnt=0;
    while(del->r!=del){//if the item only one
        if(all==1)break;
        printf("list length is : %d\n",all);
        while(cnt!=skip+1){//passing
            ptr=del;
            del=del->r;
            cnt++;
        }
        printf("the data is poped: %s\n",del->str);
        ptr->r=del->r;//delete the node
        ptr=del;//ptr point to the position which is deleted
        all--;
        cnt=0;
    }
    printf("the last data is: %s\n",del->r);
}
void left(int skip){//if we choose to kill from left
    node *ptr=first,*del=first;
    int cnt=0;
    while(del->l!=del){
        if(all==1)break;
        printf("list length is : %d\n",all);
        while(cnt!=skip+1){//passing
            ptr=del;
            del=del->l;
            cnt++;
        }
        printf("the data is poped: %s\n",del->str);
        ptr->l=del->l;//delete the node
        ptr=del;//ptr point to the position which is deleted
        all--;
        cnt=0;
    }
    printf("the last data is: %s\n",del->l);
}
void read_com(){//read from command line
    node *ptr,*pre,*tmp;
    int i;
    printf("how many node do you want to append\n");
    scanf("%d",&all);
    for(i=0;i<all;i++){
              ptr=malloc(sizeof(node));
              scanf("%s",ptr->str);//enter the string
              if (i==0){
                  first=ptr;     //first item            
              }
              else{
                  pre->r=ptr;//more than one item
                  ptr->l=pre;
              }
              pre=ptr;
              printf("%s is appended\n",ptr->str);                   
    }
       ptr->r=first;
       first->l=ptr;
       printf("[");//print all of the strings
       printf("%s",first->str);
       tmp=first->r;
       while(tmp!=first){
           printf(", %s",tmp->str);
           tmp=tmp->r;
       }
       printf("]\n"); 
}

void Load_CSV()//read from the file
{
    printf("Start read data from a file\n");
       FILE *fp;
       char a[100];
       node *ptr,*pre,*tmp;
       if( ( fp = fopen( "data.csv", "r")) == NULL) //if file is unable to open
       {
              printf("Cannot oepn the file\n");
       }
       while (!feof(fp))
       {
              ptr=malloc(sizeof(node));
              fscanf( fp, "%s",ptr->str);//read strings
              if (all==0){
                  first=ptr;    //the first item             
              }
              else{
                  pre->r=ptr;//more than one item
                  ptr->l=pre;
              }
              pre=ptr;
              first->l=ptr;
              all++;
              printf("%s is appended\n",ptr->str);
                      
       }
       ptr->r=first;
       fclose(fp);
       printf("The list datas are :\n");
       printf("[");//print all of the strings
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
            printf("choose direction\n\n");
            printf("\t\t(1)right\n");
            printf("\t\t(2)left\n");
            scanf("%d",&dir);
            srand(time(NULL));

            skip=(rand()%100)+1;
            printf("the skip number is:%d\n",skip);
        }
        else if(com==2){
            read_com();
            printf("choose direction\n\n");
            printf("\t\t(1)right\n");
            printf("\t\t(2)left\n");
            scanf("%d",&dir);
            printf("the skip number is:");
            scanf("%d",&skip);
        }
        
        
        if(dir==1){
            right(skip);
        }
        else {
            left(skip);
        }
    }
    return 0;
}
