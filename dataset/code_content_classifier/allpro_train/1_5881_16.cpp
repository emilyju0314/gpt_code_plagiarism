#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
#define MOD 1000000007 // prime
const int SIZE = 100100;
ll inv[SIZE+10],fac[SIZE+10],facinv[SIZE+10];
ll Pow[1010],kai[210];
ll val[210];
ll nCr(int n,int r)
{
	if(n<r)return -1;
	if(n<0||r<0)return -1;
	return ((fac[n]*facinv[r]%MOD)*facinv[n-r])%MOD;
}
ll func(int n)
{
	ll ret = 0ll;
	for(int i=0;i<=n;i++)ret = (ret+(nCr(n,i)*kai[i])%MOD)%MOD;
	return ret;
}
void init()
{
	fac[0]=1ll;
	for(int i=1;i<=SIZE;i++)fac[i]=(fac[i-1]*i)%MOD;
	inv[1]=1ll;
	for(int i=2;i<=SIZE;i++)inv[i]=((-(MOD/i)*inv[MOD%i])%MOD+MOD)%MOD;
	facinv[0]=1ll;
	for(int i=1;i<=SIZE;i++)facinv[i]=(facinv[i-1]*inv[i])%MOD;
	Pow[0]=1ll;
	for(int i=0;i<1000;i++)Pow[i+1]=(Pow[i]*10ll)%MOD;
	kai[0]=1ll;
	for(int i=1;i<=200;i++)kai[i]=(kai[i-1]*i)%MOD;
	for(int i=0;i<=200;i++)val[i]=func(i);
}
int cnt_digit(ll x)
{
	if(x==0ll)return 1;
	int ret = 0;
	while(x){ret++;x/=10ll;}
	return ret;
}
ll dp[210][1010];
int n;
ll a[210];
int dig[210];
ll digit_sum[5];
int del[5];
int zero=-1;
int N;
void culc_dp(int unuse)
{
	memset(dp,0,sizeof(dp));
	dp[0][0]=1ll;
	for(int i=0;i<N;i++)
	{
		if(i==unuse)continue;
		for(int j=i;j>=0;j--)
		{
			for(int k=0;k<=j*4;k++)
			{
				if(dp[j][k]==0)continue;
				dp[j+1][k+dig[i]]+=dp[j][k];
				dp[j+1][k+dig[i]]%=MOD;
			}
		}
	}
}
ll solve()
{
	ll ans = 0ll;
	for(int d=1;d<=4;d++)
	{
		if(del[d]==-1)continue;
		culc_dp(del[d]);
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<=4*N;j++)
			{
				if(dp[i][j]==0)continue;
				ans += (((((((val[N-i-1]*kai[i])%MOD)*digit_sum[d])%MOD)*dp[i][j])%MOD)*Pow[j])%MOD;
				ans %= MOD;
			}
		}
	}
	return ans;
}

int main()
{
	init();
	memset(del,-1,sizeof(del));
	scanf("%d",&n);
	N=n;
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	for(int i=0;i<n;i++)
	{
		dig[i]=cnt_digit(a[i]);
		digit_sum[dig[i]]+=a[i];
		del[dig[i]]=i;
		if(a[i]==0)zero=i;
	}
	ll ans = solve();
	//cout << solve() << ' ';
	if(zero!=-1)
	{
		swap(a[zero],a[n-1]);
		N--;
		memset(del,-1,sizeof(del));
		memset(digit_sum,0,sizeof(digit_sum));
		for(int i=0;i<N;i++)
		{
			dig[i]=cnt_digit(a[i]);
			digit_sum[dig[i]]+=a[i];
			del[dig[i]]=i;
		}
		ans -= solve();
		//cout << solve() << endl;
		ans = ((ans%MOD)+MOD)%MOD;
	}
	printf("%lld\n",ans);
	return 0;
}