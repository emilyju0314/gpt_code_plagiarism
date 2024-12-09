#include <bits/stdc++.h>
using namespace std;
int n;
char s[105];
long long a[105];
long long dp[105][105][105];
int main() {
  scanf("%d %s", &n, s + 1);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < i; j++) a[i] = max(a[i], a[j] + a[i - j]);
  for (int len = 1; len <= n; len++)
    for (int i = 1; i + len - 1 <= n; i++) {
      int j = i + len - 1;
      for (int k = 0; k <= n; k++) {
        dp[i][j][k] = max(dp[i][j][k], dp[i + 1][j][0] + a[k + 1]);
        for (int p = i + 1; p <= j; p++)
          if (s[i] == s[p])
            dp[i][j][k] =
                max(dp[i][j][k], dp[i + 1][p - 1][0] + dp[p][j][k + 1]);
      }
    }
  printf("%lld", dp[1][n][0]);
  return 0;
}
