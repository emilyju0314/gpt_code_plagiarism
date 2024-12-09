#include <bits/stdc++.h>

#define For(i, j, k) for (int i = j; i <= k; i++)

using namespace std;

const int N = 110;
const int Mod = 1e9 + 7;

int h[N], fa[N], n;
int dp[N][2];

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int Pow(int x, int e) {
	int ret = 1;
	while (e) {
		if (e & 1) ret = 1ll * ret * x % Mod;
		x = 1ll * x * x % Mod;
		e >>= 1;
	}
	return ret;
}

int rk[N];

bool cmp(int x, int y) {
	return h[x] > h[y];
}

bool vis[N];

int main() {

	scanf("%d", &n);
	For(i, 1, n) scanf("%d", &h[i]), fa[i] = i, rk[i] = i;
	sort(rk + 1, rk + n + 1, cmp);

	For(i, 1, n) {
		int x = rk[i], u = 0, v = 0;
		vis[x] = true;
		if (vis[x - 1]) u = find(x - 1), dp[u][0] = 1ll * dp[u][0] * Pow(2, h[u] - h[x]) % Mod, fa[u] = x;
		if (vis[x + 1]) v = find(x + 1), dp[v][0] = 1ll * dp[v][0] * Pow(2, h[v] - h[x]) % Mod, fa[v] = x;
		if (!u) u = v, v = 0;

		if (!u) {
			dp[x][0] = 1, dp[x][1] = 0;
		} else if (!v) {
			dp[x][0] = dp[u][0];
			dp[x][1] = (dp[u][1] * 2ll + dp[u][0] * 2ll) % Mod;
		} else {
			dp[x][0] = 1ll * dp[u][0] * dp[v][0] % Mod;
			dp[x][1] = 2ll * dp[u][1] * dp[v][1] % Mod;
			dp[x][1] = (dp[x][1] + 4ll * dp[u][0] * dp[v][1] + 4ll * dp[v][0] * dp[u][1]) % Mod;
			dp[x][1] = (dp[x][1] + 6ll * dp[u][0] * dp[v][0]) % Mod;
		}
	}

	int x = find(1);
	int ans = (dp[x][1] + 1ll * dp[x][0] * Pow(2, h[x])) % Mod;
	printf("%d\n", ans);

	return 0;
}