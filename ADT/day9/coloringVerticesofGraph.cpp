#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>graph;
vector<int>allColours;
int n,maxColors;
bool isSafe(int currVertex,int colour){
    for(int i=0;i<currVertex;i++){
        //itrate through the neighbours
        if(graph[currVertex][i]==1){
            if(allColours[i]==colour)return false;
        }
    }
    return true;
}
bool solve(int currVertex){  
    //returns is it possible to form adjacent different colors 
    //with only minColors
    //base case:
    if(currVertex==n)
    {  //which means all colors are filled for every vertex
        return true;
    }
    //compute all choices
    for(int colour=1;colour<=maxColors;colour++){
        if(isSafe(currVertex,colour)){
            allColours.push_back(colour);  //allColours[currVertex]=color;
            if(solve(currVertex+1)){
                return true;
            }  
            //not possible to color all vertex using m colors
            allColours.pop_back();  //backtrack
        }
    }
    //return
    return false;
}


void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}


void getInput(){
    cin>>n;
    graph.resize(n);
    for(int i=0;i<n;i++){
        graph[i].resize(n);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }
    cin>>maxColors;
}


int main(){
    getInput();
    if(solve(0)){
        for(int i=0;i<allColours.size();i++){
            cout<<allColours[i]<<" ";
        }
    }
    else{
         cout<<"Solution does not exist";
    }
    return 0;
}