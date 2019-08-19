#include <stdio.h>
#define FILE_MAP "maze.txt"//ready to read
#define MAP_MAXSIZE 100

#define MAX_STACK (100*100)/2 //max capability of stack
#define bool int
#define true 1
#define false 0
int n=0;
int max_x=15, max_y=15;
char map[MAP_MAXSIZE][MAP_MAXSIZE]={1};
bool passed[MAP_MAXSIZE][MAP_MAXSIZE]={0};//if passed 0->1

int rata[1000][2],ratb[1000][2],cnt_a=0,cnt_b=0;//put the result in array

typedef struct _POSITION { // coordinate data
    int x;
    int y;
}POSITION;

 
POSITION stack[MAX_STACK]; // stack declaration
POSITION passing[MAX_STACK];
int top = -1; // top of the stack
 
// To know whether stack is empty
bool IsEmpty()
{
    if(top == -1)
        return true;
    return false;
}
 
// To know whether stack is full
bool IsFull()
{
    if(top < MAX_STACK-1)
        return false;
    return true;
}
 
// pop data from stack
POSITION Pop()
{
    return stack[top--];
}
 
// push data into stack
void Push(POSITION posData)
{
    stack[++top]=posData;
}
int way(int x,int y,int *branch,bool passed[][MAP_MAXSIZE]){
	//this way is for the rat A(Right > Down > Up > Left)
		int direction=1;
		if((y-1>=0) &&  (map[x][y-1] == '0')&& (passed[x][y-1] == 0))
		{//if in the map,still not passed and it is not wall
			(*branch)++;// increase the branch, if this way can go
			direction = 4;//left
		}
        if((x-1>=0) && (map[x-1][y] == '0')&& (passed[x-1][y] == 0))
		{
			(*branch)++;
			direction = 3;//up
		}
        if((x+1<max_x) && (map[x+1][y] == '0')&&(passed[x+1][y] == 0))
		{
			(*branch)++;
			direction = 2;//down
		}	
        if((y+1<max_y) &&  (map[x][y+1] == '0')&& (passed[x][y+1] == 0))
		{  // if east can go, and hasn't passed yet
			(*branch)++; 
			direction = 1;//right
		}
		return direction;
}
int way2(int x,int y,int *branch,bool passed[][MAP_MAXSIZE]){
	//this way is for the rat B(Left > Up > Down > Right)
		int direction=1;
		if((y+1<max_y) && (map[x][y+1] == '0')&& (passed[x][y+1] == 0))
		{  // increase the branch, if this way can go
			(*branch)++; 
			direction = 1;// if east can go, and hasn't passed yet
		}
		if((x+1<max_x) &&  (map[x+1][y] == '0')&& (passed[x+1][y] == 0))
		{
			(*branch)++;
			direction = 2;//down
		}	
		if((x-1>=0) &&  (map[x-1][y] == '0')&& (passed[x-1][y] == 0))
		{
			(*branch)++;
			direction = 3;//up
		}
		if((y-1>=0) && (map[x][y-1] == '0')&& (passed[x][y-1] == 0))
		{
			(*branch)++;
			direction = 4;//left
		}
        
		return direction;
}
void run(int x, int y,int end_x,int end_y)
{
    int i,j;
	POSITION last; // last position data
	unsigned int branch = 0; // branch numbers
	int direction = 1; // 1:east, 2:south, 3:north, 4:west
	 
	while(1) // loop until reach the goal
	{
        if((x==end_x&&y==end_y)){
            break;
        }
		branch = 0; // reset branch to 0
		passed[x][y] = 1; // set this position is passed
		passing[n].x=x;
        passing[n].y=y;//record the passing way
		// TODO: choose a way to go
		if(end_x==14){
			direction=way(x,y,&branch,passed);
		}//rat A
		else if(end_x==0){
			direction=way2(x,y,&branch,passed);
		}//rat B
		

		// TODO: move forward
		if(branch > 1) // if there are many ways can go
		{
			if(!IsFull())
			{ // if stack is not full, push the branch position into the stack
				last.x = x;
				last.y = y;
				Push(last);
			}
		}
		else if(branch == 0) // if there is no route, is a dead end
		{
			
			if(!IsEmpty())
			{
				last = Pop();
				x = last.x;
				y = last.y;
                while(1){
                    if(passing[n-1].x==x&&passing[n-1].y==y){
                        break;
                    }
					if(end_x==14){
						rata[cnt_a][0]=passing[n-1].x;
						rata[cnt_a][1]=passing[n-1].y;
						cnt_a++;
					}
					else if(end_x==0){
						ratb[cnt_b][0]=passing[n-1].x;
						ratb[cnt_b][1]=passing[n-1].y;
						cnt_b++;
					}
					//  printf("(%d , %d)\n",passing[n-1].x,passing[n-1].y);
                    n--;
                }

					if(end_x==14){
						rata[cnt_a][0]=last.x;
						rata[cnt_a][1]=last.y;
						cnt_a++;
					}
					else if(end_x==0){
						ratb[cnt_b][0]=last.x;
						ratb[cnt_b][1]=last.y;
						cnt_b++;
					}
				// printf("(%d , %d)\n", last.x, last.y);//= Pop()
			}
			else
			{
				printf("fail to leave\n");
				return;
			}
			continue;
		}
		
		// TODO: choose a way from last one direction, and move forward
		switch(direction)
		{
			
			case 1:
				y = y + 1;
				//turn right
					if(end_x==14){
						rata[cnt_a][0]=x;
						rata[cnt_a][1]=y;
						cnt_a++;
					}
					else if(end_x==0){
						ratb[cnt_b][0]=x;
						ratb[cnt_b][1]=y;
						cnt_b++;
					}
				// printf("(%d , %d)\n",x,y);
			
				break;
			case 2:
				x = x + 1;
				//turn down
					if(end_x==14){
						rata[cnt_a][0]=x;
						rata[cnt_a][1]=y;
						cnt_a++;
					}
					else if(end_x==0){
						ratb[cnt_b][0]=x;
						ratb[cnt_b][1]=y;
						cnt_b++;
					}
				// printf("(%d , %d)\n",x,y);
				break;
			case 3:
				x = x - 1;
				//turn up
					if(end_x==14){
						rata[cnt_a][0]=x;
						rata[cnt_a][1]=y;
						cnt_a++;
					}
					else if(end_x==0){
						ratb[cnt_b][0]=x;
						ratb[cnt_b][1]=y;
						cnt_b++;
					}
				// printf("(%d , %d)\n",x,y);
				break;
			case 4:
				y = y - 1;
				//turn left
					if(end_x==14){
						rata[cnt_a][0]=x;
						rata[cnt_a][1]=y;
						cnt_a++;
					}
					else if(end_x==0){
						ratb[cnt_b][0]=x;
						ratb[cnt_b][1]=y;
						cnt_b++;
					}
				//  printf("(%d , %d)\n",x,y);
				break;
		}
        n++;
	}
	
	//printf("arrived\n");
}
void clean(){
	int i,j;
	for(i=0;i<max_x;i++)
    {
        for(j=0;j<max_y;j++)
        {
			passed[i][j]=0;
		}
	}
	n=0;
}
void Print(){//print the road with rat A and rat B
	FILE *fptr;
	int k1=0,k2=0,i;
	//fprintf(fptr,"ratA(0,0)ratB(14,14)\n");
    fptr = fopen("result.txt","w");//put the result in result.txt 
    if(!fptr)
    {
        printf("File loaded error!\n");
        return ;
    }
	fprintf(fptr,"ratA(0,0)\nratB(14,14)\n");
	while(k1!=cnt_a&&k2!=cnt_b){//how many road we have to write

		if(k1>1&&rata[k1][0]==rata[k1-1][0]&&rata[k1][1]==rata[k1-1][1]){
			// printf("ratB(%d,%d)\n",ratb[k][0],ratb[k][1]);
			// fprintf(fptr, "ratB(%d,%d)\n",ratb[k][0],ratb[k][1]);
			k1++;
			continue;
		}/////////
		printf("ratA(%d,%d)\n",rata[k1][0],rata[k1][1]);
		fprintf(fptr,"ratA(%d,%d)\n",rata[k1][0],rata[k1][1]);
		printf("ratB(%d,%d)\n",ratb[k2][0],ratb[k2][1]);
		fprintf(fptr, "ratB(%d,%d)\n",ratb[k2][0],ratb[k2][1]);
		k1++;k2++;
	}
 fclose(fptr);//close the file
}
int main()
{
    FILE *fptr;
    int i,j,start_x,start_y,end_x,end_y;
    // TODO: Load file
    fptr = fopen(FILE_MAP,"r");//read the maze.txt
    if(!fptr)
    {
        printf("File loaded error!\n");
        return 0;
    }
    
    for(i=0;i<max_x;i++)
    {
        for(j=0;j<max_y;j++)
        {
           fscanf(fptr, " %c", &map[i][j]);//read the map
           passed[i][j]=0;
              
        }
    }
    fclose(fptr);
    //start rat A
    start_y=0;//entrance
    start_x=0;//entrance
    end_x=14;
    end_y=14;
	run(start_y,start_x,end_x,end_y); // run maze
	clean();//clear passing,passed
    
	//start rat B
    start_y=14;//entrance
    start_x=14;//entrance
    end_x=0;
    end_y=0;
    run(start_y,start_x,end_x,end_y); // run maze
	Print();//print out the result
	
    return 0;
}
