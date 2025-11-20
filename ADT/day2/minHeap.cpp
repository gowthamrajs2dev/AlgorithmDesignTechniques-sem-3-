// root element in the heap is either 
// maximum(max-heap) or minimum(minimum-heap) 
// time complexcity:  deletion(log2(n)), insertion(log2(n)),findingMaxOrMin(O(1))
// applications: prority queue,shortest path finding 

// formation:from a array like a tree(level order reversal,left to right)


//minimum heap
#include<iostream>
#include<vector>
using namespace std;
void heapfyDown(vector<int> &arr,int i,int n){
    //always maintain the root node value as minimum
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && arr[left]<arr[smallest]){
        smallest=left;
    }
    if(right<n && arr[right]<arr[smallest]){
        smallest=right;
    }
    if(i!=smallest){
       swap(arr[smallest],arr[i]);
       heapfyDown(arr,smallest,n);
    }
}
void heapfyUp(vector<int> &arr,int i,int n){
    if(arr[i]>arr[(i-1)/2]  || i==0){
        return;
    }
    swap(arr[i],arr[(i-1)/2]);
    heapfyUp(arr,(i-1)/2,n);
}
void insert(vector<int> &arr,int element,int &n){
    arr.push_back(element);
    n++;
    heapfyUp(arr,n-1,n);
}
void del(vector<int>&arr,int &n){
   int min=arr[0];
   swap(arr[0],arr[n-1]);
   arr.pop_back();
   n--;
   heapfyDown(arr,0,n);  //tricky part
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    

    for(int i=(n/2)-1;i>=0;i--){
        heapfyDown(arr,i,n);
    }

    
    int newElement;
    cin>>newElement;
    insert(arr,newElement,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}