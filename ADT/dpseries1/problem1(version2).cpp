#include<iostream>
#include<cstring>
using namespace std;

int time[1000];
int skill[1000];
int x,k,n;
bool taken[1000];
bool check(int level){
    int timeTaken=0;
    int itemTaken=0;
    for(int i=0;i<level;i++){
        if(taken[i]){
            timeTaken+=time[i];
            itemTaken++;
        }
    }
    timeTaken+=time[level];
    itemTaken++;
    if(timeTaken<=x && itemTaken<=k)return true;
    else return false;
}
int solve(int level){
    //returns the maximum skill i can get from the current level

    //pruning
    if(level==n)return 0;
    //base case

    //compute
    // explore all the choices either i take the item or not
    //choice 1: not take the item
    int ans=solve(level+1);
    //choice 2: take the item
    if(check(level)){
        taken[level]=1;
        ans=max( ans , (skill[level]+solve(level+1)) );
        taken[level]=0;
    }
    //return 
    return ans;
}
void getInput(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>time[i];
        cin>>skill[i];
    }
    cin>>x>>k;
    memset(taken,0,sizeof(taken));
}
int main(){
    getInput();
    cout<<solve(0);
    return 0;
}