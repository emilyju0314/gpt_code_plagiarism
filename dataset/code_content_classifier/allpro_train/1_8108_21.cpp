#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 11;
int n, q, tot, x, y;
int f[N], fa[N], las[N], to[N], nxt[N], sz[N], s[N], dep[N];
long long val[N], ans;
inline void add(int x, int y) {
  nxt[++tot] = las[x];
  las[x] = tot;
  to[tot] = y;
}
inline int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
inline void dfs(int x) {
  sz[x] = 1;
  for (register int e = las[x]; e; e = nxt[e]) {
    if (to[e] == fa[x]) continue;
    fa[to[e]] = x;
    dep[to[e]] = dep[x] + 1;
    dfs(to[e]);
    sz[x] += sz[to[e]];
    val[x] += 1ll * sz[to[e]] * sz[to[e]];
  }
  val[x] += 1ll * (n - sz[x]) * (n - sz[x]);
  ans -= val[x];
}
inline void merge(int x, int y) {
  ans -= 1ll * (n - s[x]) * (n - s[x]) * s[x] - val[x] * s[x] +
         1ll * s[x] * (s[x] - 1) * (s[x] - 2) +
         1ll * s[x] * (s[x] - 1) * (n - s[x]) * 2 +
         1ll * (n - s[y]) * (n - s[y]) * s[y] - val[y] * s[y] +
         1ll * s[y] * (s[y] - 1) * (s[y] - 2) +
         1ll * s[y] * (s[y] - 1) * (n - s[y]) * 2;
  f[y] = x, s[x] += s[y];
  val[x] += val[y] - 1ll * sz[y] * sz[y] - 1ll * (n - sz[y]) * (n - sz[y]);
  ans += 1ll * (n - s[x]) * (n - s[x]) * s[x] - val[x] * s[x] +
         1ll * s[x] * (s[x] - 1) * (s[x] - 2) +
         1ll * s[x] * (s[x] - 1) * (n - s[x]) * 2;
}
int main() {
  scanf("%d", &n);
  for (register int i = 2; i <= n; ++i) {
    scanf("%d%d", &x, &y);
    add(x, y), add(y, x);
  }
  ans = 1ll * n * (n - 1) * (n - 1);
  dfs(1);
  printf("%lld\n", n == 0 ? 0 : ans);
  scanf("%d", &q);
  for (register int i = 1; i <= n; ++i) f[i] = i, s[i] = 1;
  for (; q--;) {
    scanf("%d%d", &x, &y);
    x = find(x), y = find(y);
    for (; x != y;) {
      if (dep[x] < dep[y]) swap(x, y);
      merge(find(fa[x]), x), x = find(fa[x]);
    }
    printf("%lld\n", n == 0 ? 0 : ans);
  }
  return 0;
}
