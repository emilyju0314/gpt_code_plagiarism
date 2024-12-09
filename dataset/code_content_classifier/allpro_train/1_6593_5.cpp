#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
void solve() {
  int n;
  cin >> n;
  vector<int> l(n + 1, INF), r(n + 1, -INF), v(n);
  for (int i = 0; i < n; ++i) {
    int val;
    cin >> val;
    l[val] = min(l[val], i);
    r[val] = max(r[val], i);
    v[i] = val;
  }
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  vector<int> dp(n, 0);
  int res = INT_MAX;
  for (int i = v.size() - 1; i >= 0; --i) {
    if (i + 1 == v.size() || r[v[i]] > l[v[i + 1]])
      dp[i] = 1;
    else
      dp[i] = dp[i + 1] + 1;
    res = min(res, (int)v.size() - dp[i]);
  }
  cout << res << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
