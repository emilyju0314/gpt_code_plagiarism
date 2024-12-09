#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 7;
vector<long long> g[N];
long long sz[N], d[N], deg[N], cost[N];
void dfs(long long v, long long h = 0, long long p = -1) {
  deg[v] = g[v].size();
  d[v] = h;
  sz[v] = 1;
  for (long long u : g[v]) {
    if (u == p) continue;
    dfs(u, h + 1, v);
    sz[v] += sz[u];
  }
  cost[v] = d[v] - (sz[v] - 1);
}
signed main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  set<pair<long long, long long>, greater<pair<long long, long long>>> s;
  for (long long i = 0; i < n - 1; i++) {
    long long v, u;
    cin >> v >> u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  if (k == n) {
    cout << 0 << endl;
  }
  dfs(1);
  long long res = 0;
  for (long long i = 2; i <= n; i++) {
    if (deg[i] == 1) {
      s.insert({cost[i], i});
    }
  }
  for (long long i = 0; i < k; i++) {
    auto kek = *s.begin();
    s.erase(s.begin());
    res += kek.first;
    for (long long elem : g[kek.second]) {
      if (--deg[elem] == 1 && elem != 1) {
        s.insert({cost[elem], elem});
      }
    }
  }
  cout << res << endl;
  return 0;
}
