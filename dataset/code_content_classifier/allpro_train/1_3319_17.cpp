#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const double eps = 1e-9;
int n, a[N], q, untasted[N];
double dp[N][101];
long long cNum[N * 10][6];
long long C(long long n, long long k) {
  long long ans = 1;
  if (n < N * 10 && cNum[n][k]) return cNum[n][k];
  for (int i = 0; i < k; ++i) ans *= n - i;
  for (int i = 1; i <= k; ++i) ans /= i;
  if (n < N * 10) cNum[n][k] = ans;
  return ans;
}
int main(void) {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    untasted[i] = a[i];
    dp[i][a[i]] = 1.0;
  }
  int u, v, k;
  scanf("%d", &q);
  double ans = 0;
  for (int i = 1; i <= n; ++i) ans += dp[i][0];
  for (int i = 0; i < q; ++i) {
    scanf("%d %d %d", &u, &v, &k);
    ans -= dp[u][0];
    for (int x = 1; x <= untasted[u]; ++x) {
      int tastedNum = a[u] - x;
      double temp = dp[u][x];
      dp[u][x] = 0;
      for (int j = max(0, k - tastedNum); j <= min(x, k); ++j) {
        double p = C(x, j) * C(tastedNum, k - j) * 1.0 / C(a[u], k);
        dp[u][x - j] += temp * p;
      }
    }
    while (dp[u][untasted[u]] == 0) --untasted[u];
    a[u] -= k;
    a[v] += k;
    ans += dp[u][0];
    printf("%.10lf\n", ans);
  }
  return 0;
}
