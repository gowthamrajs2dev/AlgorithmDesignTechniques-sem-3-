//probablity of knight staying the board after k moves in n*n board starting from row, col
#include<iostream>
#include<vector>
#include<queue>
#include<iomanip>
using namespace std;
int n,k,row,col;
struct Coordinate{
    int x,y; 
};
bool isValid(int i,int j){
    if(i>=0 && i<n && j>=0 && j<n)return true;
    return false;
}
double solve(){
    int count=0;
    double prob=1,moves=0,validMoves=0;
    vector<Coordinate>children;
    queue<Coordinate>q;
    q.push({row,col});
    
    while(!q.empty()){
        if(count==k){
            return prob;
        }
        Coordinate temp=q.front();
        q.pop();
        
        int x=temp.x,y=temp.y;
        moves+=8;
        if(isValid(x+1,y+2)){
            validMoves++;
            children.push_back({x+1,y+2});
        }
        if(isValid(x-1,y+2)){
            validMoves++;
            children.push_back({x-1,y+2});
        }
        if(isValid(x+1,y-2)){
            children.push_back({x+1,y-2});
            validMoves++;
        }
        if(isValid(x-1,y-2)){
            children.push_back({x-1,y-2});
            validMoves++;
        }
        
        
        if(isValid(x+2,y+1)){
            children.push_back({x+2,y+1});
            validMoves++;
        }
        if(isValid(x-2,y+1)){
            children.push_back({x-2,y+1});
            validMoves++;
        }
        if(isValid(x+2,y-1)){
            children.push_back({x+2,y-1});
            validMoves++;
        }
        if(isValid(x-2,y-1)){
            children.push_back({x-2,y-1});
            validMoves++;
        }
        // cout<<validMoves<<" ";
        // cout<<prob<<"->";
        if(q.empty() && children.size()!=0){
            for(int i=0;i<children.size();i++){
                q.push(children[i]);
            }
            children.clear();
            count++;
            double currentProb=validMoves/moves;
            prob=currentProb*prob;
            
            validMoves=0;
            moves=0;
        }
    }
    
    cout<<"Unexpected!";
    return -1;
}
int main(){
    cin>>n>>k>>row>>col;
    cout<<fixed<<setprecision(5)<<solve();
    // solve();
}