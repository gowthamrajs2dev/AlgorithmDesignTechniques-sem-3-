// learning:sort function for structures,Greedy approach (choosing the minimum among all the end times)

//simple code:
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Task{
    int st,et;
    string name;
};

struct comp{
   bool operator()(const Task &a,const Task &b){
    return a.et<b.et;  //swaps a and b when a>b(false)
   }
};
int main(){
    int n;
    cin>>n;
    vector<Task>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].name>>arr[i].st>>arr[i].et;
    }
    sort(arr.begin(),arr.end(),comp());
    // for(Task a:arr){
    //     cout<<a.name<<" "<<a.st<<" "<<a.et<<endl;
    // }
    
    int currentTime=arr[0].et;
    cout<<"Tasks that are executed in Greedy approach: \n";
    cout<<arr[0].name<<" ";
    for(int i=1;i<n;i++){
        if(currentTime<=arr[i].st)
        {
            cout<<(arr[i].name)<<" ";
            currentTime=arr[i].et;
        }

    }
}