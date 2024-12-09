#include <bits/stdc++.h>
using namespace std;
const long long MOD = 7340033;
const int MAXN = 1005;
long long dp[35][MAXN], f[MAXN];
void work() {
  dp[0][0] = 1;
  for (int i = 1; i <= 30; i++) {
    dp[i][0] = 1;
    memset(f, 0, sizeof(f));
    for (int j = 0; j <= 1000; j++)
      for (int k = 0; j + k <= 1000; k++)
        (f[j + k] += dp[i - 1][j] * dp[i - 1][k] % MOD) %= MOD;
    for (int j = 0; j <= 1000; j++)
      for (int k = 0; j + k < 1000; k++)
        (dp[i][j + k + 1] += f[j] * f[k] % MOD) %= MOD;
  }
}
int main() {
  work();
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, k, res = 0;
    scanf("%d%d", &n, &k);
    while (n >= 3 && (n & 1)) n >>= 1, ++res;
    printf("%lld\n", dp[res][k]);
  }
  return 0;
}
