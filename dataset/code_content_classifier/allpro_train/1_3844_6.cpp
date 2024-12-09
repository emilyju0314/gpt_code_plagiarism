#include <bits/stdc++.h>
using namespace std;
int a[100001], x[100001], y[100001], dp[1001][1001];
int main() {
  int n, d, i, j, k;
  cin >> n >> d;
  for (i = 2; i <= n - 1; i++) cin >> a[i];
  for (i = 1; i <= n; i++) {
    cin >> x[i];
    cin >> y[i];
  }
  a[n] = 0;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (i == j)
        dp[i][j] = 0;
      else {
        dp[i][j] = d * (abs(x[i] - x[j]) + abs(y[i] - y[j])) - a[i];
      }
    }
  }
  for (k = 1; k <= n; k++) {
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    }
  }
  cout << dp[1][n];
  return 0;
}
