//draw recursive tree for this code
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
struct Problem{
    int time,skill;
};
vector<Problem>arr;
int maxSkillGain=0;
int n;
int x,k;  //x->time ,k->slots
void getInput(){
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>(arr[i].time)>>(arr[i].skill);
    }
    cin>>x>>k;
}
void solve(int curr,int time,int slot,int skillGain){
    if(time<=0 || slot<=0 )return;
    for(int i=curr;i<n;i++){
        if(arr[i].time<=time){
            skillGain+=arr[i].skill;
            if(skillGain > maxSkillGain){
                maxSkillGain=skillGain;
            }
            solve(i+1,(time-arr[i].time),slot-1,skillGain);
            skillGain-=arr[i].skill;
        }
    }
}
int main(){
    getInput();
    solve(0,x,k,0);
    cout<<maxSkillGain;
}