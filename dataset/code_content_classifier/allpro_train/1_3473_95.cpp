#include <bits/stdc++.h>
using namespace std;
const long long M = 1e5 + 10;
class matching {
 public:
  vector<vector<long long>> G;
  vector<long long> pa, push_back, was;
  long long n, m, res, t;
  matching(long long n, long long m) : n(n), m(m) {
    pa = vector<long long>(n + 1, -1);
    push_back = vector<long long>(m + 1, -1);
    was = vector<long long>(n + 1, 0);
    G.resize(n + 1);
    res = t = 0;
  }
  void add(long long u, long long v) { G[u].push_back(v); }
  bool dfs(long long u) {
    was[u] = t;
    for (long long v : G[u])
      if (push_back[v] < 0) {
        push_back[v] = u, pa[u] = v;
        return true;
      }
    for (long long v : G[u])
      if (was[push_back[v]] != t and dfs(push_back[v])) {
        push_back[v] = u, pa[u] = v;
        return true;
      }
    return false;
  }
  long long solve() {
    while (true) {
      t++;
      long long add = 0;
      for (long long i = 0; i < n; ++i)
        if (pa[i] < 0 and dfs(i)) ++add;
      if (!add) break;
      res += add;
    }
    return res;
  }
  bool run_one(long long u) {
    if (pa[u] < 0) return 0;
    t++;
    return dfs(u);
  }
};
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  long long dp[n + 1][n + 1];
  for (long long i = 0; i < n + 1; ++i)
    for (long long j = 0; j < n + 1; ++j) dp[i][j] = (long long)(1e18);
  for (long long i = 0; i < n + 1; ++i) dp[i][i] = 0;
  for (long long i = 0; i < m; ++i) {
    long long u, v;
    cin >> u >> v;
    dp[u][v] = dp[v][u] = 1;
  }
  long long s, b, k, h;
  cin >> s >> b >> k >> h;
  long long sid[s], a[s], f[s];
  for (long long i = 0; i < s; ++i) cin >> sid[i] >> a[i] >> f[i];
  long long bid[b], d[b];
  for (long long i = 0; i < b; ++i) cin >> bid[i] >> d[i];
  for (long long k = 1; k < n + 1; ++k)
    for (long long i = 1; i < n + 1; ++i)
      for (long long j = 1; j < n + 1; ++j) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
  matching match(s, b);
  for (long long i = 0; i < s; ++i)
    for (long long j = 0; j < b; ++j) {
      if (a[i] >= d[j] and f[i] >= dp[sid[i]][bid[j]]) {
        match.add(i, j);
      }
    }
  long long mx = match.solve();
  long long ans = (long long)(1e18);
  for (long long i = 0; i < s + 1; ++i)
    ans = min(ans, i * h + min(mx, s - i) * k);
  cout << ans;
  return 0;
}
