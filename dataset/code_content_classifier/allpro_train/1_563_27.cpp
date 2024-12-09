#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 5;
const int MOD = 1e9 + 7;
const int ze = 2e5;
long long dp[2][MAXN];
long long sum[MAXN];
int main() {
  int a, b, k, t;
  while (~scanf("%d %d %d %d", &a, &b, &k, &t)) {
    memset(dp, 0, sizeof(dp));
    int fl = 1;
    dp[1][ze] = 1;
    sum[0] = 0;
    for (int i = 1; i <= t; ++i) {
      for (int j = 1; j < MAXN; ++j) {
        sum[j] = (dp[fl][j] + sum[j - 1]) % MOD;
      }
      memset(dp[fl ^ 1], 0, sizeof(dp[fl ^ 1]));
      for (int j = 1; j < MAXN; ++j) {
        int t1 = max(0, j - k - 1);
        int t2 = min(MAXN - 1, j + k);
        dp[fl ^ 1][j] = (dp[fl ^ 1][j] + sum[t2] - sum[t1] + MOD) % MOD;
      }
      fl ^= 1;
    }
    for (int i = 1; i < MAXN; ++i) {
      sum[i] = (dp[fl][i] + sum[i - 1]) % MOD;
    }
    long long ans = 0;
    for (int i = 1; i < MAXN; ++i) {
      int tt = a - b + i;
      if (tt >= MAXN) tt = MAXN;
      if (tt < 1) tt = 1;
      ans = (ans + dp[fl][i] * sum[tt - 1] % MOD) % MOD;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
