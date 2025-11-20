#include<bits/stdc++.h>
using namespace std;

void formLpsArray(string str,vector<int>&lps){
    int i=0,j=1,n=lps.size();
    while(j<n){
        if(str[i]==str[j]){
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
int main(){
    string str;
    cin>>str;

    string rev=str;
    reverse(rev.begin(),rev.end());
    
    vector<int>lps(2*(str.size()),0);
    formLpsArray(str+rev,lps);

    for(int i=0;i<lps.size();i++){
        cout<<lps[i]<<" ";
    }cout<<endl;

    str=rev.substr(0,str.size()-lps.back())+str;

    cout<<str;
}