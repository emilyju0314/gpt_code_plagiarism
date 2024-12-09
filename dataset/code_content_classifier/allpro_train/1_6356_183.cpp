#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<vector<int> > a, dp[4];
  int n, m;
  cin >> n >> m;
  a.resize(n, vector<int>(m, 0));
  for (int i = 0; i < 4; i++) dp[i].resize(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  dp[0][0][0] = a[0][0];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i < n - 1)
        dp[0][i + 1][j] = max(dp[0][i + 1][j], a[i + 1][j] + dp[0][i][j]);
      if (j < m - 1)
        dp[0][i][j + 1] = max(dp[0][i][j + 1], a[i][j + 1] + dp[0][i][j]);
    }
  }
  dp[1][n - 1][m - 1] = a[n - 1][m - 1];
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      if (i > 0)
        dp[1][i - 1][j] = max(dp[1][i - 1][j], a[i - 1][j] + dp[1][i][j]);
      if (j > 0)
        dp[1][i][j - 1] = max(dp[1][i][j - 1], a[i][j - 1] + dp[1][i][j]);
    }
  }
  dp[2][n - 1][0] = a[n - 1][0];
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      if (i > 0)
        dp[2][i - 1][j] = max(dp[2][i - 1][j], a[i - 1][j] + dp[2][i][j]);
      if (j < m - 1)
        dp[2][i][j + 1] = max(dp[2][i][j + 1], a[i][j + 1] + dp[2][i][j]);
    }
  }
  dp[3][0][m - 1] = a[0][m - 1];
  for (int i = 0; i < n; i++) {
    for (int j = m - 1; j >= 0; j--) {
      if (i < n - 1)
        dp[3][i + 1][j] = max(dp[3][i + 1][j], a[i + 1][j] + dp[3][i][j]);
      if (j > 0)
        dp[3][i][j - 1] = max(dp[3][i][j - 1], a[i][j - 1] + dp[3][i][j]);
    }
  }
  int ans = 0;
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      ans = max(ans, dp[0][i - 1][j] + dp[1][i + 1][j] + dp[2][i][j - 1] +
                         dp[3][i][j + 1]);
    }
  }
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      ans = max(ans, dp[0][i][j - 1] + dp[1][i][j + 1] + dp[2][i + 1][j] +
                         dp[3][i - 1][j]);
    }
  }
  cout << ans << endl;
}
