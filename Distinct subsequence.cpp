
int Solution::numDistinct(string A, string B) {
    //related to concept of lcs
    int n=A.length();
    int m=B.length();
    int t[701][701];
    //string A --> string B(subsequence of A)
    for(int i=0;i<=m;i++)//convert empty A -> string B
    {
        t[0][i]=0;
    }
    for(int i=0;i<=n;i++)//convert string A -->empty B
    {
        t[i][0]=1;//ek hi no. of ways hoga-sabko delete karte chale jaunga
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;i++)
        {
            if(j>i)//not possible ,how i convert any string into larger string
            t[i][j]=0;
            else if(A[i-1]==B[j-1])
            {
                //no.of ways=element include karke(i-1 length ki string A --> string B(j-1))
                            //not include(i-1 length ki string A ->string B(lenght j))
                t[i][j]=t[i-1][j-1]+t[i-1][j];
            }
            else
            {
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][m];
}

