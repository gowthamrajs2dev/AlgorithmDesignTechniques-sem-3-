#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int main(){
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);

    int n=str1.size(),m=str2.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=1;
            }
        }
    }
    int max=0,maxi;  //,maxj
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(dp[i][j]==1)
            dp[i][j]=dp[i-1][j-1]+dp[i][j];
            if(max<dp[i][j]){
                max=dp[i][j];
                maxi=i-max;
                // maxj=j-max+1;
            }
        }
    }

    //print
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<max<<endl;
    cout<<str1.substr(maxi,max);
}