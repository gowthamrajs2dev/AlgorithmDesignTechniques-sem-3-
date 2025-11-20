#include<iostream>
#include<cmath>
#include<climits>
#include<vector>
using namespace std;
void build(vector<int>&seg,vector<int>arr,int i,int start,int end){
    if(start==end){
        seg[i]=arr[start];
        return;
    }
    int mid=(start+end)/2;
    build(seg,arr,2*i+1,start,mid);
    build(seg,arr,2*i+2,mid+1,end);
    seg[i]=min(seg[2*i+1],seg[2*i+2]);
}
int query(vector<int>seg,int i,int start,int end,int left,int right){
    //no-lies
    if(start>right || end<left)return INT_MAX;
    //lies
    if(start>=left && end<=right)return seg[i];
    //overlapping
    int mid=(start+end)/2;
    int r=query(seg,2*i+2,mid+1,end,left,right);
    int l=query(seg,2*i+1,start,mid,left,right);
    return min(r,l);
}
void update(vector<int>&seg,int i,int start,int end,int pos,int val){
    if(start==end){
        seg[i]=val;
        return;
    }
    int mid=(start+end)/2;
    if(mid>=pos){
        //left
        update(seg,2*i+1,start,mid,pos,val);
    }
    else{
        update(seg,2*i+2,mid+1,end,pos,val);
    }
    seg[i]=min(seg[2*i+1],seg[2*i+2]);
    
}
int main(){
    int n,q;
    cin>>n>>q;
    
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int layers=int(log2(n))+2;
    vector<int>seg( (int)pow( 2,(layers) )-1,-1 );
    build(seg,arr,0,0,n-1);
    // for(int i=0;i<(int)seg.size();i++){
    //     cout<<seg[i]<<" ";
    // }
    // cout<<endl;
    while(q--){
        char ch;
        cin>>ch;
        if(ch=='Q'){
            int left,right;
            cin>>left>>right;
            cout<<query(seg,0,0,n-1,left,right)<<endl;
        }
        else if ( ch == 'U'){
            int pos,val;
            cin>>pos>>val;
            update(seg,0,0,n-1,pos,val);
        }
    }
}