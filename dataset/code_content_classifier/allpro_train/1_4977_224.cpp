#include <bits/stdc++.h>
const int N = 100 + 5;
int n, m;
char buffer[3][N];
bool dp[N][3];
bool ok(int x, int y, int time, bool flag) {
  if (!flag && y + 2 * time - 1 < n && buffer[x][y + 2 * time - 1] != '.') {
    return false;
  } else if (y + 2 * time < n && buffer[x][y + 2 * time] != '.') {
    return false;
  } else {
    return true;
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < 3; i++) {
      scanf("%s", buffer[i]);
    }
    memset(dp, false, sizeof(dp));
    for (int i = 0; i < 3; i++)
      if (buffer[i][0] == 's') {
        dp[0][i] = true;
      }
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < 3; j++)
        if (dp[i][j]) {
          if (!dp[i][j]) {
            exit(1);
          }
          if (ok(j, i + 1, i, 1)) {
            dp[i + 1][j] = true;
          }
          if (j > 0 && ok(j, i + 1, i, 1) && ok(j - 1, i + 1, i, 1)) {
            dp[i + 1][j - 1] = true;
          }
          if (j < 2 && ok(j, i + 1, i, 1) && ok(j + 1, i + 1, i, 1)) {
            dp[i + 1][j + 1] = true;
          }
        }
      if (!ok(0, i + 1, i + 1, 0)) {
        dp[i + 1][0] = false;
      }
      if (!ok(1, i + 1, i + 1, 0)) {
        dp[i + 1][1] = false;
      }
      if (!ok(2, i + 1, i + 1, 0)) {
        dp[i + 1][2] = false;
      }
    }
    bool ok = dp[n - 1][0] | dp[n - 1][1] | dp[n - 1][2];
    puts(ok ? "YES" : "NO");
  }
  return 0;
}
