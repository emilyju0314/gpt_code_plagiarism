#include <bits/stdc++.h>
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
using namespace std;
const long long N = 3005;
const long long mod = 1e9 + 7;
const long long INF = 0x7f7f7f7f7f7f7f7f;
const int INFi = 0x7f7f7f7f;
long long test = 1, n, dp[N][N], sz[N][N], par[N][N];
vector<long long> adj[N];
void dfs(long long x, long long p, long long st) {
  sz[st][x] = 1;
  for (auto it : adj[x]) {
    if (it == p) continue;
    dfs(it, x, st);
    par[st][it] = x;
    sz[st][x] += sz[st][it];
  }
}
long long mem(long long u, long long v) {
  if (u == v) return 0;
  if (dp[u][v] != -1) return dp[u][v];
  dp[u][v] = dp[v][u] =
      max(mem(par[u][v], u), mem(par[v][u], v)) + sz[u][v] * sz[v][u];
  return dp[u][v];
}
void solve() {
  memset(dp, -1, sizeof(dp));
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    dfs(i, 0, i);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      ans = max(ans, mem(i, j));
    }
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(15);
  ;
  for (int i = 1; i <= test; i++) {
    solve();
  }
}
