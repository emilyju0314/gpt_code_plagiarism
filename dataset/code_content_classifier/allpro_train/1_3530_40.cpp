# include <cstdio>
# include <iostream>
# include <queue>
# include <cstring>
# include <string>
# define mod 1000000007
# define R register int
# define ll long long

using namespace std;

const int maxn=100100;
int n,m,fac=1,h;
int p[maxn],c[maxn];
ll f[maxn],inv[maxn];
ll ans=1;

ll qui (ll a,ll b)
{
	ll s=1;
	while (b)
	{
		if(b&1LL) s=s*a%mod;
		a=a*a%mod;
		b=b>>1LL;
	}
	return s%mod;
}

ll C (int a,int b)
{
	return f[b]*qui(f[a],mod-2)%mod*qui(f[b-a],mod-2)%mod;
}

int main()
{
	scanf("%d%d",&n,&m);
	f[0]=1;
	for (R i=1;i<=n+50;++i)
		f[i]=1LL*i*f[i-1]%mod;
	for (R i=2;1LL*i*i<=m;++i)
	{
		if(m%i==0) p[++h]=i;
		while (m%i==0) c[h]++,m/=i;
	}
	if(m!=1) p[++h]=m,c[h]=1;
	for (R i=1;i<=h;++i)
		ans=(ans*C(n-1,n+c[i]-1))%mod;
	printf("%lld",ans%mod);
	return 0;
}