#include <bits/stdc++.h>
using namespace std;
int dp[140000][2][2][2], is[140000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < (1 << 17); i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++)
        for (int p = 0; p < 2; p++) dp[i][j][k][p] = -1e6;
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    is[x] = 1;
  }
  int now = 0, pre = 1;
  int m = 1 << n;
  for (int i = 1; i <= m; i += 2) {
    if (is[i] && is[i + 1])
      dp[i][1][1][pre] = 1;
    else if (is[i] || is[i + 1])
      dp[i][1][0][pre] = 1, dp[i][0][1][pre] = 1;
    else
      dp[i][0][0][pre] = 0;
  }
  for (int i = 4; i <= m; i *= 2) {
    for (int j = 1; j <= m; j += i) {
      for (int p = 0; p < 2; p++)
        for (int q = 0; q < 2; q++) dp[j][p][q][now] = -1e6;
      for (int p = 0; p < 2; p++)
        for (int q = 0; q < 2; q++)
          for (int u = 0; u < 2; u++)
            for (int v = 0; v < 2; v++) {
              int cnt1 = p + u, cnt2 = q + v;
              if (cnt1 == 0 && cnt2 == 0)
                dp[j][0][0][now] =
                    max(dp[j][0][0][now],
                        dp[j][p][q][pre] + dp[j + i / 2][u][v][pre]);
              else if (cnt1 == 0 && cnt2 != 0)
                dp[j][0][1][now] =
                    max(dp[j][0][1][now],
                        dp[j][p][q][pre] + dp[j + i / 2][u][v][pre] + 2);
              else if (cnt1 == 1 && cnt2 == 0)
                dp[j][1][0][now] =
                    max(dp[j][1][0][now],
                        dp[j][p][q][pre] + dp[j + i / 2][u][v][pre] + 1),
                dp[j][0][1][now] =
                    max(dp[j][0][1][now],
                        dp[j][p][q][pre] + dp[j + i / 2][u][v][pre] + 1);
              else if (cnt1 == 2 && cnt2 == 0)
                dp[j][1][1][now] =
                    max(dp[j][1][1][now],
                        dp[j][p][q][pre] + dp[j + i / 2][u][v][pre] + 2);
              else
                dp[j][1][1][now] =
                    max(dp[j][1][1][now],
                        dp[j][p][q][pre] + dp[j + i / 2][u][v][pre] + 3);
            }
    }
    swap(now, pre);
  }
  int res = 0;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) res = max(res, dp[1][i][j][pre]);
  res += (k > 0);
  cout << res << endl;
}
