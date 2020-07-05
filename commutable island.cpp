//totally based on krushkal algorithm
//MST(minimum spanning tree)=n-1 edges with minimum weight
class edge
{
    public:
    int source;
    int destination;
    int weight;
};

bool compare(edge e1,edge e2)
{
    return e1.weight<e2.weight;
}
int findparent(int v,int*parent)
{
    if(parent[v]==v)
    return v;
    return findparent(parent[v],parent);
}
int krushkal(edge*input,int n,int e)
{
    sort(input,input+e,compare);//sort the edge on basis of cost
    //pick that edge whose weight is minimum
    int*parent=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        parent[i]=i;//harek banda khud ka parent hai
    }
    int count=0;//how many edge(n-1) we added in MST iff n= vertex
    int i=0;//pheli wali edge pe hu
    edge *output=new edge[n-1];
    while(count!=n-1)
    {
        edge currentedge=input[i];
        //vo hi edge insert karunga ki cycle na bne
        //apply union find algorithm-
        //agar dono alag alag set m lie kar rahe hai(parent alag hai) then insert kardunga
        //then fir ek ko child and ek ko parent bna dunga
        int scparent=findparent(currentedge.source,parent);
        int destparent=findparent(currentedge.destination,parent);
        if(scparent!=destparent)
        {
            output[count]=currentedge;
            count++;
            parent[scparent]=destparent;
        }
        i++;
    }
    int res=0;
    for(int i=0;i<n-1;i++)//0..n-2 =n-1 edge
    {
        res=res+output[i].weight;
    }
    return res;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    edge *input=new edge[B.size()];
    for(int i=0;i<B.size();i++)
    {
        input[i].source=B[i][0];
        input[i].destination=B[i][1];
        input[i].weight=B[i][2];
    }
    return krushkal(input,A,B.size());
}

