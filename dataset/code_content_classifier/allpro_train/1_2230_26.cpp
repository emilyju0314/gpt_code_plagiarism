
//Totka hai dosto
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int mod=998244353;
const int N=2e5+9;
int f1[N];
int f2[N];
ll modp(ll a, ll b)
{
	if(b==0)return 1;
	ll u=modp(a,b/2);
	u=(u*u)%mod;
	if(b&1)
	return (a*u)%mod;
	return u;
}
int ncr(int n, int r)
{
	if(n<r)return 0;
	int res=(f1[n]*f2[n-r])%mod;
	res=(f2[r]*res)%mod;
	return res;
}
int32_t main()
{
	f1[0]=1;f2[0]=modp(f1[0],mod-2);
	for(int i=1;i<=200000;i++)
	{
		f1[i]=(f1[i-1]*i)%mod;
		f2[i]=modp(f1[i],mod-2);
	}
	
	int ans=0,tmp=0;
	
	int n,m,k;
	cin>>n>>m>>k;
	
	for(int i=0;i<=k;i++)
	{
		tmp=0;
		tmp=ncr(n-1,i)*m;
		tmp%=mod;
		tmp=(tmp*modp(m-1, n-1-i));
		tmp%=mod;
		ans+=tmp;ans%=mod;
	}
	
	cout<<ans;
	
}