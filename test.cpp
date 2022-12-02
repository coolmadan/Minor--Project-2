#include<bits/stdc++.h>
using namespace std;

void printSolution(int ** solution,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<solution[i][j]<<" ";
        }
    cout<<endl;
    }
    cout<<endl<<endl;
}
void mazeHelp(int maze[20][20],int * *solution,int n,int row,int col)
{
    //Base Condition
    if(row==n-1&&col==n-1)
    {
        solution[row][col]=1;
        printSolution(solution,n);
        solution[row][col]=0;
        return;
    }
    if(row>=n||col>=n||row<0||col<0||solution[row][col]==1||maze[row][col]==0)
    return;
    solution[row][col]=1;
    mazeHelp(maze,solution,n,row-1,col);
    mazeHelp(maze,solution,n,row+1,col);
    mazeHelp(maze,solution,n,row,col-1);
    mazeHelp(maze,solution,n,row,col+1);
    solution[row][col]=0;
    return;
}
void ratInAMaze(int maze[20][20],int n)
{
    int **solution= new int*[n];
    for(int i=0;i<n;i++)
    solution[i]=new int [n];
    for(int i=0;i<n;i++)
    memset(solution[i],0,n*sizeof(int));
    mazeHelp(maze,solution,n,0,0);
}
int main()
{
    int n;
    cin>>n;
    int maze[20][20];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin>>maze[i][j];
    }

    ratInAMaze(maze,n);
}