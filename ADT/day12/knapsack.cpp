//0/1 knap-sack
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>wt(n,0);
    vector<int>val(n,0);
    
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    
    int target;
    cin>>target;
    
    vector<vector<int>>dp(n+1,vector<int>(target+1,0));
    
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=target;j++)
        {
            if(j>=wt[i-1])
            {
                dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][target];
    return 0;
}