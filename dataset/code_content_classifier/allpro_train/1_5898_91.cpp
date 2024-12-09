#include <bits/stdc++.h>
#pragma GCC optimize "03"
using namespace std;
const long long int N = 5e5 + 5;
const long long int mod = 1e9 + 7;
long long int n, k, dp[N][2];
vector<pair<long long int, long long int> > g[N];
void dfs(long long int u, long long int p) {
  long long int cur = 0;
  vector<long long int> v;
  for (auto i : g[u]) {
    if (i.first == p) continue;
    dfs(i.first, u);
    cur += dp[i.first][1];
    v.push_back(dp[i.first][0] - dp[i.first][1] + i.second);
  }
  dp[u][0] = dp[u][1] = cur;
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  for (long long int i = 0; i < (long long int)v.size(); i++) {
    if (v[i] > 0) cur += v[i];
    if (i < k - 1) dp[u][0] = cur;
    if (i < k) dp[u][1] = cur;
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int q;
  cin >> q;
  while (q--) {
    cin >> n >> k;
    for (long long int i = 1; i <= n; i++) {
      g[i].clear();
      dp[i][0] = dp[i][1] = 0;
    }
    for (long long int i = 1; i <= n - 1; i++) {
      long long int u, v, w;
      cin >> u >> v >> w;
      g[u].push_back({v, w});
      g[v].push_back({u, w});
    }
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << '\n';
  }
  return 0;
}
