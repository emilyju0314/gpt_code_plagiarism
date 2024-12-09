#include <bits/stdc++.h>
using namespace std;
#define int long long
void read (int &x) {
    char ch = getchar(); int f = 0; x = 0;
    while (!isdigit(ch)) { if (ch == '-') f = 1; ch = getchar(); }
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
    if (f) x = -x;
} const int N = 2e5 + 5;
int n, q, res, cnt[N], vis[N], p[N], a[N], b[N], fa[N][20], tp, t[N], sum[N], f[N], d[N];
set<int> s; set<int>::iterator it;
int lca(int x, int y) {
	if (d[x] < d[y]) swap(x, y);
	for (int i = 18; i >= 0; --i)
	  if (d[fa[x][i]] >= d[y]) x = fa[x][i];
	if (x == y)  return x;
	for (int i = 18; i >= 0; --i)
	  if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
int dis (int x, int y) {
    return f[x] + f[y] - 2 * f[lca (x, y)];
}
int add (int x) {
    it = s.insert(x).first; int l = *(--it); ++it, ++it;
    int r = it == s.end() ? *s.begin() : *it;
    res += dis (l, x) + dis (x, r) - dis (l, r);
}
void del (int x) {
    it = s.find (x); int l = *(--it); ++it, ++it;
    int r = it == s.end() ? *s.begin() : *it;
    res -= dis (l, x) + dis (x, r) - dis (l, r); s.erase (--it);
}
signed main() {
    read (n), read (q);
    for (int i = 1; i <= n; ++i) read (p[i]);
    for (int i = 1; i <= n; ++i) read (a[i]);
    for (int i = 1; i <= n; ++i) read (b[i]);
    for (int i = 1; i <= n; ++i) {
        while (tp && p[t[tp]] < p[i]) --tp;
        d[i] = d[fa[i][0] = t[tp]] + 1; t[++tp] = i;
        for (int j = 1; (1 << j) <= d[i]; ++j)
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
    }
    for (int i = 1; i <= n; ++i)
        sum[i] = a[i] - b[i], sum[fa[i][0]] += b[i];
    for (int i = n; i >= 1; --i) 
        f[i] += sum[i], f[fa[i][0]] += min (f[i], 0ll), f[i] = max (f[i], 0ll);
    f[0] += sum[0]; for (int i = 1; i <= n; ++i) f[i] += f[fa[i][0]];
    ++cnt[0], s.insert (0);
    while (q--) {
        int x; read (x);
        if (vis[x]) {
            vis[x] = 0; if (!(--cnt[fa[x][0]])) del (fa[x][0]);
        } else {
            vis[x] = 1; if (!(cnt[fa[x][0]]++)) add (fa[x][0]);
        }
        printf ("%lld\n", res / 2 + f[0]);
    }
    return 0;
}
