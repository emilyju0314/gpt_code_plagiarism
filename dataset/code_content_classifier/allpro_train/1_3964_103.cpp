#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
vector<vector<ll> > adj(100001);
vector<ll> dp, ans;

void dfs1(ll x, ll p) {
	for (ll c : adj[x]) {
		if (c == p) continue;
		dfs1(c, x);
		dp[x] *= dp[c] + 1; dp[x] %= m;
	}
	return;
}

void dfs2(ll x, ll p) {
	ll l = adj[x].size();
	vector<ll> cuml(l+2, 1);
	vector<ll> cumr(l+2, 1);
	for (ll i = 0; i < l; ++i) cuml[i+1] = (cuml[i] * (dp[adj[x][i]] + 1)) % m;
	for (ll i = l-1; i >= 0; --i) cumr[i+1] = (cumr[i+2] * (dp[adj[x][i]] + 1)) % m;
	ll pres_x = dp[x];
	for (ll i = 0; i < l; ++i)
	{
		ll c = adj[x][i];
		if (c == p) continue;
		ll pres_c = dp[c];
		dp[x] = (cuml[i] * cumr[i+2]) % m;
		dp[c] *= dp[x] + 1;
		dp[c] %= m;
		ans[c] = dp[c];
		dfs2(c, x);
		dp[x] = pres_x;
		dp[c] = pres_c;
	}
	return;
}

int main() {
	cin >> n >> m;
	dp.resize(n, 1);
	ans.resize(n, 0);
	for (ll i = 0; i < n-1; ++i)
	{
		ll a, b; cin >> a >> b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	dfs1(0, -1);
	ans[0] = dp[0];
	dfs2(0, -1);
	for (ll x : ans) cout << x << "\n";
	return 0;
}