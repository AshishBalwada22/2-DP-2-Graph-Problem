int match(const string &A,const string &B,int i,int j,unordered_map<int,unordered_map<int,bool>>&dp)
{
    if(i==A.length()&&j==B.length()) return 1;
    if(j==B.length()) return 0;
    if(i==A.length()&&B[j]!='*') return 0;
    if(dp.find(i)!=dp.end()&&dp[i].find(j)!=dp[i].end()) return dp[i][j];
    int ans=0;
    if(i==A.length()&&B[j]=='*')
    ans=match(A,B,i,j+1,dp);
    else if(A[i]==B[j]||B[j]=='?')
    ans=match(A,B,i+1,j+1,dp);
    else if(B[j]=='*')
    {
        ans=match(A,B,i+1,j,dp);
        if(!ans)//agar mera usse answer nahi aaya tabhi star ko skip kardunag
        ans=match(A,B,i,j+1,dp);//toh isse bhi mangwa lunga
    }
    dp[i][j]=ans;
    return ans;
}
int Solution::isMatch(const string A, const string B) {
    int nonstarlength=0;
    for(int i=0;i<B.length();i++)
    {
        if(B[i]!='*')
        nonstarlength++;
    }
    if(nonstarlength>A.length())
    return 0;
    int n=A.length();
    int m=B.length();
    unordered_map<int,unordered_map<int,bool>> dp;
    return match(A,B,0,0,dp);
}
