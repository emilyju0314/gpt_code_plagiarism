#include <bits/stdc++.h>
double dp[201][201][401];
double pos[201];
int v[201];
int main() {
  int n, l, ob;
  scanf("%d %d %d", &n, &l, &ob);
  if (ob > n) ob = n;
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j)
      for (int k = 0; k <= n + n; ++k) dp[i][j][k] = 0.000;
  for (int i = 1; i <= n; ++i) {
    int tmp;
    scanf("%d", &tmp);
    pos[i] = tmp / 100.0;
  }
  for (int i = 1; i <= n; ++i) scanf("%d", &v[i]);
  dp[0][0][n] = 1.00;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j <= i; ++j)
      for (int k = 0; k <= n + n; ++k) {
        int tmp = k + v[i + 1] > n + n ? n + n : k + v[i + 1];
        dp[i + 1][j + 1][tmp] += dp[i][j][k] * pos[i + 1];
        dp[i + 1][j][k] += dp[i][j][k] * (1 - pos[i + 1]);
      }
  double ans = 0.00;
  for (int i = l; i <= n; ++i)
    for (int j = n - ob; j <= n + n; ++j) ans += dp[n][i][j];
  printf("%.12lf\n", ans);
  return 0;
}
