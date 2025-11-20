#include<iostream>
#include<vector>
using namespace std;
vector<int>arr;
vector<int>heap;
int hs=0;

void heapifyDown(int curr){
    int small=curr;
    int left=2*curr+1;
    int right=2*curr+2;
    
    if(left<hs && heap[left]<heap[small]){
        small=left;
    }
    if(right<hs && heap[right]<heap[small]){
        small=right;
    }
    if(small!=curr){
        swap(heap[small],heap[curr]);
        heapifyDown(small);
    }
}
void heapifyUp(int curr){  //place the value in curr in correct position of heap tree
    int parent=(curr-1)/2;
    //base case:
    if(curr==0 || heap[parent]<heap[curr])return ;
    //compute:
    swap(heap[parent],heap[curr]);
    heapifyUp(parent);
}
void insert(int val){
    hs++;
    heap.push_back(val);
    heapifyUp(hs-1);
    
}
void print(){
    for(int i=0;i<hs;i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}
void build(){
    for(int i=(hs/2)-1;i>=0;i--){
        heapifyDown(i);
    }
}
int main()
{
    int n;
    cin>>n;
    
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        insert(arr[i]);
    }
    
    //removing elements in heap <= root*2  using two-pointer approach;
    
    int j=0;
    int root=heap[0];
    for(int i=0;i<hs;i++){
        if(heap[i]>=root*2){
            heap[j]=heap[i];
            j++;
        }
    }
    hs=j;
    heap.resize(hs);  
    
    build();
    print();
}