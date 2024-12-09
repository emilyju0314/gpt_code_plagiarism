#include <bits/stdc++.h>
using namespace std;
int n;
int fr[3005], to[3005];
vector<int> adj[3005];
int dad[3005][3005], sz[3005][3005];
int d[3005][3005];
long long f[3005][3005];
vector<pair<int, int> > di[3005];
void dfs2(int u, int r) {
  sz[u][r] = 1;
  for (auto v : adj[u]) {
    if (v == dad[u][r]) continue;
    dad[v][r] = u;
    d[v][r] = d[u][r] + 1;
    di[d[v][r]].push_back({v, r});
    dfs2(v, r);
    sz[u][r] += sz[v][r];
  }
}
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    fr[i] = u, to[i] = v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    dfs2(i, i);
  }
  long long ans = 0;
  for (int y = 1; di[y].size(); ++y) {
    for (auto z : di[y]) {
      int u = z.first, v = z.second;
      int pu = dad[u][v], pv = dad[v][u];
      int su = sz[u][v], sv = sz[v][u];
      f[u][v] = max(f[u][v], f[pu][v] + su * sv);
      f[u][v] = max(f[u][v], f[u][pv] + su * sv);
      ans = max(ans, f[u][v]);
    }
  }
  cout << ans << endl;
  return 0;
}
