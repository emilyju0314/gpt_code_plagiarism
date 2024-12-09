#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 4;
struct edge {
  int to, next;
} es[maxn * 2];
int head[maxn], cnt;
void add(int u, int v) {
  es[++cnt] = (edge){v, head[u]};
  head[u] = cnt;
}
int h[maxn], son[maxn];
void dfs1(int x, int fa) {
  h[x] = 1;
  for (int i = head[x]; i; i = es[i].next) {
    int v = es[i].to;
    if (v == fa) continue;
    dfs1(v, x);
    h[x] = max(h[x], h[v] + 1);
    if (h[v] > h[son[x]]) son[x] = v;
  }
}
int *dp[maxn], g[maxn], dfn[maxn];
void dfs2(int x, int fa) {
  dfn[x] = ++dfn[0];
  dp[x] = g + dfn[x];
  if (son[x]) dfs2(son[x], x);
  for (int i = head[x]; i; i = es[i].next) {
    int v = es[i].to;
    if (v == fa || v == son[x]) continue;
    dfs2(v, x);
  }
}
int ans[maxn];
void solve_dp(int x, int fa) {
  if (son[x] > 0) {
    solve_dp(son[x], x);
    ans[x] = ans[son[x]] + 1;
  }
  dp[x][0] = 1;
  if (dp[x][ans[x]] == dp[x][0]) ans[x] = 0;
  for (int i = head[x]; i; i = es[i].next) {
    int v = es[i].to;
    if (v == son[x] || fa == v) continue;
    solve_dp(v, x);
    int len = h[v];
    for (int j = 0; j < len; j++) {
      dp[x][j + 1] += dp[v][j];
      if (dp[x][j + 1] > dp[x][ans[x]]) ans[x] = j + 1;
      if (dp[x][j + 1] == dp[x][ans[x]] && ans[x] > j + 1) ans[x] = j + 1;
    }
  }
}
int n;
int main() {
  cin >> n;
  for (int i = 1, x, y; i < n; i++) {
    cin >> x >> y;
    add(x, y);
    add(y, x);
  }
  dfs1(1, 0);
  dfs2(1, 0);
  solve_dp(1, 0);
  for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
  return 0;
}
