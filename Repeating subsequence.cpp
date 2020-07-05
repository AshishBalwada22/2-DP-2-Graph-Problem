
int Solution::anytwo(string A) {
    //concept of lcs
    //A[i-1]==B[j-1],m uss element ko lcs m tabhi include karunga iff i!=j
    string B=A;
    int n=A.length();
    int m=B.length();
    int t[101][101];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0||j==0)
            {
                t[i][j]=0;
            }
            else if(A[i-1]==B[j-1]&&i!=j)
            {
                t[i][j]=1+t[i-1][j-1];
            }
            else
            {
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    if(t[n][m]>=2)
    {
        return 1;
    }
    else return 0;
}
