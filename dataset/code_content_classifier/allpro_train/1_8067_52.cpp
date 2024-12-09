#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
vector<pair<int, int> > g[N];
vector<int> sz;
int n;
long long mx, mn;
void makeG() {
  mx = 0;
  mn = 0;
  sz.clear();
  sz.assign(n, 1);
  for (int i = 0; i < n; i++) g[i].clear();
  for (int i = 0; i < n - 1; i++) {
    int u, v, t;
    cin >> u >> v >> t;
    u--, v--;
    g[u].push_back({v, t});
    g[v].push_back({u, t});
  }
}
void dfs(int v, int p) {
  for (auto x : g[v]) {
    if (x.first == p) continue;
    dfs(x.first, v);
    mx += 1ll *
          (sz[x.first] < n - sz[x.first] ? sz[x.first] : n - sz[x.first]) *
          x.second;
    mn += 1ll * (sz[x.first] & 1) * x.second;
    sz[v] += sz[x.first];
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int Q;
  cin >> Q;
  while (Q--) {
    int i;
    cin >> n;
    n *= 2;
    makeG();
    dfs(0, -1);
    cout << mn << " " << mx << "\n";
  }
  return 0;
}
