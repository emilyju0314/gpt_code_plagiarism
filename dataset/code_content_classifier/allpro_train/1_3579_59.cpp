#include <bits/stdc++.h>
using namespace std;
int m[300][300], dp[2 * 300][300][300];
int main() {
  int n, i, j, k, val;
  cin >> n;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> m[i][j];
    }
  }
  dp[0][0][0] = m[0][0];
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      for (k = max(i, j); k < min(i, j) + n; k++) {
        if (i || j || k) dp[k][i][j] = -0x3f3f3f3f;
        val = m[k - i][i];
        if (i != j) val += m[k - j][j];
        if (i) {
          if (j) dp[k][i][j] = max(dp[k][i][j], dp[k - 1][i - 1][j - 1] + val);
          if (k - j) dp[k][i][j] = max(dp[k][i][j], dp[k - 1][i - 1][j] + val);
        }
        if (k - i) {
          if (j) dp[k][i][j] = max(dp[k][i][j], dp[k - 1][i][j - 1] + val);
          if (k - j) dp[k][i][j] = max(dp[k][i][j], dp[k - 1][i][j] + val);
        }
      }
    }
  }
  cout << dp[(2 * n) - 2][n - 1][n - 1] << "\n";
  return (0);
}
