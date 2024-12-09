#include <bits/stdc++.h>

using namespace std;
const int maxn = 5005;
typedef long long ll;
int dp[2][maxn],sum[maxn];
int main() {
	int n,mod,rt = 0;
	cin>>n>>mod;
	dp[rt][0] = 1;
	for(int i = 1;i < n;++i) {
		rt ^= 1;
		int s = i;
		if(n%2 == 1&& s > n/2 + 1) s = (n-i+1);
		if(n%2 == 0 && s > n/2) s = (n-i+1);
		memset(dp[rt],0,(n+1)<<2);
		for(int j = 0;j < n; ++j) {
			ll temp = 0;
			int k = 0;
			for(k = 0;k < n&&j-(k+16)*s>=0; k += 16) {
				temp += dp[rt^1][j-k*s];
				temp += dp[rt^1][j-(k+1)*s];
				temp += dp[rt^1][j-(k+2)*s];
				temp += dp[rt^1][j-(k+3)*s];
				temp += dp[rt^1][j-(k+4)*s];
				temp += dp[rt^1][j-(k+5)*s];
				temp += dp[rt^1][j-(k+6)*s];
				temp += dp[rt^1][j-(k+7)*s];
				temp += dp[rt^1][j-(k+8)*s];
				temp += dp[rt^1][j-(k+9)*s];
				temp += dp[rt^1][j-(k+10)*s];
				temp += dp[rt^1][j-(k+11)*s];
				temp += dp[rt^1][j-(k+12)*s];
				temp += dp[rt^1][j-(k+13)*s];
				temp += dp[rt^1][j-(k+14)*s];
				temp += dp[rt^1][j-(k+15)*s];
			}
			for(;k < n &&j - k*s >= 0; ++k) temp += dp[rt^1][j-k*s];
			dp[rt][j] = temp%mod;
		}
	}
	ll ans = 0;
	for(int i = 0;i < n; ++i) {
		int j = n-i-1;
		ans += 1ll*(j+1)* dp[rt][i];
		ans %= mod;
	}
	cout<<ans<<'\n';
	return 0;
}