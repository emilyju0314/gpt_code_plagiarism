#include <bits/stdc++.h>
using namespace std;
int lst[1005], to[2000005], pre[2000005], tot;
int deg[1005], x[1005], y[1005], vis[1005], n, k;
inline void add_edge(int u, int v) {
  to[tot] = v;
  pre[tot] = lst[u];
  deg[v]++;
  lst[u] = tot++;
}
void init(int n, int m) {
  memset(lst, -1, n << 2);
  memset(deg, 0, n << 2);
  memset(vis, 0, n << 2);
  tot = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) > m)
        add_edge(i, j);
    }
  }
}
bool dfs(int u, int k) {
  if (u >= n) return true;
  if (vis[u]) return dfs(u + 1, k);
  for (int i = lst[u]; ~i; i = pre[i]) {
    k -= !vis[to[i]];
    vis[to[i]]++;
  }
  if (k >= 0 && dfs(u + 1, k)) return true;
  vis[u] = true;
  int x = k;
  for (int i = lst[u]; ~i; i = pre[i]) {
    vis[to[i]]--;
    k += !vis[to[i]];
  }
  k--;
  if (k >= 0 && k > x && dfs(u + 1, k)) return true;
  vis[u] = false;
  return false;
}
int main() {
  int l = 0, r = 0, ans = 0;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", x + i, y + i);
    for (int j = 0; j < i; j++)
      r = max(r, (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
  }
  while (l <= r) {
    int m = l + r >> 1;
    init(n, m);
    if (dfs(0, k)) {
      ans = m;
      r = m - 1;
    } else
      l = m + 1;
  }
  init(n, ans);
  dfs(0, k);
  for (int i = 0; i < n; i++) {
    if (vis[i]) printf("%d%c", i + 1, " \n"[!--k]);
  }
  for (int i = 0; i < n; i++) {
    if (!vis[i] && k) printf("%d%c", i + 1, " \n"[!--k]);
  }
  return 0;
}
