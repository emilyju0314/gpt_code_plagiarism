#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int MX = 110000;
int n, m, q[MX], qn, vis[MX], cn, c[MX];
vector<int> adj[MX], _adj[MX];
void DFS(int u) {
  vis[u]++;
  for (int v : adj[u])
    if (!vis[v]) DFS(v);
  q[qn++] = u;
}
void _DFS(int u) {
  vis[u] = cn;
  for (int v : _adj[u])
    if (!vis[v]) _DFS(v);
}
void SCC() {
  memset(vis, 0, sizeof vis);
  qn = 0;
  for (int u = 0; u < n; u++)
    if (!vis[u]) DFS(u);
  for (int u = 0; u < n; u++) _adj[u].clear();
  for (int u = 0; u < n; u++)
    for (int v : adj[u]) _adj[v].push_back(u);
  memset(vis, 0, sizeof vis);
  cn = 0;
  for (int i = n - 1; i >= 0; i--) {
    int u = q[i];
    if (!vis[u]) {
      cn++;
      _DFS(u);
    }
  }
}
vector<int> rlt[MX];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", &c[i]);
  cin >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    adj[u].push_back(v);
  }
  SCC();
  for (int i = 0; i < n; i++) rlt[vis[i]].push_back(i);
  long long ans1 = 0, ans2 = 1;
  for (int i = 0; i <= cn; i++) {
    if (rlt[i].empty()) continue;
    int Min = 1e9;
    for (int u : rlt[i]) Min = min(Min, c[u]);
    ans1 += Min;
    int ret = 0;
    for (int u : rlt[i]) ret += (Min == c[u]);
    ans2 = ans2 * ret % mod;
  }
  cout << ans1 << " " << ans2 << endl;
  return 0;
}
