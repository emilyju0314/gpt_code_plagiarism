#include<vector>
#include<bitset>
#include<cstdio>
#include<iostream>
#include<algorithm>
#define pb push_back
#define nc getchar
using namespace std;
inline void read(int &x) {
	char b = nc(); x = 0;
	for (; !isdigit(b); b = nc());
	for (; isdigit(b); b = nc()) x = x * 10 + b - '0';
}
struct Node {
	int x, y, id;	
	inline bool operator<(const Node &o) const {
		return x < o.x || (x == o.x && y < o.y);
	}
} a[100005];
int n, s, t, D, f[100005];
long long ans;
vector < int > g[100005];
bitset < 100005 > vis;
inline int ABS(int x) {return x > 0 ? x : -x;}
inline void ae(int u, int v) {
	g[u].pb(v); g[v].pb(u);	
}
void build(int k) {
	sort(a + 1, a + 1 + n); int i, j, l, r;
	for (i = j = l = r = 1; i <= n; ++i) {
		while (a[l].x < a[i].x - D || (a[l].x == a[i].x - D && a[i].y - a[l].y > k)) ++l;
		while (a[r].x < a[i].x - D || (a[r].x == a[i].x - D && a[r].y - a[i].y <= k)) ++r;
		f[a[i].id] += r - l; j = max(j, l); if (j < r) ae(a[i].id, a[j].id);
		for (; j + 1 < r; ++j) ae(a[j].id, a[j+1].id);
	}
}
void dfs(int u) {
	if (vis[u]) return; vis[u] = 1; ans += f[u];
	for (int i = 0; i < g[u].size(); ++i) dfs(g[u][i]);
}
int main() {
	read(n); read(s); read(t);
	for (int x, y, i = 1; i <= n; ++i)
		read(x), read(y), a[i] = (Node){x + y, x - y, i};
	D = max(ABS(a[s].x - a[t].x), ABS(a[s].y - a[t].y));
	build(D);
	for (int i = 1; i <= n; ++i) swap(a[i].x, a[i].y);
	build(D-1);
	dfs(s);
	printf("%lld\n", ans);
	return 0;
}
