//optimised n-queen problem SC:O(n) TC:O(N!) we cannot reduce tc further

#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int>board;

bool isSafe(int row,int col){
    //diagonal->abs(board[i]-col)==abs(i-row)
    for(int i=0;i<n;i++){
        if(board[i]==-1)continue;
        //row check is done in solve function itself
        //column check
        if(board[i]==col)return false;
        //diagonal check
        if(abs(board[i]-col)==abs(i-row))return false;
    }
    return true;
}
int solve(int row){
    //returns all possible ways of placing queens safely from row
    //base case:
    if(row==n){  //if n queens are placed already till n-1th row
        return 1;  //it's one possible/valid way
    }
    if(board[row]!=-1)return 0;  //row check
    //compute(choices)
    int ways=0;
    for(int col=0;col<n;col++){
        if(isSafe(row,col)){
            board[row]=col;
            ways+=solve(row+1); //next row
            board[row]=-1;  //backtrack
        }
    }
    //return
    return ways;
}
int main(){
    cin>>n;
    board.resize(n,-1);  //board[row]=queen's column index
    cout<<solve(0);
}