#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX / 2;
const int Maxn = 500;
int dp[Maxn + 5][Maxn + 5], ai[Maxn + 5], n, m, b, mod;
int solve() {
  memset(dp, 0, sizeof(dp));
  for (int(i) = (0); (i) <= (b); ++(i)) dp[0][i] = 1;
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= m; ++i)
      for (int j = ai[k]; j <= b; ++j) {
        dp[i][j] = (dp[i - 1][j - ai[k]] + dp[i][j]) % mod;
      }
  }
  return dp[m][b];
}
int main() {
  cin >> n >> m >> b >> mod;
  for (int(i) = (1); (i) <= (n); ++(i)) cin >> ai[i];
  cout << solve();
  return 0;
}
