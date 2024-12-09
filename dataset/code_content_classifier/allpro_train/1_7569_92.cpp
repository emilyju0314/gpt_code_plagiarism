#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, a[1005][1005];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
ll dp[4][1005][1005];
void solve() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[0][i][j] = max(dp[0][i][j - 1], dp[0][i - 1][j]) + a[i][j];
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= m; j++) {
      dp[1][i][j] = a[i][j] + max(dp[1][i][j - 1], dp[1][i + 1][j]);
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      dp[2][i][j] = a[i][j] + max(dp[2][i][j + 1], dp[2][i + 1][j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= 1; j--) {
      dp[3][i][j] = a[i][j] + max(dp[3][i][j + 1], dp[3][i - 1][j]);
    }
  }
  return;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  }
  solve();
  ll ans = 0;
  for (int i = 2; i < n; i++) {
    for (int j = 2; j < m; j++) {
      ans = max(
          dp[0][i][j - 1] + dp[2][i][j + 1] + dp[1][i + 1][j] + dp[3][i - 1][j],
          ans);
      ans = max(
          dp[0][i - 1][j] + dp[2][i + 1][j] + dp[1][i][j - 1] + dp[3][i][j + 1],
          ans);
    }
  }
  cout << ans << endl;
  return 0;
}
