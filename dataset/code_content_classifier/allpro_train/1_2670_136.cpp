#include<bits/stdc++.h>
using namespace std;
#define maxn 405
#define ll long long
#define p 1000000007
ll sum[maxn][maxn],f[maxn][maxn];
int n,m,a[maxn],b[maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
		scanf("%d",&b[i]);
	for(int i=1;i<=400;++i)
	{
		sum[i][0]=1;
		for(int j=1;j<=400;++j)
			sum[i][j]=1ll*sum[i][j-1]*i%p;
	}
	for(int i=1;i<=400;++i)
		for(int j=0;j<=400;++j)
			sum[i][j]+=sum[i-1][j],sum[i][j]%=p;
	f[0][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=m;++j)
			for(int k=0;k<=j;++k)
			{
				f[i][j]+=0ll+1ll*f[i-1][j-k]*(sum[b[i]][k]-sum[a[i]-1][k])%p;
				f[i][j]%=p;
			}
	printf("%lld\n",(f[n][m]%p+p)%p);
	return 0;
}