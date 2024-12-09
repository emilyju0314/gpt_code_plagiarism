#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define fi first
#define se second

int n,k,q;
int const N=5e3+3;
ll a[N];
ll dp[N][N];
ll cnt[N];
ll mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k>>q;
    F0R(i,n)
    {
		cin>>a[i];
	}
	F0R(i,n)
	{
		dp[i][0] = 1;
	}
	FOR(j,1,k+1)
	{
		F0R(i,n)
		{
			dp[i][j] = 0;
			if(i-1>=0)dp[i][j] += dp[i-1][j-1];
			if(i+1<n)dp[i][j] += dp[i+1][j-1];
			dp[i][j] %= mod;
		}
	}
	F0R(i,n)
	{
		cnt[i] = 0;
		F0R(j,k+1)
		{
			cnt[i] += dp[i][j] * dp[i][k-j];
			cnt[i] %= mod;
		}
	}
	ll cum = 0;
	F0R(i,n)
	{
		cum += a[i] * cnt[i];
		cum %= mod;
	}
	int id,x;
	while(q--)
	{
		cin>>id>>x;
		--id;
		cum -= (a[id] * cnt[id])%mod;
		a[id] = x;
		cum += (a[id] * cnt[id])%mod;
		while(cum<0)cum += mod;
		cum %= mod;
		cout<<cum<<'\n';
	}
    return 0;
}
