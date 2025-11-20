//[1,2,10,20,50,100,2000]
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>selected;
    int arr[]={2000,100,50,20,10,2,1};
    int amount;
    cin>>amount;
    for(int curr:arr){
        while(curr<=amount){
            amount-=curr;
            selected.push_back(curr);
        }
        if(amount==0){
            break;
        }
    }
    cout<<"Selected coins: ";
    for(int i : selected){
        cout<<i<<" ";
    }
    cout<<"\nNumber coins selected: "<<selected.size();
}