#define x A
#define y B
#define n C
#define r D
#define x_cord E
#define y_cord F

bool issafe(vector<int>&x_cord,vector<int>&y_cord,int r,int i,int j,int x,int y,vector<vector<bool>>&visited)
{
    if(i<0||j<0||i>x||j>y)//out of bound index
    return false;
    if(visited[i][j])//phele se hi visited hai
    return false;
    //check that that cordinate must not lie in any circle
    for(int k=0;k<x_cord.size();k++)
    {
        float d=pow(i-x_cord[k],2)+pow(j-y_cord[k],2);
        if(d<=r*r)//coordinate lie in circle
        return false;
    }
    return true;
}
bool dfs(vector<int>&x_cord,vector<int>&y_cord,int r,int i,int j,int x,int y,vector<vector<bool>>&visited)
{
    if(i==x&&j==y) return true;
    //otherwise go to 8 direction
    visited[i][j]=true;
    if(issafe(x_cord,y_cord,r,i-1,j-1,x,y,visited))
    {
        if(dfs(x_cord,y_cord,r,i-1,j-1,x,y,visited)) return true;
    }
    if(issafe(x_cord,y_cord,r,i-1,j,x,y,visited))
    {
        if(dfs(x_cord,y_cord,r,i-1,j,x,y,visited)) return true;
    }
    if(issafe(x_cord,y_cord,r,i-1,j+1,x,y,visited))
    {
        if(dfs(x_cord,y_cord,r,i-1,j+1,x,y,visited)) return true;
    }
    if(issafe(x_cord,y_cord,r,i,j+1,x,y,visited))
    {
        if(dfs(x_cord,y_cord,r,i,j+1,x,y,visited)) return true;
    }

    if(issafe(x_cord,y_cord,r,i+1,j+1,x,y,visited))
    {
        if(dfs(x_cord,y_cord,r,i+1,j+1,x,y,visited)) return true;
    }
    if(issafe(x_cord,y_cord,r,i+1,j,x,y,visited))
    {
        if(dfs(x_cord,y_cord,r,i+1,j,x,y,visited)) return true;
    }
    if(issafe(x_cord,y_cord,r,i+1,j-1,x,y,visited))
    {
        if(dfs(x_cord,y_cord,r,i+1,j-1,x,y,visited)) return true;
    }
    if(issafe(x_cord,y_cord,r,i,j-1,x,y,visited))
    {
        if(dfs(x_cord,y_cord,r,i,j-1,x,y,visited)) return true;
    }
    return false;
}
string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    vector<vector<bool>>visited(x+1,vector<bool>(y+1,false));
    if(dfs(x_cord,y_cord,r,0,0,x,y,visited))
    return "YES";
    else return "NO";
}
