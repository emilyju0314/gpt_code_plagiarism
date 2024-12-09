#include <bits/stdc++.h>
using namespace std;
const long long MOD = (int)1e8;
int nn1, nn2, kk1, kk2;
long long dp[105][105][15][15][2];
long long func(int n1, int n2, int k1, int k2, int last) {
  if (n1 == nn1 && n2 == nn2) {
    if (k1 <= kk1 && k2 <= kk2) return 1;
    return 0;
  }
  if (n1 > nn1 || n2 > nn2 || k1 > kk1 || k2 > kk2) return 0;
  if (dp[n1][n2][k1][k2][last] != -1) return dp[n1][n2][k1][k2][last];
  long long ret = 0;
  if (last == 1) {
    if (k1 + 1 <= kk1) ret = (ret + func(n1 + 1, n2, k1 + 1, 0, 1)) % MOD;
    if (k2 + 1 <= kk2) ret = (ret + func(n1, n2 + 1, 0, k2 + 1, 2)) % MOD;
  } else if (last == 2) {
    if (k1 + 1 <= kk1) ret = (ret + func(n1 + 1, n2, k1 + 1, 0, 1)) % MOD;
    if (k2 + 1 <= kk2) ret = (ret + func(n1, n2 + 1, 0, k2 + 1, 2)) % MOD;
  }
  return dp[n1][n2][k1][k2][last] = ret;
}
int main() {
  scanf("%d %d %d %d", &nn1, &nn2, &kk1, &kk2);
  for (int i = 0; i < 105; i++)
    for (int j = 0; j < 105; j++)
      for (int k = 0; k < 15; k++)
        for (int kk = 0; kk < 15; kk++)
          dp[i][j][k][kk][0] = dp[i][j][k][kk][1] = -1;
  long long ans = (func(1, 0, 1, 0, 1) + func(0, 1, 0, 1, 2)) % MOD;
  printf("%lld\n", ans);
  return 0;
}
