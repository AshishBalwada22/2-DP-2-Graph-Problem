int Solution::minDistance(string A, string B) {
    int n=A.length();
    int m=B.length();
    vector<vector<int>>t(n+1,vector<int>(m+1,-1));
    //if one string is empty ,then we have to delete or insert that no. of character
    //present in other string
    for(int i=0;i<=n;i++)
    {
        t[i][0]=i;
    }
    for(int i=0;i<=m;i++)
    {
        t[0][i]=i;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(A[i-1]==B[j-1])//dono string ko 1-1 chota karke bhej dunga
            t[i][j]=t[i-1][j-1];
            else
            {
                int option1=1+t[i-1][j-1];//replace
                int option2=1+t[i-1][j];//delete or insert
                int option3=1+t[i][j-1];//delete or insert
                t[i][j]=min(option1,min(option2,option3));
            }
        }
    }
    return t[n][m];
}

