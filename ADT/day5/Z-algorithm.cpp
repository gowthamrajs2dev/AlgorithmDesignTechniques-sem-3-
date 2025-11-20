#include<iostream>
#include<vector>
using namespace std;
int main(){
    string str,pat,s;
    cin>>str>>pat;
    s=pat+"$"+str;
    int n=s.size(),m=pat.size();
    
    vector<int>z(n,0);
    int r=0,l=0;
    for(int i=1;i<n;i++){
        if(i<=r){
            z[i]=min(z[i-l],r-i+1);  //r is inclusive so +1 

        }
        while(z[i]+i<n && s[z[i]+i]==s[z[i]] ){
            z[i]++;
        }
        if(r<z[i]+i-1){
            r=z[i]+i-1;
            l=i;
        }
    }
    for(int i=m+1;i<n;i++){
        if(z[i]==m)cout<<i-m-1<<" ";
    }
}