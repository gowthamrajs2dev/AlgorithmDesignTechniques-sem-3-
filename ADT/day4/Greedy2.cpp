//Fractional knapSack(we can divide the product) && 0/1 knapSack (we cannot divide the product)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Product{
    double weight;
    double value;
    double index;
    Product(int weight,int value,int index){
        this->weight=weight;  //this always points the address
        this->value=value;
        this->index=index;
    }
};
struct compare{
    bool operator()(Product &a,Product &b){
        double r1=a.value/a.weight;
        double r2=b.value/b.weight;
        return r1>r2;
    }
};
int main(){
    int n,cap;
    cin>>n>>cap;
    vector<Product>arr;
    for(int i=1;i<=n;i++){
        int weight,value,index;
        cin>>weight>>value;
        arr.push_back({weight,value,index});
    }
    
    sort(arr.begin(),arr.end(),compare());
   
   
    int maxProfit=0;
    for(Product curr:arr){
        if(cap==0)break;
        if(cap>=curr.weight){
            maxProfit+=curr.value;
            cap-=curr.weight;
        }
        else{
            maxProfit+=((curr.value/curr.weight)*cap);
            cap=0;
        }

    }
    cout<<"Maximum Profit(val) that can be acheived: "<<maxProfit;
    // for(int i=0;i<n;i++){
    //     cout<<arr[i].weight<<" "<<arr[i].value<<"\n";
    // }
}