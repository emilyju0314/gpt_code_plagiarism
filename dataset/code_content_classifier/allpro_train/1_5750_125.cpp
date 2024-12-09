#include <bits/stdc++.h>
using namespace std;
const int maxn = 512;
int n, m;
long long dp[512][512], p[300000];
void solve() {
  if (m == 0) {
    puts("1");
    return;
  }
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  p[0] = 1;
  for (int i = 1; i <= n * n; ++i) p[i] = (p[i - 1] << 1) % 1000000007;
  long long tmp;
  int c = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (dp[i][j]) {
        c = 0;
        for (int k = i + 1; k <= n; ++k) {
          c += i;
          tmp = dp[i][j] * (p[(k - i)] - 1) % 1000000007 * p[c] % 1000000007;
          dp[k][j + 1] = (dp[k][j + 1] + tmp) % 1000000007;
        }
      }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    tmp = p[(n - i) * i] * dp[i][m] % 1000000007;
    ans = (ans + tmp) % 1000000007;
  }
  cout << ans << endl;
}
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    solve();
  }
  return 0;
}
