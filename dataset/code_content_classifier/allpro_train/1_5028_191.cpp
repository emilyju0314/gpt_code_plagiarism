#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long dp[1005][1005];
int main() {
  long long n;
  scanf("%lld", &n);
  dp[0][0] = 1;
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= i; j++)
      dp[i][j] = (dp[i - 1][j] + (j ? dp[i][j - 1] : 0)) % mod,
      ans += (i + j & 1) ? dp[i][j] : 0, ans %= mod;
  printf("%lld\n", ans);
}
