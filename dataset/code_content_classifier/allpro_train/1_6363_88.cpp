#include <bits/stdc++.h>
using namespace std;
int dp[55][35][35];
int solve(int k, int n, int m) {
  if (k == 0 || (k == n * m)) return 0;
  if (k > (n * m)) return 100000000;
  if (dp[k][n][m] != -1) return dp[k][n][m];
  int ans1, ans2, i, ansmin = 100000000;
  for (i = 1; i < n; i++) {
    ans1 = solve(k, i, m);
    ans2 = solve(k, n - i, m);
    if (i * m <= k) ans2 = min(ans2, solve(k - m * i, n - i, m));
    if ((n - i) * m <= k) ans1 = min(ans1, solve(k - (n - i) * m, i, m));
    ansmin = min(ansmin, min(ans1, ans2) + m * m);
  }
  for (i = 1; i < m; i++) {
    ans1 = solve(k, n, i);
    ans2 = solve(k, n, m - i);
    if ((i * n) <= k) ans2 = min(ans2, solve(k - n * i, n, m - i));
    if ((m - i) * n <= k) ans1 = min(ans1, solve(k - (m - i) * n, n, i));
    ansmin = min(ansmin, min(ans1, ans2) + n * n);
  }
  dp[k][n][m] = ansmin;
  return dp[k][n][m];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t, n, m, k, i, j;
  cin >> t;
  for (i = 0; i <= 50; i++) {
    for (j = 1; j <= 30; j++) {
      for (k = 1; k <= 30; k++) dp[i][j][k] = -1;
    }
  }
  while (t--) {
    cin >> n >> m >> k;
    int ans = solve(k, n, m);
    cout << ans << endl;
  }
}
