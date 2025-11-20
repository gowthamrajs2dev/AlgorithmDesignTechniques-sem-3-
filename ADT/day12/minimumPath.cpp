#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<int>>dp(n,vector<int>(n,0));

    dp[0][0]=arr[0][0];
    //column
    for(int i=1;i<n;i++){
        dp[0][i]=dp[0][i-1]+arr[0][i];
    }
    //row
    for(int i=1;i<n;i++){
        dp[i][0]=dp[i-1][0]+arr[i][0];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
             dp[i][j]=arr[i][j]+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"final output:"<<dp[n-1][n-1];
}