//TC:O(n*m)
#include<iostream>
using namespace std;
int main(){
    string str,pattern;
    cin>>str>>pattern;
    
    int n=str.length(),m=pattern.length();
    for(int i=0;i<=n-m;i++){
        int j;
        for(j=0;j<m;j++){
            if(pattern[j]!=str[i+j])break;
        }
        if(m==j){
            cout<<"Pattern found at index "<<i<<endl;
        }
    }
}