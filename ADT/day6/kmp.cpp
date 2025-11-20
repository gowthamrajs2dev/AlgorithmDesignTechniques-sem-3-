#include<iostream>
#include<vector>
using namespace std;
void formLps(string pat,int m,vector<int>&lps){
    for(int j=1,i=0;j<m;){
        // cout<<pat[i]<<" == "<<pat[j]<<"\n";
        if(pat[i]==pat[j]){
            i++;
            lps[j]=i;
            j++;
        }
        else{
            if(i==0){
                j++;
            }
            else{
                i=lps[i-1];
            }
        }
    }
}
void kmpAlgo(string txt,string pat){
    int n=txt.size(),m=pat.size();
    vector<int>lps(m,0);
    
    formLps(pat,m,lps);
    // for(int i=0;i<m;i++){
    //     cout<<lps[i]<<" ";
    // }
    
    for(int i=0,j=0;i<n;){
        while(j<m && i<n && pat[j]==txt[i]){
            j++;
            i++;
        }
        if(j==m){
            cout<<"Found pattern at index "<<i-j<<endl;
        }
        if(j==0){
            i++;
        }
        else{
            j=lps[j-1];
        }
    }
}
int main(){
    string txt,pat;
    getline(cin,txt);
    getline(cin,pat);
    
    kmpAlgo(txt,pat);
}