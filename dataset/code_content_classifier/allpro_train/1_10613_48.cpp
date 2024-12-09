#include <bits/stdc++.h>
using namespace std;
int g[300010], rc = 0, n, q;
struct node {
  int t, nxt;
} e[300010];
void ade(int u, int v) {
  e[rc].t = v;
  e[rc].nxt = g[u];
  g[u] = rc++;
}
int ans[300010], mx[300010], s[300010], fa[300010];
void dfs(int u) {
  s[u] = 1;
  for (int i = g[u]; ~i; i = e[i].nxt) {
    int v = e[i].t;
    dfs(v);
    s[u] += s[v];
    mx[u] = max(mx[u], s[v]);
  }
}
void get(int u) {
  int as = u, mi = 1 << 30;
  for (int i = g[u]; ~i; i = e[i].nxt) {
    int v = e[i].t;
    get(v);
    int p = ans[v], now = mx[ans[v]];
    while (p != u && max(s[u] - s[fa[p]], mx[fa[p]]) < max(s[u] - s[p], mx[p]))
      p = fa[p];
    if (max(s[u] - s[p], mx[p]) < mi) mi = max(s[u] - s[p], mx[p]), as = p;
  }
  ans[u] = as;
}
int main() {
  memset(g, 0xff, sizeof(g));
  scanf("%d%d", &n, &q);
  for (int i = 2; i <= n; i++) scanf("%d", &fa[i]), ade(fa[i], i);
  dfs(1);
  get(1);
  int x;
  for (int i = 1; i <= q; i++) scanf("%d", &x), printf("%d\n", ans[x]);
}
