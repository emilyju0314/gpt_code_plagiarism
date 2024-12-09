#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
const int MOD = (int)1e9 + 7;
long long dp[maxn][maxn];
int main() {
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  if (abs(a - b) <= 1) {
    printf("0\n");
    return 0;
  }
  dp[0][a] = 1;
  for (int i = 0; i < k; i++) {
    for (int j = 1; j <= n; j++) {
      int d = abs(j - b);
      if (d == 0) continue;
      dp[i + 1][max(1, j - d + 1)] += dp[i][j];
      dp[i + 1][max(1, j - d + 1)] %= MOD;
      dp[i + 1][j] -= dp[i][j];
      dp[i + 1][j] += MOD;
      dp[i + 1][j] %= MOD;
      if (j + 1 <= n) {
        dp[i + 1][j + 1] += dp[i][j];
        dp[i + 1][j + 1] %= MOD;
      }
      if (j + d <= n) {
        dp[i + 1][j + d] -= dp[i][j];
        dp[i + 1][j + d] += MOD;
        dp[i + 1][j + d] %= MOD;
      }
    }
    for (int j = 1; j <= n; j++) {
      dp[i + 1][j] += dp[i + 1][j - 1];
      dp[i + 1][j] %= MOD;
    }
    dp[i + 1][b] = 0;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = ans + dp[k][i];
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
