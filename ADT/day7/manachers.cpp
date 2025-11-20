//longest palindromic substring 
//tc: O(n)
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s,str;
    cin>>s;
    
    for(int i=0;i<s.size();i++){
        str+='#';
        str+=s[i];
    }
    str+='#';
    int n=str.size();
    vector<int>p(n,0);
    int mc=0,ml=0,r=0,c=0;  //maximum length of palindrome and it's index
    for(int i=1;i<n;i++){
        if(i<r){
            int mirror=2*c-1;
            p[i]=min(r-i,p[mirror]);
        }
        while(i+p[i]+1<n && i-p[i]-1>=0 && str[i+p[i]+1] == str[i-p[i]-1]){
            p[i]++;
        }

        if(r<p[i]+i){
            c=i;
            r=p[i]+i;
        }
        if(ml<p[i]){
            ml=p[i];
            mc=i;
        }
    }

    cout<<s.substr((mc-ml)/2,ml);
    return 0;
}