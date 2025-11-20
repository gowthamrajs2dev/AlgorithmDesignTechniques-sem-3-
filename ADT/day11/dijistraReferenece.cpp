#include<bits/stdc++.h>
using namespace std;

struct Edge
{
    int src,dest,wt;
};
vector<vector<Edge>>adj;
class Graph
{
    public:
    int n;
    vector<vector<Edge>>adj;
    Graph(int n,vector<Edge>edges)
    {
        adj.resize(n);
        for(Edge e: edges)
        {
            adj[e.src].push_back(e);
            adj[e.dest].push_back({e.dest,e.src,e.wt});
        }
    }
};

struct Node
{
    int vertex,mc;
};

struct comp
{
    bool operator()( const Node &a, const Node &b )
    {
        return a.mc>b.mc;
    }
};
void buildpath(vector<int>&path,int dest,vector<int>prev)
{
    if(dest==-1)
    {
        return;
    }
    buildpath(path,prev[dest],prev);
    path.push_back(dest);
}
void spaths(int src,int n)
{
    priority_queue<Node,vector<Node>,comp> q;
    vector<int>dist(n,INT_MAX);
    dist[src]=0;
    vector<int>prev(n,-1);
    vector<bool>vis(n,false);
    q.push({src,dist[src]});
    
    while(!q.empty())
    {
        Node t=q.top();
        cout<<t<<endl;
        q.pop();
        int u=t.vertex;
        
        if(vis[u])continue;
        
        for(Edge e: adj[u])
        {
            int v=e.dest;
            int w=e.wt;
            
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                prev[v]=u;
                q.push({v,dist[v]});
            }
        }
        
        vis[u]=true;
        
    }
    
    
    
    for(int i=0;i<n;i++)
    {
        vector<int>path;
        if(i!=src)
        {
            cout<<"SRC: "<<src<<" to "<<"DEST :"<<i<<" MC: "<<dist[i]<<" PATH: ";
            buildpath(path,i,prev);
            for(int i : path)
            {
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
    
}
int main()
{
    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<Edge>edges;
    while(e-- >0)
    {
        Edge g;
        cin>>g.src>>g.dest>>g.wt;
        edges.push_back(g);
    }
    Graph g(n,edges);
    adj=g.adj;
    for(int i=0;i<n;i++)
    {
        spaths(i,n);
        cout<<endl;
    }
}