#include<bits/stdc++.h>
#include<climits>
using namespace std;
int n=4;
vector<vector<int>>adj(n,vector<int>(n,INT_MAX));
void getInput(){
    int e;
    cin>>e;
    for(int i=0;i<e;i++){
       int src,dest,wt;
       cin>>src>>dest>>wt;  
       adj[src][dest]=wt;    //for directed graph
    }
    for(int i=0;i<n;i++){
        adj[i][i]=0;  //no self loop
    }
}
void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}
void solve() {
   getInput();
   for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[k][j]==INT_MAX || adj[i][k]==INT_MAX )continue;
            adj[i][j]=min( (adj[k][j]+adj[i][k]) ,adj[i][j] );
        }
    }
   }
   print();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    // cin>>t;
    for(int i=0;i<t;i++){
        solve();
    }
    return 0;
}