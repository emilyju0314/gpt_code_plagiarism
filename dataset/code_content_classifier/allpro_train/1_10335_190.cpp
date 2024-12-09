#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long mod = 1e9 + 7;
vector<long long> g[5003];
bool pr[5003], pr2[5003];
long long dp[5003];
void dfs(long long i, long long p) {
  dp[i] = 1;
  vector<long long> v;
  v.clear();
  for (auto j : g[i]) {
    if (j != p) {
      dfs(j, i);
      v.push_back(dp[j]);
      dp[i] += dp[j];
    }
  }
  fill(pr2, pr2 + 5003, 0);
  pr2[0] = 1;
  long long j, l, sz = v.size();
  for (j = 0; j < sz; ++j)
    for (l = 5003 - 3 - v[j]; l >= 0; --l)
      if (pr2[l]) pr2[l + v[j]] = 1;
  for (j = 1; j <= 5003 - 3; ++j) pr[j] |= pr2[j];
  pr[dp[i]] = 1;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long i, j, u, v;
  for (i = 1; i <= n - 1; ++i)
    cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
  dfs(1, 1);
  vector<pair<long long, long long> > ans;
  ans.clear();
  for (i = 1; i <= n - 2; ++i) {
    if (pr[i]) {
      ans.push_back({i, n - 1 - i});
      if (i != n - i - 1) ans.push_back({n - 1 - i, i});
      pr[n - 1 - i] = 0;
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for (auto it : ans) cout << it.first << ' ' << it.second << '\n';
  return 0;
}
