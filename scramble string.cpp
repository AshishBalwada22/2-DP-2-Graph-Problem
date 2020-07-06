//this question based upon matrix chain multiplication
unordered_map<string,int> m;
int solve(string A,string B)
{
    if(A.compare(B)==0) return 1;
    //dono ki length equal hai and fir dono equal nahi huye
    if(A.length()<=1)//length 1 hogi tabhi bhi m swap karke m equal string nahi bna paunga
    return 0;
    string key=A;
    key.push_back(' ');
    key.append(B);
    if(m.find(key)!=m.end())
    return m[key];
    int flag=0;//let this two string  not be scramble
    int n=A.length();
    for(int i=1;i<=n-1;i++)//m sari length pe break karke dekh lunga
    {
        int withswapping=solve(A.substr(0,i),B.substr(n-i,i))&&solve(A.substr(i,n-i),B.substr(0,n-i));
        int withoutswapping=solve(A.substr(0,i),B.substr(0,i))&&solve(A.substr(i,n-i),B.substr(i,n-i));
        if(withoutswapping||withswapping)
        {
            flag=1;
            break;
        }
    }
    return m[key]=flag;
}
int Solution::isScramble(const string A, const string B) {
    if(A.length()!=B.length()) return 0;
    if(A.length()==0||B.length()==0) return 1;
    m.clear();
    return solve(A,B);
}

