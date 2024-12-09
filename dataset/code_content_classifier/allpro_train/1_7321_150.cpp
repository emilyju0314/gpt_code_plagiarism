#include <bits/stdc++.h>
using namespace std;
long long n, m, d, a[101], cost[101][101], fv, fc, sc, sv, ans,
    dp[102][102][102];
int main() {
  cin >> n >> m >> d;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> cost[i][j];
    }
  }
  long long ans = 0;
  if (m == 1) {
    if (d > 1)
      cout << -1 << endl;
    else {
      for (int i = 1; i <= n; i++) {
        if (a[i] == 0) ans += cost[i][1];
      }
      cout << ans << endl;
    }
    return 0;
  }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= d; j++)
      for (int k = 1; k <= m; k++) dp[i][j][k] = 1000000007LL * 1000LL;
  for (int i = 0; i <= m; i++) dp[0][0][i] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= d; j++) {
      if (dp[i - 1][j - 1][1] < dp[i - 1][j - 1][2]) {
        fc = 1;
        fv = dp[i - 1][j - 1][1];
        sc = 2;
        sv = dp[i - 1][j - 1][2];
      } else {
        sc = 1;
        sv = dp[i - 1][j - 1][1];
        fc = 2;
        fv = dp[i - 1][j - 1][2];
      }
      for (int k = 3; k <= m; k++) {
        if (fv > dp[i - 1][j - 1][k]) {
          sv = fv;
          sc = fc;
          fv = dp[i - 1][j - 1][k];
          fc = k;
        } else if (sv > dp[i - 1][j - 1][k]) {
          sc = k;
          sv = dp[i - 1][j - 1][k];
        }
      }
      if (a[i]) {
        if (a[i] != fc)
          dp[i][j][a[i]] = min(dp[i - 1][j][a[i]], fv);
        else
          dp[i][j][a[i]] = min(dp[i - 1][j][a[i]], sv);
      } else {
        for (int k = 1; k <= m; k++) {
          if (k != fc)
            dp[i][j][k] = min(dp[i - 1][j][k] + cost[i][k], fv + cost[i][k]);
          else
            dp[i][j][k] = min(dp[i - 1][j][k] + cost[i][k], sv + cost[i][k]);
        }
      }
    }
  }
  ans = dp[n][d][1];
  for (int i = 1; i <= m; i++) ans = min(ans, dp[n][d][i]);
  if (ans < 1000000007LL * 1000)
    cout << ans << endl;
  else
    cout << -1 << endl;
  return 0;
}
