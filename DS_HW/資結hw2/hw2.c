#include<stdio.h>//缺圍牆
#include<string.h>
#include<stdlib.h>
#define SIZE 17
typedef struct a{
    int x;
    int y;
}pos;
pos pt(int x, int y) {
    pos p = {x, y};
    return p;
}
int visit(int maze[][SIZE], pos start, pos end) {
    printf("%d %d\n",start.x-1,start.y-1);
    if(!maze[start.x][start.y]) {
         maze[start.x][start.y] = 5;//走過了
         if(!maze[end.x][end.y] &&
            
            !(visit(maze, pt(start.x, start.y + 1), end) || 
              visit(maze, pt(start.x + 1, start.y), end) ||
              visit(maze, pt(start.x, start.y - 1), end) || 
              visit(maze, pt(start.x - 1, start.y), end))
              ) 
              {
                 maze[start.x][start.y] = 0;
              }
        //  if(maze[start.x][start.y] == 5){
             
        //  }
    }
   // printf("%d\n",maze[end.x][end.y]);
    return maze[end.x][end.y];
    
}

void print(int maze[][SIZE]) {
    int i, j;
    
    for(i = 0; i < SIZE; i++) { 
        for(j = 0; j < SIZE; j++) { 
            //printf("%d",maze[i][j]);
            switch(maze[i][j]) {
            case 0 : printf("-"); break;
            case 5 : printf("R"); break;
            case 1 : printf("*"); 
            }
        }
       
        printf("\n"); 
    }     
}
int main(int argc, char const *argv[])
{
    int i,j,n=0;
    char Maze[SIZE][SIZE];
    int maze[SIZE][SIZE];
    for(i=0;i<SIZE;i++){
        memset(maze[i],0,sizeof(maze[0]));
    }
    for(i=0;i<SIZE;i++){
       maze[0][i]=1;
       maze[SIZE-1][i]=1;
       maze[i][0]=1;
       maze[i][SIZE-1]=1;
    }
    while(scanf("%s",Maze[n])!=EOF){
            n++;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            maze[i+1][j+1]=Maze[i][j]-'0';
            printf("%d",maze[i+1][j+1]);
        }
        printf("\n");
    }
    //  int maze[SIZE][SIZE] = {{2, 2, 2, 2, 2, 2, 2}, 
    //                         {2, 0, 0, 0, 0, 0, 2}, 
    //                         {2, 0, 2, 0, 2, 0, 2}, 
    //                         {2, 0, 0, 2, 0, 2, 2}, 
    //                         {2, 2, 0, 2, 0, 2, 2}, 
    //                         {2, 0, 0, 0, 0, 0, 2}, 
    //                         {2, 2, 2, 2, 2, 2, 2}}; 

    if(!visit(maze, pt(1, 1), pt(15, 15))) {
        printf("\n沒有找到出口！\n"); 
    }
    print(maze);
    return 0;
}
