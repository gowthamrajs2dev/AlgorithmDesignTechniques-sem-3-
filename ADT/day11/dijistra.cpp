#include<iostream>
#include<vector>
#include<queue>
#include<climits>
// #include<bits/stdc++.h>

using namespace std;
struct Edge{
    int src,dest,wt;
    Edge(int src,int dest,int wt){
        this->src=src;
        this->dest=dest;
        this->wt=wt;
    }
};
struct node{
    int wt,vertex;  //that particluar vertex and minimum possible distance as of now 
    node(int wt,int vertex){
        this->wt=wt;
        this->vertex=vertex;
    }
};
struct compare{
    bool operator()(const node &a,const node &b){
        return a.wt>b.wt;
    }
};
int source;
vector<vector<Edge>>adj;
vector<int>dist;
vector<int>parent;
void printEdges(){
    for(int i=0;i<(int)adj.size();i++){
        cout<<i<<"-> {";
        for(Edge e:adj[i]){
            cout<<"("<<e.dest<<","<<e.wt<<") ";
        }
        cout<<"}";
        cout<<endl;
    }
}
void printPq(priority_queue<node,vector<node>,compare>pq){
    while(!pq.empty()){
        node temp=pq.top();
        pq.pop();
        cout<<temp.vertex<<" -> "<<temp.wt<<endl;
    }
}
void getInput(){
    int n;
    cin>>n;
    adj.resize(n);
    dist.resize(n,INT_MAX);
    parent.resize(n,-1);
    vector<vector<int>>inp(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>inp[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(inp[i][j] != 0){
                adj[i].push_back({i,j,inp[i][j]});
            }
        }
    }
    cin>>source;
}
void solve(){
    dist[source]=0;
    priority_queue<node,vector<node>,compare>pq;
    pq.push({0,source});
    // printPq(pq);
    while(!pq.empty()){
        node temp=pq.top();
        pq.pop();
        for(Edge e:adj[temp.vertex]){
            if(dist[e.dest]>temp.wt+e.wt){  //e.wt->current path,temp.wt->old path
                dist[e.dest]=temp.wt+e.wt;
                pq.push({dist[e.dest],e.dest});
                parent[e.dest]=e.src;
            }
        }
    }
    cout<<"Vertex 	Distance from Source\n";
    for(int i=0;i<(int)parent.size();i++){
        cout<<i<<"			 "<<dist[i]<<endl;
    }
}
int main(){
    getInput();
    // printEdges();
    solve();
}