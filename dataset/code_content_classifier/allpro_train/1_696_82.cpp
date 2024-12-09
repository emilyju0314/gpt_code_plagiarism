#include <bits/stdc++.h>
using namespace std;
const int N = 5100;
int n, m, d;
vector<int> g[N];
int vis[N], lin[N], k[N], p[N], c[N];
int dfs(int u) {
  for (int i = 0; i < (int)g[u].size(); i++) {
    int v = g[u][i];
    if (vis[v]) continue;
    vis[v] = 1;
    if (!lin[v] || dfs(lin[v])) {
      lin[v] = u;
      return 1;
    }
  }
  return 0;
}
int get(int x) {
  for (int i = 1; i <= m; i++) vis[i] = 0;
  return dfs(x);
}
int main() {
  scanf("%d%d", &n, &m);
  int mx = 0;
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]), p[i]++, mx = max(mx, p[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
  scanf("%d", &d);
  for (int i = 1; i <= d; i++) scanf("%d", &k[i]), vis[k[i]] = 1;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) g[p[i]].push_back(c[i]);
  int ans = 0;
  while (ans + 1 <= mx && get(ans + 1)) ans++;
  vector<int> sna;
  for (int i = d; i >= 1; i--) {
    sna.push_back(ans);
    g[p[k[i]]].push_back(c[k[i]]);
    while (ans + 1 <= mx && get(ans + 1)) ans++;
  }
  for (int i = (int)sna.size() - 1; i >= 0; i--) printf("%d\n", sna[i]);
  return 0;
}
