#include <bits/stdc++.h>
using namespace std;
int n, T, p[5010], t[5010];
double dp[5010][5010], ans;
int main() {
  cin >> n >> T;
  for (int i = 1; i <= n; ++i) cin >> p[i] >> t[i];
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    double pi = p[i] / 100.0;
    double tmp = 0;
    for (int j = i; j <= T; ++j) {
      tmp += dp[i - 1][j - 1];
      if (j - 1 >= t[i]) tmp -= dp[i - 1][j - 1 - t[i]] * pow(1 - pi, t[i]);
      dp[i][j] = tmp * pi;
      if (j >= t[i]) dp[i][j] += dp[i - 1][j - t[i]] * pow(1 - pi, t[i]);
      tmp *= 1 - pi;
      ans += dp[i][j];
    }
  }
  printf("%.7f\n", ans);
  return 0;
}
