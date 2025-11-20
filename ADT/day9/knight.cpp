#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
int targetRow,targetCol;
int ways=0;
struct Cordinate{
    int x,y;
    Cordinate(int x,int y){
        this->x=x;
        this->y=y;
    }
};
bool isValid(int x,int y){
    // if(x>=0 && y>=0 && y<8 && x<8)return true;
    //every move is valid;
    return true;
}
void solve(){
    queue<Cordinate>q;
    q.push({0,0});
    while(!q.empty()){
        Cordinate temp=q.front();
        q.pop();
        int x=temp.x,y=temp.y;
        if(x==targetRow && y==targetCol)return;
        ways+=8;
        if(isValid(x+1,y+2)){
            q.push({x+1,y+2});
        }
        if(isValid(x-1,y+2)){
            q.push({x-1,y+2});
        }
        if(isValid(x+1,y-2)){
            q.push({x+1,y-2});
        }
        if(isValid(x-1,y-2)){
            q.push({x-1,y-2});
        }
        
        if(isValid(x+2,y+1)){
            q.push({x+2,y+1});
        }
        if(isValid(x-2,y+1)){
            q.push({x-2,y+1});
        }
        if(isValid(x+2,y-1)){
            q.push({x+2,y-1});
        }
        if(isValid(x-2,y-1)){
            q.push({x-2,y-1});
        }
    }
}
int main(){
    cin>>targetRow>>targetCol;
    if((targetRow==0 && targetCol==0) || !isValid(targetRow,targetCol)){
        cout<<0;
        return 0;
    }
    solve();
    int moves=log(ways)/log(8);
    cout<<moves;
}