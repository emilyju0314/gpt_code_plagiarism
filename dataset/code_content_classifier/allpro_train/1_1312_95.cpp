#include <bits/stdc++.h>
using namespace std;
long long dp[2050][2050];
signed main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) dp[i][0] = m;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] * (m - 1);
      dp[i][j] %= 998244353;
    }
  }
  cout << dp[n - 1][k];
  return 0;
}
