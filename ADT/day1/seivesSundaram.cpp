#include<bits/stdc++.h>
using namespace std;

void seive(int n){
    int size=((n+1)/2);
    vector<bool>isPrime(size+1,true);  //1 based indexing
    for(int i=1;i<=size;i++)
    {
        for(int j=i;(i+j+2*i*j)<=size;j++){
            isPrime[i+j+2*i*j]=false;
        }
    }
    if(n>=2)cout<<"2 ";
    for(int i=1;i<=size;i++){
        if(isPrime[i]){
            cout<<2*i+1<<" ";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    // cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        seive(n);
    }
    return 0;
}