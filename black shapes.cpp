void dfs(vector<string>&A,int i,int j,vector<vector<bool>>&visited)
{
    if(i<0||j<0||i>=A.size()||j>=A[0].length()||A[i][j]!='X') return;
    if(visited[i][j]) return;
    visited[i][j]=true;
    //explore all 4 direction
    dfs(A,i+1,j,visited);
    dfs(A,i-1,j,visited);
    dfs(A,i,j+1,visited);
    dfs(A,i,j-1,visited);
}
int Solution::black(vector<string> &A) {
    int n=A.size();
    int m=A[0].length();
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]=='X')
            {
                if(!visited[i][j])
                {
                    dfs(A,i,j,visited);
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

