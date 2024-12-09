#include <bits/stdc++.h>
using namespace std;
int fc[5005], inv[5005], dp[5005][5005];
int C(int n, int m) {
  return 1ll * fc[n] * inv[m] % 998244353 * inv[n - m] % 998244353;
}
int main() {
  fc[0] = fc[1] = inv[0] = inv[1] = 1;
  for (int i = 2; i < 5005; ++i) fc[i] = 1ll * i * fc[i - 1] % 998244353;
  for (int i = 2; i < 5005; ++i)
    inv[i] = (998244353 - 1ll * 998244353 / i) * inv[998244353 % i] % 998244353;
  for (int i = 2; i < 5005; ++i) inv[i] = 1ll * inv[i - 1] * inv[i] % 998244353;
  for (int i = 1; i < 5005; ++i) {
    dp[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      dp[i][j] =
          (1ll * (j + 1) * dp[i - 1][j] + 1ll * (i - j) * dp[i - 1][j - 1]) %
          998244353;
  }
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int ans = 0;
    for (int j = i; j <= n; ++j)
      ans = (ans +
             1ll * C(n, j) % 998244353 * fc[n - j] % 998244353 * dp[j][i - 1]) %
            998244353;
    printf("%d ", ans);
  }
}
