#include <bits/stdc++.h>
#define R register
#define mp make_pair
#define ll long long
#define pii pair<int, int>
using namespace std;
const int N = 210000, mod = 998244353;

int n, dis[N], a, b;
ll f[N], g[N], pw[N];
vector<int> to[N];

template <class T>
inline void read(T &x) {
	x = 0;
	char ch = getchar(), w = 0;
	while (!isdigit(ch)) w = (ch == '-'), ch = getchar();
	while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	x = w ? -x : x;
	return;
}

inline void addEdg(int x, int y) {
	to[x].push_back(y), to[y].push_back(x);
	return;
}

void dfs1(int now, int fa) {
	dis[now] = dis[fa] + 1;
	for (auto &v : to[now]) {
		if (v == fa) continue;
		dfs1(v, now);
	}
	return;
}

int dfs2(int now, int fa, int maxD) {
	if (dis[now] == maxD) return 1;
	int ret = 0;
	for (auto &v : to[now]) {
		if (v == fa) continue;
		ret |= dfs2(v, now, maxD);
	}
	if (ret) {
		if (dis[now] == (maxD + 1) >> 1)
			a = now;
		else if (dis[now] == (maxD >> 1) + 1)
			b = now;
	}
	return ret;
}

void dfs3(int now, int fa, int maxD) {
	pw[now] = 1, dis[now] = dis[fa] + 1;
	if (dis[now] == (maxD + 1) >> 1) g[now] = 1;
	f[now] = 1 - g[now];
	for (auto &v : to[now]) {
		if (v == fa) continue;
		dfs3(v, now, maxD);
		g[now] = ((2 * pw[v] + f[v]) * g[now] + f[now] * g[v]) % mod;
		f[now] = (2 * pw[v] + f[v]) * f[now] % mod;
		pw[now] = pw[now] * pw[v] * 3 % mod;
	}
//	cout << "qwq " << now << ' ' << pw[now] << ' ' << f[now] << ' ' << g[now] << endl;
	return;
}

int main() {
	int x, y;
	read(n);
	for (R int i = 1; i < n; ++i)
		read(x), read(y), addEdg(x, y);
	dfs1(1, 0);
	int rt = 1, maxD = 1;
	for (R int i = 2; i <= n; ++i)
		if (dis[i] > maxD) maxD = dis[i], rt = i;
	dfs1(rt, 0), maxD = 1;
	for (R int i = 1; i <= n; ++i)
		maxD = max(maxD, dis[i]);
	dfs2(rt, 0, maxD);
	if (b) {
		dis[a] = 0, dfs3(b, a, maxD);
		dis[b] = 0, dfs3(a, b, maxD);
		printf("%lld\n", g[a] * g[b] % mod);
	}
	else {
		ll ans = 0;
		f[a] = 1, dis[a] = 1;
		for (auto &v : to[a]) {
			dfs3(v, a, maxD);
			ans = (ans * (pw[v] + 2 * f[v]) + g[a] * g[v]) % mod;
			g[a] = (g[a] * (pw[v] + 2 * f[v]) + f[a] * g[v]) % mod;
			f[a] = f[a] * (pw[v] + 2 * f[v]) % mod;
			//cout << "qwq " << v << ' ' << f[v] << ' ' << g[v] << endl;
		}
		printf("%lld\n", ans);
	}
	return 0;
}