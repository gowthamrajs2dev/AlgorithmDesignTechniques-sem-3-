#include<bits/stdc++.h>
using namespace std;
int main(){
    string txt,pat;
    cin>>txt>>pat;
    int n=txt.size(),m=pat.size();
    int base=256,mod=101;  //(base=10,mod=13)
    int high=(int)pow(base,m-1)%mod;
    int th=0,ph=0;
    for(int i=0;i<m;i++){
        th=(th*base+txt[i])%mod;
        ph=(ph*base+pat[i])%mod;
    }
    // cout<<"ph("<<pat<<")->"<<ph<<" "<<endl;
    // cout<<"th("<<txt.substr(0,m)<<")->"<<th<<endl;
    for(int i=0;i<=n-m;i++){
        // cout<<"th("<<txt.substr(i,m)<<")->"<<th<<endl;
        if(ph==th){
            //sliding window
            bool match=true;
            for(int j=0;j<m;j++){
                if(txt[i+j]!=pat[j]){
                    match=false;
                    break;
                }
            }
            if(match){
                cout<<i<<" ";
            }
        }

        if(i<n-m){
            th=(th-txt[i]*high)%mod;
            if(th<0){
                th+=mod;
            }
            th=(th*base+txt[i+m])%mod;
        }
    }
}