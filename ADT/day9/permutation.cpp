#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
vector<string>allPermutations;
unordered_set<string>st;
void solve(string &str,int n){
    //finds all possible permutation of a word 
    //n->all possible swap of the index with the greater index
    //base case
    if(n==str.size()){
        st.insert(str);
        return;
    }
    for(int i=n;i<str.size();i++){
        swap(str[i],str[n]);
        solve(str,n+1);
        swap(str[i],str[n]); // backtrack
    }
    
}
void printResult(){
    allPermutations.assign(st.begin(),st.end());
    sort(allPermutations.begin(),allPermutations.end());
    for(int i=0;i<allPermutations.size();i++){
        cout<<allPermutations[i]<<"\n";
    }
}
int main(){
    string str;
    cin>>str;
    solve(str,0);
    printResult();
}