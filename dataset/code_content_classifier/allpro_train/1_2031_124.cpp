#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
int n, k;
int a[6][N];
int p[6][N];
int dp[N];
vector<int> f[N];
void dfs(int u) {
  dp[u] = 1;
  for (int v : f[u]) {
    if (dp[v]) {
      dp[u] = max(dp[u], dp[v] + 1);
    } else {
      dfs(v);
      dp[u] = max(dp[u], dp[v] + 1);
    }
  }
}
void solve() {
  cin >> n >> k;
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
      p[i][a[i][j]] = j;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == j) continue;
      bool ok = 1;
      for (int q = 1; q <= k; ++q) {
        if (p[q][i] > p[q][j]) ok = 0;
      }
      if (ok) f[i].push_back(j);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!dp[i]) dfs(i);
  }
  int res = 0;
  for (int i = 1; i <= n; ++i)
    if (dp[i] > res) res = dp[i];
  cout << res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
