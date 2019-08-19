#include <stdio.h>//Â²©öª©
#include <stdlib.h>
#define max_maze_size 10
#define max_path_size (max_maze_size * max_maze_size)
typedef struct
{
    int row, col; //row for row, col for column
    int dir;      //for the stack about the direction of the next movement
} Data;
Data stack[max_maze_size * max_maze_size], path[max_path_size];
Data dim[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int maze[max_maze_size][max_maze_size], top, path_size=0; //top for the stack
void input_data()
{
    char line[1000];
    int n = 0, i, j;

    while (scanf("%s", line) != EOF)
    {
        for (j = 0; j < strlen(line); j++) //input data
            maze[n][j] = line[j] - '0';
        n++;
    }
}
void push_stack(int r, int c, int dir) //push the new stack
{
    top++;
    stack[top].row = r;
    stack[top].col = c;
    stack[top].dir = dir;
}
void push_path( int r, int c) //push the new path
{
    if (path_size != -1 && r == path[path_size].row && c == path[path_size].col)
        return; //if the new position is same as the top of the path, don't store
    path_size++;
    path[path_size].row = r;
    path[path_size].col = c;
}
Data pop()
{
    return stack[top--];
}
void map()
{
    int r = 1, c = 1, dir, dest_r = 8, dest_c = 8, next_r, next_c; //r for row, c for column
    int found = 0, passed[max_maze_size][max_maze_size] = {0};       //the position is passed or not
    Data position;                                                   //store the tmp position

    top = -1;
    path_size = -1;
    passed[1][1] = 1;
    push_stack(r, c, 0); //push the first position into the stack
    while (top > -1 && !found)
    {
        position = pop(); //pop the top stack
        r = position.row;
        c = position.col;
        dir = position.dir;
        push_path( r, c);
        while (dir < 4 && !found)
        {
            next_r = r + dim[dir].row;
            next_c = c + dim[dir].col;
            if (next_r == dest_r && next_c == dest_c) //found, store the path
            {
                push_path( r, c);
                push_path( next_r, next_c);
                found = 1;
            }
            else if (!maze[next_r][next_c] && !passed[next_r][next_c])
            {
                //if the position can be passed, mark the place, store into stack and path, and move
                passed[next_r][next_c] = 1;
                position.row = r;
                position.col = c;
                position.dir = ++dir;
                push_stack(position.row, position.col, position.dir);
                push_path( r, c);
                r = next_r;
                c = next_c;
                dir = 0;
            }
            else //If the direction can't be passed, then choose the next direction
                dir++;
        }
        if (dir == 4) //If there isn't any direction can be entered, still store the position into the path
            push_path(r, c);
    }
}
void print_result() //Print the full path until one of them is arrived the destination
{
    int i;
    for (i = 0; i <= path_size ; i++)
    {
        printf("(%d,%d)\n" ,path[i].col , path[i].row );
    }
}
int main()
{
    freopen("13input.txt", "r", stdin);
    int i;
    input_data();
    map();
    print_result(); //print the result of the full path
    return 0;
}
