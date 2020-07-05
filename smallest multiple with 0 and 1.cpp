string Solution::multiple(int A) {
    queue<int>q;//storing remainder of that state
    vector<pair<int,char>>parent(A+1,{-1,"1"});//{parent,current-'0' or '1' choose kiya hai}
    //index represent remainder
    vector<bool> visited(A+1,false);//optimization
    q.push(1%A);
    visited[1%A]=true;
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        if(top==0)//mujhe apni string banani hai
        {
            string s="";
            while(top!=-1)
            {
                s=parent[top].second+s;
                top=parent[top].first;
            }
            return s;
        }
        //graph 11 ->left(11*10+0=110) &right(11*10+1==111) dono ka remainder le raha hu
        int left=(top*10)%A;//choose 0
        int right=(top*10+1)%A;//choose 1
        if(!visited[left])
        {
            visited[left]=true;
            q.push(left);
            parent[left].first=top;
            parent[left].second='0';
        }
        if(!visited[right])
        {
            visited[right]=true;
            q.push(right);
            parent[right].first=top;
            parent[right].second='1';//toh vo 1 choose karke aaya hoga
        }
    }
    return "";
}

/*
//concept->at each state ,ya toh uske aage "0" add ho raha hoga ya "1"
//(BFS)level order traversal- toh mujhe sabse phele minimum hi milega
//optimization-m queue m usse hi dalunga,jo phele remainder nahi aaya
//rem func-number banata chle jaunga ..sath hi sath mod lete chle jaunga(no overflow)
//gives TLE=MLE(queue<string>)
int rem(string s,int n)
{
    int r=0;
    for(int i=0;i<s.length();i++)
    {
        r=r*10+(s[i]-'0');
        r=r%n;//no overflow
    }
    return r;
}
string Solution::multiple(int A) {
    set<int>s;
    queue<string> q;
    q.push("1");
    while(!q.empty())
    {
        string t=q.front();
        q.pop();
        int r=rem(t,A);
        if(r==0)
        return t;
        if(s.find(r)==s.end())
        {
        s.insert(r);
        q.push(t+"0");
        q.push(t+"1");
        }
    }

}
*/

