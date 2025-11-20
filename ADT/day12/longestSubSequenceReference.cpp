#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1;
	string s2;
	getline(cin,s1);
	getline(cin,s2);
	int n=s1.size();
	int m=s2.size();
	vector<vector<int>>dp(n+1,vector<int>(m+1,0));

	for(int i=0; i<=n; i++)
	{
		for(int j=0; j<=m; j++)
		{
			if(i==0 ||j==0)
			{
				dp[i][j]=0;
			}
			else if(s1[i-1]==s2[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;

			}
			else
			{
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}

	cout<<dp[m][n]<<endl;;
	int i=m;
	int j=n;
	string lcs="";
	while(i>0 && j>0)
	{
		if(s1[i-1]==s2[j-1])
		{
			lcs= s1[i-1] +lcs;
			i--;
			j--;
		}
		else if(dp[i-1][j]>dp[i][j-1])
		{
			i--;
		}
		else
		{
			j--;
		}
	}
	cout<<lcs;
	return 0;
}