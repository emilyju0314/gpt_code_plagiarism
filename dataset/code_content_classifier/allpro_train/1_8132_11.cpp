#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
  int N;
  cin >> N;
  while(N-- > 0)
    {
      int n;
      cin >> n;
      int dp[n][n];
      vector<int> vec(n);
      for(int i=0;i<n;i++)
	{
	  cin >> vec[i];
	  for(int j=0;j<n;j++)
	    dp[i][j] = 0;
	}

      int mex = 0;
      for(int i=0;i<n;i++)
	dp[i][(i+1)%n] = abs(vec[i]-vec[(i+1)%n]),mex = max(mex,dp[i][(i+1)%n]);

      for(int i=2;i<n;i++)//幅
	{
	  for(int j=0;j<n;j++)//index
	    {
	      for(int k=j;k<=j+i-1;k++)//中間地点
		{
		  if(k == j)
		    {
		      dp[j][(j+i)%n] = max(dp[j][(j+i)%n],dp[j][(j+i-1)%n]+abs(vec[j]-vec[(j+i)%n]));
		      mex = max(mex,dp[j][(j+i)%n]);
		      continue;
		    }
		  dp[j][(j+i)%n] = max(dp[j][(j+i)%n],
				       dp[k%n][(j+i)%n]+dp[j][k%n]);
		}
	      mex = max(mex,dp[j][(j+i)%n]);
	    }
	}

      cout << mex << endl;


    }
  return 0;
}