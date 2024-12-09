#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;


const int maxn = 16;
int a[maxn][maxn],dp[1LL<<maxn];
int n;
int32_t main()
{
	IOS
	memset(dp,0,sizeof(dp));
	cin>>n;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	cin>>a[i][j];
	
	
	for(int i=0;i<(1LL<<n);i++)
	{
		int msk = i;
		for(int j=0;j<n;j++)
		for(int k=0;k<n;k++)
		if( ((msk>>j)&1)   &&  ((msk>>k)&1) )
		{
			dp[msk]+=a[j][k];
		}
	}
	
	for(int i=0;i<(1LL<<n);i++)
	{
		
		for(int j=i;j;j=(j-1)&i)
		{
			int msk1 = j;
			int msk2 = i^j;
			
			dp[i]=max(dp[i],dp[msk1]+dp[msk2]);
		}
	}
	
	cout << (dp[(1LL<<n)-1]>>1) << endl;
	
	
}
