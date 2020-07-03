int Solution::solve(string A) {
    string B=A;
    reverse(B.begin(),B.end());
    int n=A.length();
    int m=B.length();
    vector<vector<int>>t(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(A[i-1]==B[j-1])
            t[i][j]=1+t[i-1][j-1];
            else
            t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    return t[n][m];
}

