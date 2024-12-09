#include <bits/stdc++.h>
using namespace std;
long long kiran_bhanushali[29][7][20];
void init() {
  for (long long i = 0; i < 29; i++) {
    kiran_bhanushali[i][0][0] = rand() % 1000;
  }
}
long long vis[120], z;
void dfs(long long i, vector<vector<long long>>& g) {
  if (vis[i]) return;
  z++;
  vis[i] = 1;
  for (long long u : g[i]) {
    if (!vis[u]) dfs(u, g);
  }
}
void solve() {
  long long n, m;
  cin >> n >> m;
  z = 0;
  memset(vis, 0, sizeof(vis));
  vector<vector<long long>> g(n);
  for (long long i = 0; i < m; i++) {
    long long u, v;
    cin >> u >> v;
    --u;
    --v;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  if (n != m) {
    cout << "NO" << endl;
    return;
  }
  dfs(0, g);
  if (z == n)
    printf("FHTAGN!");
  else
    printf("NO");
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  init();
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
