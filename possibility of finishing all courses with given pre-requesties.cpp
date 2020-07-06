int dfs(unordered_map<int,int>&m,int si,vector<bool>&visited)
{
    visited[si]=true;
    if(m.find(si)!=m.end())//uske corresponding vertex hoga
    {
        if(visited[m[si]]) return 0;
        return dfs(m,m[si],visited);
    }
    return 1;
}

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    //directed graph
    //concept- if there is an cycle in graph - not possible to do all task
    if(B.size()==0) return 1;
    unordered_map<int,int>m;
    for(int i=0;i<B.size();i++)
    {
        m[B[i]]=C[i];//directed edge
    }
    vector<bool>visited(A+1,false);
    return dfs(m,B[0],visited);
}

