#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 6;
vector<long long> g[N], r[N];
long long me[N], md[N];
long long used1[N], used2[N];
bool is_cycle = false;
void dfs(long long v) {
  used1[v] = 1;
  me[v] = v;
  for (auto u : g[v]) {
    if (used1[u] == 1) is_cycle = true;
    if (!used1[u]) {
      dfs(u);
    }
    me[v] = min(me[v], me[u]);
  }
  used1[v] = 2;
}
void dfs_r(long long v) {
  used2[v] = 1;
  md[v] = v;
  for (auto u : r[v]) {
    if (!used2[u]) {
      dfs_r(u);
    }
    md[v] = min(md[v], md[u]);
  }
  used2[v] = 2;
}
signed main() {
  long long n, m;
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    long long u, v;
    cin >> u >> v;
    g[u].push_back(v);
    r[v].push_back(u);
  }
  for (long long i = 1; i <= n; i++)
    if (!used1[i]) dfs(i);
  for (long long i = 1; i <= n; i++)
    if (!used2[i]) dfs_r(i);
  if (is_cycle) return cout << -1, 0;
  long long cnt = 0;
  for (long long i = 1; i <= n; i++) cnt += (me[i] == i && md[i] == i);
  cout << cnt << '\n';
  for (long long i = 1; i <= n; i++)
    cout << (me[i] == i && md[i] == i ? 'A' : 'E');
}
