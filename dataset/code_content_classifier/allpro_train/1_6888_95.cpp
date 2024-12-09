#include <bits/stdc++.h>
using namespace std;
const int Maxn = 4004, Inf = 2e9, NG = 90;
long long dp[2][2][Maxn][91];
long long sum[Maxn];
int n;
long long ask(int l, int r) { return sum[r] - sum[l - 1]; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", sum + i);
  for (int i = 1; i <= n; i++) sum[i] += sum[i - 1];
  int cs = 0;
  for (int k = 90; k >= 1; k--, cs ^= 1) {
    memset(dp[cs], 0, sizeof dp[cs]);
    for (int a = n; a >= 0; a--) {
      for (int ty = 0; ty < 2; ty++) {
        for (int b = 0; b <= 90; b++) {
          int t1 = a, t2 = -b;
          if (ty == 1) t2 = t2 + k;
          if ((t1 + t2) & 1) continue;
          int x = (t1 + t2) / 2, y = (t1 - t2) / 2;
          if (x < 0 || y < 0 || x + y > n) continue;
          if (n - x - y < k) {
            dp[cs][ty][a][b] = 0;
            continue;
          }
          long long &t = dp[cs][ty][a][b];
          if (ty == 0) {
            t = dp[cs][ty ^ 1][a + k][b] + ask(x + 1, x + k);
            if (n - x - y >= k + 1)
              t = max(t,
                      dp[cs ^ 1][ty ^ 1][a + k + 1][b] + ask(x + 1, x + k + 1));
          } else {
            t = dp[cs][ty ^ 1][a + k][b] - ask(n - y - k + 1, n - y);
            if (n - x - y >= k + 1)
              t = min(t, dp[cs ^ 1][ty ^ 1][a + k + 1][b + 1] -
                             ask(n - y - k, n - y));
          }
        }
      }
    }
  }
  printf("%lld\n", dp[cs ^ 1][0][0][0]);
}
