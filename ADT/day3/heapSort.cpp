#include<iostream>
#include<vector>
using namespace std;

void heapifyDown(vector<int>&arr,int curr,int n){
    int big=curr;
    int left=2*curr+1;
    int right=2*curr+2;

    if(left<n && arr[left]>arr[big]){
        big=left;
    }
    if(right<n && arr[right]>arr[big]){
        big=right;
    }
    if(big!=curr){
        swap(arr[big],arr[curr]);
        heapifyDown(arr,big,n);
    }
}

void buildMaxHeap(vector<int>&arr,int n){
    for(int i=(n/2)-1;i>=0;i--){
        heapifyDown(arr,i,n);
    }
}
void maxHeapSort(vector<int>&arr,int n){
    for(int i=n-1;i>=0;i--){
        swap(arr[i],arr[0]);
        heapifyDown(arr,0,i);
    }
    
}
void print(vector<int>arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    buildMaxHeap(arr,n);
    maxHeapSort(arr,n);
    print(arr,n);
    
}