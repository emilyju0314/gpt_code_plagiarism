#include <bits/stdc++.h>
using namespace std;
int const N = 100100;
int const M = 1001000;
long long x[N], y[N];
int r[N];
int root;
bool check(int a, int b, int c) {
  if (c == root) return 0;
  long long x1 = x[b] - x[a], x2 = x[c] - x[a];
  long long y1 = y[b] - y[a], y2 = y[c] - y[a];
  return x1 * y2 > x2 * y1;
}
struct edges {
  int u, next;
} e[M];
int p[N], idx;
void addedge(int u, int v) { e[idx].u = v, e[idx].next = p[u], p[u] = idx++; }
void init() {
  idx = 0;
  memset(p, (0xff), sizeof p);
}
int dep[N], dp[21][N];
void dfs(int u, int d, int pre) {
  dep[u] = d, dp[0][u] = pre;
  for (int i = 1; (1 << i) <= d; ++i) dp[i][u] = dp[i - 1][dp[i - 1][u]];
  for (int i = p[u]; ~i; i = e[i].next) {
    int v = e[i].u;
    if (v != pre) dfs(v, d + 1, u);
  }
}
int lca(int a, int b) {
  if (dep[a] < dep[b]) swap(a, b);
  for (int t = dep[a] - dep[b], step = 0; t; ++step, t >>= 1)
    if (t & 1) a = dp[step][a];
  if (a == b) return a;
  for (int i = 20; ~i; --i)
    if (dp[i][a] != dp[i][b]) a = dp[i][a], b = dp[i][b];
  return dp[0][a];
}
int main() {
  int n;
  scanf("%d", &n);
  root = n + 1;
  for (int i = 1; i <= (n); ++i) {
    scanf("%I64d %I64d", &x[i], &y[i]);
    r[i] = i + 1;
  }
  for (int i = n - 1; i >= 1; --i) {
    while (check(i, r[i], r[r[i]])) {
      r[i] = r[r[i]];
    }
  }
  ++n;
  init();
  for (int i = 1; i <= (n); ++i) addedge(r[i], i);
  dfs(root, 0, -1);
  int m;
  scanf("%d", &m);
  int a, b;
  while (m--) {
    scanf("%d%d", &a, &b);
    printf("%d ", lca(a, b));
  }
  puts("");
  return 0;
}
