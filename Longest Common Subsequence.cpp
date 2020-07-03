int Solution::solve(string A, string B) {
    int n=A.length();
    int m=B.length();
    int**t=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        t[i]=new int[m+1];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0||j==0)
            t[i][j]=0;
            else if(A[i-1]==B[j-1])
            {
                t[i][j]=1+t[i-1][j-1];
            }
            else
            {
               t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return t[n][m];
}

