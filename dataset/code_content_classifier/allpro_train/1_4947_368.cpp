#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n, k;
  cin >> n >> k;
  long long h[n];
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  long long hh[n];
  hh[0] = h[n - 1];
  for (int j = 1; j < n; ++j) {
    hh[j] = h[j - 1];
  }
  long long dp[n + 1][n + 1][2];
  for (int l = 0; l < n + 1; ++l) {
    for (int i = 0; i < n + 1; ++i) {
      dp[l][i][0] = 0;
      dp[l][i][1] = 0;
    }
  }
  dp[0][0][0] = 1;
  for (int m = 1; m < n + 1; ++m) {
    for (int i = 0; i < n + 1; ++i) {
      if (h[m - 1] == hh[m - 1]) {
        dp[m][i][0] += dp[m - 1][i][0] * (k);
        dp[m][i][0] %= mod;
        dp[m][i][1] += dp[m - 1][i][1] * k;
        dp[m][i][1] %= mod;
      } else {
        dp[m][i][0] += dp[m - 1][i][0] * (k - 2);
        dp[m][i][0] %= mod;
        dp[m][i][1] += dp[m - 1][i][1] * (k - 2);
        dp[m][i][1] %= mod;
        if (i == 0) {
          dp[m][i][0] += dp[m - 1][1][1];
          dp[m][i][0] %= mod;
          dp[m][i][0] += dp[m - 1][1][0];
          dp[m][i][0] %= mod;
        } else if (i == 1) {
          dp[m][i][1] += dp[m - 1][0][0];
          dp[m][i][1] %= mod;
          dp[m][i][1] += dp[m - 1][i + 1][1];
          dp[m][i][1] %= mod;
          dp[m][i][0] += dp[m - 1][i + 1][0];
          dp[m][i][0] %= mod;
          dp[m][i][0] += dp[m - 1][i - 1][0];
          dp[m][i][0] %= mod;
        } else {
          if (i == n) {
            dp[m][i][0] += dp[m - 1][i - 1][0];
            dp[m][i][0] %= mod;
            dp[m][i][1] += dp[m - 1][i - 1][1];
            dp[m][i][1] %= mod;
          } else {
            dp[m][i][0] += dp[m - 1][i - 1][0];
            dp[m][i][0] %= mod;
            dp[m][i][0] += dp[m - 1][i + 1][0];
            dp[m][i][0] %= mod;
            dp[m][i][1] += dp[m - 1][i + 1][1];
            dp[m][i][1] %= mod;
            dp[m][i][1] += dp[m - 1][i - 1][1];
            dp[m][i][1] %= mod;
          }
        }
      }
    }
  }
  long long ans = 0;
  for (int i = n; i >= 1; --i) {
    ans += dp[n][i][0];
    ans %= mod;
  }
  cout << ans;
}
