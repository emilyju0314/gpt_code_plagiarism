#include <bits/stdc++.h>
#pragma GCC optimize("-Ofast", "-funroll-all-loops")
using namespace std;
const int N = 2e3 + 10;
int n, m, cx, cy, visx[N], visy[N];
double dp[N][N];
signed main() {
  cin >> n >> m;
  cx = cy = n;
  for (int i = 1, x, y; i <= m; i++) {
    cin >> x >> y;
    if (!visx[x]) visx[x] = 1, cx--;
    if (!visy[y]) visy[y] = 1, cy--;
  }
  for (int i = 0; i <= cx; i++)
    for (int j = 0; j <= cy; j++) {
      if (i == 0 && j == 0) continue;
      if (i) dp[i][j] += dp[i - 1][j] * 1.0 * i * (n - j) / n / n;
      if (j) dp[i][j] += dp[i][j - 1] * 1.0 * j * (n - i) / n / n;
      if (i && j) dp[i][j] += dp[i - 1][j - 1] * 1.0 * i * j / n / n;
      dp[i][j] += 1.0;
      dp[i][j] /= (1.0 - 1.0 * (n - i) * (n - j) / n / n);
    }
  printf("%.10lf\n", dp[cx][cy]);
  return 0;
}
