#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LINE_SIZE 20
int all=0;//index 一個個相加的結果
char final[100];//最後用於pop的string
struct a{
    char word[100];
    int index;
}list[100];
void insert(char  *a,char *s1, char *s2, int pos) 
{ 
        all+=pos;
        int len1=strlen(s1), len2= strlen(s2),i,j,n=0;
      //  printf("%d\n",all);
       for(i=0;i<len1;i++){
           if(i==all){
               for(j=0;j<len2;j++){
                   a[n]=s2[j];
                   n++;
               }
           }
           a[n]=s1[i];
           n++;          
       }
       a[n]='\0';
} 
void process(int num,char tmp[][100]){
    int j,now=0;
    for(j=1;j<num;j++){
        if (j==1){
            insert(tmp[now],list[j-1].word,list[j].word,list[j-1].index);
            printf("insert word to main string: %s\n",tmp[now]);
        }
            
        else{
            insert(tmp[now+1],tmp[now],list[j].word,list[j-1].index);
            printf("insert word to main string: %s\n",tmp[now+1]);
            now++;
       }
            
   }
   strcpy(final,tmp[now]);//+1-1
}

void Load_CSV(void)
{
       FILE *fp;
       char tmp[100][100];
     int num=0;
     char line[MAX_LINE_SIZE];
     char *result = NULL;
    fp = fopen("data.csv", "r");
    
    if (!fp) {
        fprintf(stderr, "failed to open file for reading\n");
        return ;
    }
    
    printf("===============================\n");
    while(fgets(line, MAX_LINE_SIZE, fp) != NULL) {
        
        result = strtok(line, ",");
        int i = 0;
       
        while( result != NULL ) {
            if(i!=0){
                list[num].index=atoi(result);
                printf("===the index: %d\n",list[num].index);
            }
            else{
                strcpy(list[num].word,result);
                printf("===the name:  %s\n",list[num].word);
                i++;
            }
            result = strtok(NULL, ",");
            
        }
        num++;
    }
    
    fclose (fp); 
   printf("===============================\n"); 
   process(num,tmp);
    
}
void com_process(int num,char tmp[][100]){//command line 輸入時的字串重新組合
    int j,now=0;
    
    for(j=1;j<num;j++){
        if (j==1){//將字串2插入於字串1的index處
            insert(tmp[now],list[j-1].word,list[j].word,list[j-1].index);
        }
            
        else{//j>1的情況
             insert(tmp[now+1],tmp[now],list[j].word,list[j-1].index);
            now++;
       }      
   }
   strcpy(final,tmp[now]);//now+1-1，所以是tmp[now]
}
void read_com(){
        int n=0,i,j;
        char tmp[100][100];
        printf("===input name\n->");
        while(scanf("%s",list[n].word)!=EOF){
            printf("===input index\n->");
            scanf("%d",&list[n].index);
            n++;
            printf("===input name\n->");
        }
        printf("===============================\n"); 
        for(i=0;i<n;i++){
            printf("===the name: %s\n",list[i].word);
            printf("===the index: %d\n",list[i].index);
        }
        printf("===============================\n"); 
        com_process(n,tmp);
}
void prefix_table(char pattern[],int prefix[],int n){
    prefix[0]=0;
    int len=0,i=1,j;
    
    while(i<n){
        if(pattern[i]==pattern[len]){
            len++;
            prefix[i]=len;
            i++;
        }
        else{
            if(len>0){
                len=prefix[len-1];
            }
            else{
                prefix[i]=0;
                i++;
            }
        }

    }
}
void move(int prefix[],int n){//移動prefix table 使prefix[0]=-1
    int i;
    for(i=n-1;i>=0;i--){
        prefix[i]=prefix[i-1];
    }
    prefix[0]=-1;
}
int search(char text[],char pattern[]){
    int i=0,j=0,prefix[100];//i和j 分別代表指向text,pattern陣列上的位置
    int len_p=strlen(pattern);
    int len_text=strlen(text);
    prefix_table(pattern,prefix,len_p);
    move(prefix,len_p);
    while(i<len_text){
        
        if(j==len_p-1&&pattern[j]==text[i]){
            //printf("found pattern in %d\n",i-j);
            return (i-j);
           // j=prefix[j];
        }
        if(text[i]==pattern[j]){
            i++;j++;
        }
        else{
            j=prefix[j];
            if(j==-1){
                i++;j++;
            }
        }
    }

}
void pop(){
    char str[100];
    char res[100];
    int prefix[100],n,i,pos,now=0;
    
    printf("input pop name\n");
    scanf("%s",str);
    printf("pop name is: %s\n",str);
    n=strlen(str);
    prefix_table(str,prefix,n);
    printf("lps={");
    for(i=0;i<n;i++){
        if(i==0)
            printf("%d",prefix[i]);
        else{
            printf(",%d",prefix[i]);
        }
    }
    printf("}\n");
   pos=search(final,str);
    for(i=0;i<strlen(final);i++){
        if(i>=pos&&i<pos+n){
            continue;
        }
        res[now]=final[i];
        now++;
    }
    res[now]='\0';
   printf("The output is:%s\n",res);
}
int main(int argc, char const *argv[])
{
    int command;
    printf("What do you want to do?\n\n");
    printf("\t\t(1)Read data from a file\n");
    printf("\t\t(2)Write new data\n");
    printf("\t\t(3)Pop data\n");
    printf("\t\t(0)Exit\n");
    while(scanf("%d",&command)!=EOF&&command!=0){
        if (command ==1){
            Load_CSV(); 
        }
        else if(command==2){
            read_com();
        }
        else if(command==3){
            pop();
        }
    }
    return 0;
}
