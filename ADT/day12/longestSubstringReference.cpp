#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int m=s1.size();
    int n=s2.size();
    vector<vector<int>>dp(m+1,vector<int>(n+1));
    int sr=0,sc=0;
    int maxi=INT_MIN;
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                if(maxi<dp[i][j])
                {
                    maxi=dp[i][j];
                    sr=i;
                    sc=j;
                }
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }
  string res="";
    
    while(dp[sr][sc]!=0)
    {
        res= s1[sr-1]+res;
        sr--;
        sc--;
    }
    cout<<maxi<< " "<< res;
    return 0;
}