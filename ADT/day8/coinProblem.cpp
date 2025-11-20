
#include<iostream>
#include<vector>
using namespace std;
void print(vector<int>arr){
    if(arr.size()==0)cout<<"Empty";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void solve(int n,int start,vector<int>&temp){ 
    //start tells to write possiblities above the start
//prints all possbile combinations(order no matter) of coins whose sum is n
   if(n==0){
      print(temp);
      return;
    vector<int>result;
   }
   for(int i=start;i<=n;i++){
      temp.push_back(i);
      solve(n-i,i,temp);
      temp.pop_back(); //backtracking(undoing the changes)
   }
}
int main(){
    int n;
    cin>>n;
    vector<int>temp;

    solve(n,1,temp);
}   