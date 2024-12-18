#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define mkp make_pair
#define pii pair<int, int>
#define ll long long
#define db double
#define sz(a) a.size()
#define x first
#define y second
#define vi vector<int>
using namespace std;
const int N = 307, mod = 998244353, inv2 = (mod + 1) / 2;
int n, Mid, ns = mod - 1, val[N], dep[N], dp[N][N * 2], t[N * 2];
vi e[N];
void dfs(int x, int fa) {
	dp[x][dep[x] + 1 + N] = 1, dp[x][dep[x] - Mid + N] = 1;
	for(const int &v : e[x]) if(v != fa) {
		dep[v] = dep[x] + 1, dfs(v, x);
		vi A, B;
		L(i, -N, n) if(dp[x][i + N]) A.push_back(i);
		L(i, -N, n) if(dp[v][i + N]) B.push_back(i);
		for(const int &a : A) for(const int &b : B)
			(t[(a + b - 1 <= 2 * dep[x] ? min(a, b) : max(a, b)) + N] += (ll) dp[x][a + N] * dp[v][b + N] % mod) %= mod;
		L(i, -N, n) dp[x][i + N] = t[i + N], t[i + N] = 0;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n;
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v), e[v].push_back(u);
	}
	L(i, 1, n) { // val : < i
		Mid = i, memset(dp, 0, sizeof(dp)), dfs(1, 0);
		L(a, -N, 0) (val[i] += dp[1][a + N]) %= mod;
		val[i] = mod - val[i], (ns += val[i]) %= mod;
	}
	L(i, 1, n) ns = (ll) ns * inv2 % mod;
	(ns += n) %= mod;
	cout << ns << "\n";
	return 0;
}