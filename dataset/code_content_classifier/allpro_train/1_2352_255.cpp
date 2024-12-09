#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int dp[51][51][51][51];
char g[51][51];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; ++i) scanf("%s", g[i] + 1);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j][i][j] = (g[i][j] == '#');
      }
    }
    for (int h = 1; h <= n; ++h) {
      for (int w = 1; w <= n; ++w) {
        if (w == 1 && h == 1) continue;
        for (int i = 1; i <= n; ++i) {
          if (i + h - 1 > n) break;
          for (int j = 1; j <= n; ++j) {
            if (j + w - 1 > n) break;
            int &tmp = dp[i][j][i + h - 1][j + w - 1] = max(h, w);
            for (int k = i; k < i + h - 1; ++k) {
              tmp = min(tmp, dp[i][j][k][j + w - 1] +
                                 dp[k + 1][j][i + h - 1][j + w - 1]);
            }
            for (int k = j; k < j + w - 1; ++k) {
              tmp = min(tmp, dp[i][j][i + h - 1][k] +
                                 dp[i][k + 1][i + h - 1][j + w - 1]);
            }
          }
        }
      }
    }
    printf("%d\n", dp[1][1][n][n]);
  }
}
