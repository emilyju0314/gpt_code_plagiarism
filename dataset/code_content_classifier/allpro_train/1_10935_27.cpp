#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#include<map>
#include<set>
#include<cstdlib>
#include<bitset>
using namespace std;
#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long long ll;
ll n,mod=1e9+7;
ll a[100005];
ll fac[100005]={0};
ll qpow(ll a,ll b)
{
	if(b==0) return 1;
	ll c=qpow(a,b/2);
	if(b%2==0) return c*c%mod;
	else return c*c%mod*a%mod;
}
int main(void)
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	fac[0]=1;
	for(ll i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	ll ans=0;
	map<ll,ll> mp;
	for(ll i=1;i<=n;i++) ans+=a[i],mp[a[i]]++;
	if(ans%n!=0)
	{
		printf("0");
		return 0;
	}
	ll ok=ans/n;
	ans=1;
	ll cn1=0,cn2=0;
	for(ll i=1;i<=n;i++)
	{
		if(a[i]<ok) cn1++;
		if(a[i]>ok) cn2++;
	}
	if(cn1<=1||cn2<=1)
	{
		for(auto x:mp)
		{
			ans=ans*fac[x.second]%mod;
		}
		ans=fac[n]*qpow(ans,mod-2)%mod;
	}
	else
	{
		ans=2*fac[cn1]%mod*fac[cn2]%mod;
		ans=ans*fac[n]%mod*qpow(fac[cn1+cn2]*fac[n-cn1-cn2]%mod,mod-2)%mod;
		for(auto x:mp)
		{
			if(x.first!=ok)
			{
				ans=ans*qpow(fac[x.second],mod-2)%mod;
			}
		}
	}
	cout<<ans;
}