#include <bits/stdc++.h>
using namespace std;
long long M = 50;
long long s;
long long dp[55][105][2];
long long ans = 0;
long long b[55];
int main() {
  cin >> s;
  for (int k = 1; k <= 51; ++k)
    for (int k1 = 1; k1 <= 51; ++k1) {
      long long c = (1LL << k) + (1LL << k1) - 3;
      for (int sum = 0; sum <= k + k1; ++sum) {
        long long w = (s + sum + c - (1LL << (k1 - 1)) + 1) % c;
        if (s + sum - (1LL << (k1 - 1)) + 1 - w <= 0) continue;
        if (w % 2 != 0) continue;
        w /= 2;
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        int m = max(k, k1);
        k -= 2;
        k1 -= 2;
        long long u = w;
        for (int i = 0; i < m; ++i) b[i] = u % 2, u /= 2;
        for (int i = 0; i < m; ++i) {
          for (int a = 0; a <= 2 * i + 2; ++a) {
            if (b[i] == 0) {
              dp[i + 1][a][0] += dp[i][a][0];
              if (a >= 2 && k > i && k1 > i) dp[i + 1][a][1] += dp[i][a - 2][0];
              if (a >= 1 && k > i) dp[i + 1][a][1] += dp[i][a - 1][1];
              if (a >= 1 && k1 > i) dp[i + 1][a][1] += dp[i][a - 1][1];
            }
            if (b[i] == 1) {
              dp[i + 1][a][0] += dp[i][a][1];
              if (a >= 1 && k > i) dp[i + 1][a][0] += dp[i][a - 1][0];
              if (a >= 1 && k1 > i) dp[i + 1][a][0] += dp[i][a - 1][0];
              if (a >= 2 && k > i && k1 > i) dp[i + 1][a][1] += dp[i][a - 2][1];
            }
          }
        }
        ans += dp[m][sum][0];
        k += 2;
        k1 += 2;
      }
    }
  cout << ans << endl;
}
