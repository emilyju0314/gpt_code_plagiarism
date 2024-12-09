#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5005;
ll a[N],dp[N][N];
inline void cmn(ll&a,ll b){if(a>b)a=b;}
int main()
{
	ll n,A,B,ans=1ll<<60;scanf("%lld%lld%lld",&n,&A,&B);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	memset(dp,0x3f,sizeof(dp));dp[0][0]=0;
	for(int i=1;i<=n;i++)for(int j=0;j<=n;j++)if(a[i]>j)cmn(dp[i][j],dp[i-1][j]+A),cmn(dp[i][a[i]],dp[i-1][j]);else cmn(dp[i][j],dp[i-1][j]+B);
	for(int i=0;i<=n;i++)cmn(ans,dp[n][i]);
	printf("%lld\n",ans);
	return 0;
}