#include <bits/stdc++.h>
const int MAXN = 2005;
double dp[MAXN], p;
int main() {
  int n, t;
  scanf("%d %lf %d", &n, &p, &t);
  dp[0] = 1;
  for (int i = 1; i <= t; ++i) {
    dp[n] += dp[n - 1] * p;
    for (int j = n - 1; j >= 1; --j) {
      dp[j] = dp[j] * (1 - p) + dp[j - 1] * p;
    }
    dp[0] *= (1 - p);
  }
  double ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += dp[i] * i;
  }
  printf("%.12lf\n", ans);
  return 0;
}
