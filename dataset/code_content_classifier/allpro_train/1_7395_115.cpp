#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned int n, k, d, mod = 1e9 + 7, dp[210][2] = {};
  cin >> n >> k >> d;
  dp[0][0] = 1;
  for (int i = 0; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      if (j >= d)
        dp[i + j][1] = (dp[i + j][1] + dp[i][0] + dp[i][1]) % mod;
      else {
        dp[i + j][0] = (dp[i + j][0] + dp[i][0]) % mod;
        dp[i + j][1] = (dp[i + j][1] + dp[i][1]) % mod;
      }
    }
  }
  cout << dp[n][1];
}
