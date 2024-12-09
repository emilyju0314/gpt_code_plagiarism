#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353LL

ll fac[10000010],ifac[10000010];
int n,a,b;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline ll pls(const ll &x,const ll &y) { return (x+y<mod)?x+y:x+y-mod; }
inline ll mns(const ll &x,const ll &y) { return (x-y<0)?x-y+mod:x-y; }
inline ll ksm(ll x,ll y) { ll res=1;for (;y;y>>=1,x=x*x%mod) if (y&1) res=res*x%mod;return res; }
inline ll C(const int &x,const int &y) { return (x<0||y<0||x<y)?0:fac[x]*ifac[y]%mod*ifac[x-y]%mod; }

inline void pre_gao()
{
	fac[0]=1;
	for (int i=1;i<=10000000;i++) fac[i]=fac[i-1]*i%mod;
	ifac[10000000]=ksm(fac[10000000],mod-2);
	for (int i=9999999;~i;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
}

inline ll calc(int n,int m)
{
	return mns(C(n-1+m,m),C(n-1+m,m-1));
}

inline ll gao(int n,int m) { return (!n)?0:C(m+n-1,n-1); }

int main()
{
	n=rd();a=rd();b=rd();pre_gao();
	if (b==0) { puts("1");return 0; }
	ll ans=0;
	if (a+b==n) ans=calc(b,a);
	for (int k=0;k<=a;k++)
	{
		int hh=n-b-k;
		if (hh<=0) break;
		ans=pls(ans,calc(b,k)*mns(gao(a-k+1,hh),gao(a-k,hh))%mod);
	}
	printf("%lld\n",ans);
	return 0;
}