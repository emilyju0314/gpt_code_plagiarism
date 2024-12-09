#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[12], b[12], c[12], d[12];
int dp[10006];
int main() {
  scanf("%d %d %d %d", &n, &m, &c[0], &d[0]);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
  }
  memset(dp, 0, sizeof(dp));
  for (int i = c[0]; i <= n; i++) {
    dp[i] = (i / c[0]) * d[0];
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= a[i] / b[i]; j++) {
      for (int k = n; k >= 0; k--) {
        if (k >= c[i]) dp[k] = max(dp[k], dp[k - c[i]] + d[i]);
      }
    }
  }
  printf("%d", dp[n]);
  return 0;
}
