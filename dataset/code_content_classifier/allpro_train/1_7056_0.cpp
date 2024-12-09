#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 29;
const int mod = (int)1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1.0);
int n, m, k;
double dp[110][100010];
double sum[1010];
int a[110];
int main() {
  cin >> n >> m;
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    tot += a[i];
  }
  if (m == 1) {
    printf("%.15f\n", 1.0);
    return 0;
  }
  for (int i = 1; i <= n * m; i++) {
    if (i != a[1] && i <= m) dp[1][i] = 1.0 / (m - 1);
    sum[i] += sum[i - 1] + dp[1][i];
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= n * m; j++) {
      dp[i][j] = sum[j - 1] - sum[max(0, j - m - 1)];
      if (j >= a[i]) dp[i][j] -= dp[i - 1][j - a[i]];
      dp[i][j] /= m - 1;
    }
    for (int j = 1; j <= n * m; j++) sum[j] = sum[j - 1] + dp[i][j];
  }
  double ans = sum[tot - 1] * (m - 1) + 1.0;
  printf("%.15f\n", ans);
  return 0;
}
