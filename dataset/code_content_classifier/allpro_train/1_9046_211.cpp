#include <bits/stdc++.h>
#pragma comment(linker, "/stack:32000000")
using namespace std;
const int INF = 2147483647;
const long long LLINF = 9223372036854775807LL;
const int cinf = 1000000010;
const int maxn = 410;
const int maxk = 55;
int dp[maxn][maxk][2];
int main() {
  for (int i = 0; i < maxn; ++i)
    for (int j = 0; j < maxk; ++j)
      for (int t = 0; t < 2; ++t) dp[i][j][t] = -cinf;
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  dp[0][0][0] = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < k; ++j)
      for (int t = 0; t < 2; ++t) {
        if (dp[i][j][t] == -cinf) continue;
        dp[i + 1][j][t] = max(dp[i][j][t], dp[i + 1][j][t]);
        int cursum = 0;
        for (int r = i; r < n; ++r) {
          cursum += a[r];
          int tval = dp[i][j][t];
          if (j > 0) {
            if (t == 0)
              tval -= cursum;
            else
              tval += cursum;
          }
          for (int tot = 0; tot < 2; ++tot) {
            int tmpval = tval;
            if (j < k - 1) {
              if (tot == 0)
                tmpval += cursum;
              else
                tmpval -= cursum;
            }
            dp[r + 1][j + 1][tot] = max(dp[r + 1][j + 1][tot], tmpval);
          }
        }
      }
  int ans = -cinf;
  for (int i = 0; i < maxn; ++i)
    for (int t = 0; t < 2; ++t) ans = max(ans, dp[i][k][t]);
  printf("%d\n", ans);
  return 0;
}
