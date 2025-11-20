#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<string>allPossibleResult;
void print(vector<vector<int>>maze,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }
}
void solve(vector<vector<int>>maze,vector<vector<int>>&visited,int i,int j,int n,string result){
    //returns prints all possbile ways(result) for reaching the destination from 
    //pruning:
    if(i>=n || j>=n || i<0|| j<0 || visited[i][j] || maze[i][j]==0 )return;
    
    //base case:
    if(i==n-1 && j==n-1 && maze[i][j]==1){
         
        allPossibleResult.push_back(result);
        return;
    }
    //compute 
    visited[i][j]=1;
    //up  if(condition &&!visited[i-1][j])
    solve(maze,visited,i-1,j,n,result+"U");
    //down if(condition && !visited[i+1][j])
    solve(maze,visited,i+1,j,n,result+"D");
    //keft if(condition && !visited[i][j-1])
    solve(maze,visited,i,j-1,n,result+"L");
    //right if(condition && !visited[i][j+1])
    solve(maze,visited,i,j+1,n,result+"R");

    visited[i][j]=0;
    //return
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>maze(n,vector<int>(n,0));
    vector<vector<int>>visited(n,vector<int>(n,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
        }
    }
    solve(maze,visited,0,0,n,"");
    if(allPossibleResult.size()==0){
        cout<<-1;
    }
    else{
        sort(allPossibleResult.begin(),allPossibleResult.end());
        for(string curr:allPossibleResult){
            cout<<curr<<" ";
        }
    }
}