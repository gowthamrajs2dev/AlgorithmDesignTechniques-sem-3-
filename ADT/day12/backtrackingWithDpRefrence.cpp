//exploring all possible ways with backtracking in dp(tabulated Value):

#include<bits/stdc++.h>
using namespace std;
vector<string>res;
string s1,s2;

void poss(vector<vector<int>>dp,int i,int j,int length, string curr)
{
    if(length==0)
    {
        res.push_back(curr);
        return;
    }
    if(s1[i-1]==s2[j-1])
    {
        curr= s1[i-1]+curr;
        poss(dp,i-1,j-1,length-1,curr);
    }
    else if(dp[i-1][j]==dp[i][j-1])
    {
        poss(dp,i-1,j,length,curr);
        poss(dp,i,j-1,length,curr);
    }
    else if(dp[i-1][j]>dp[i][j-1])
    {
        poss(dp,i-1,j,length,curr);
    }
    else
    {
        poss(dp,i,j-1,length,curr);
    }
}
int main()
{
    getline(cin,s1);
    getline(cin,s2);
    
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    poss(dp,n,m,dp[n][m],"");
    
    for(string s: res)
    {
        cout<<s<<endl;
    }
    return 0;
}