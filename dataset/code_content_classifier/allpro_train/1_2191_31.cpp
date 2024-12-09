#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define br '\n'

#define mod1 1000000007
#define mod 998244353
#define debug(x) cout << #x << " = " << x << br;



void solve()
{
	
	ll n;
	cin>>n;
	vector<ll>a(n),c(n),b(n);
	for(ll i=0;i<n;i++)
	{
		cin>>c[i];
	}
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	ll start;
	for(ll i=0;i<n;i++)
	{
		cin>>b[i];
		if(a[i]==b[i])
		{
			start=i;
		}

	}
	ll dp[n+1];
	memset(dp,0,sizeof(dp));
	ll ans=0;
	
	dp[0]=-2e9;
	for(ll i=1;i<n;i++)
	{
		dp[i]=abs(a[i]-b[i])+2;
		if(a[i]!=b[i])
		{
			dp[i]=max(dp[i],dp[i-1]+c[i-1]-1-abs(a[i]-b[i])+2);
		}
		ans=max(c[i]-1+dp[i],ans);
	}
	
	cout<<ans<<br;
	

       

}



	




	

	




int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
}

