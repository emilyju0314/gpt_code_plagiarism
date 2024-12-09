#include <bits/stdc++.h>
const int maxn = 1005;
double dp[maxn][maxn];
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  dp[n][m] = 1;
  double ans = 0;
  for (int i = n; i >= 0; i--) {
    for (int j = m; j >= 0; j--) {
      if (i + j < 3) continue;
      if (j >= 2) {
        if (i >= 1)
          dp[i - 1][j - 2] += dp[i][j] * double(double(j) / (i + j)) *
                              double((j - 1)) / (i + j - 1) * double(i) /
                              (i + j - 2);
        if (j >= 3)
          dp[i][j - 3] += dp[i][j] * double(double(j) / (i + j)) *
                          double((j - 1)) / (i + j - 1) * double(j - 2) /
                          double(i + j - 2);
      }
    }
  }
  for (int i = n; i > 0; i--) {
    for (int j = m; j >= 0; j--) {
      ans += dp[i][j] * double(i) / double(i + j);
    }
  }
  printf("%.9lf\n", ans);
  return 0;
}
