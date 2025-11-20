#include<bits/stdc++.h>
using namespace std;
vector<int>parent;
struct Edge{
    int src,dest,wt;
};
struct compare{
    bool operator()(Edge a,Edge b){
        return a.wt<b.wt;
    }
};
int find(int a){  //master parent
    if(parent[a]==a)return a;
    return find(parent[a]);
}
void Union(int a,int b){
    parent[b]=a;
}
int main(){
    int e,v;
    cin>>e>>v;
    parent.resize(v);

    vector<Edge>edges(e);
    for(int i=0;i<e;i++){
        cin>>edges[i].src>>edges[i].dest>>edges[i].wt;
    }
    sort(edges.begin(),edges.end(),compare());

    for(int i=0;i<v;i++){
        parent[i]=i;
    }
    int actualEdges=0;
    int mc=0;
    for(int i=0;i<e && actualEdges<v-1;i++){
        if(find(edges[i].src)!=find(edges[i].dest))
        {
            Union(edges[i].src,edges[i].dest);
            actualEdges++;
            mc+=(edges[i].wt);
        }
    }
    cout<<"Minimum Cost:"<<mc<<endl;
    for(int i=0;i<v;i++){
        cout<<i<<"->"<<parent[i]<<"\n";
    }

}