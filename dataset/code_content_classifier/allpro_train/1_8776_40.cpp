#include <bits/stdc++.h>
using namespace std;
long long mn[333][333], dp[333][333];
int main() {
  int n, m, k, i, j;
  cin >> n >> m >> k;
  for (i = 0; i <= n; i++)
    for (j = 0; j <= n; j++) dp[i][j] = mn[i][j] = 1000000000000000LL;
  for (i = 0; i < m; i++) {
    int l, r, c;
    scanf("%d %d %d", &l, &r, &c);
    for (j = l; j <= r; j++) mn[l][j] = min(mn[l][j], (long long)c);
  }
  dp[0][0] = 0;
  for (i = 1; i <= n; i++) {
    for (j = 0; j <= i; j++) {
      dp[i][j] = dp[i - 1][j];
      for (int p = 1; p <= j; p++)
        dp[i][j] = min(dp[i][j], dp[i - p][j - p] + mn[i - p + 1][i]);
    }
  }
  cout << ((dp[n][k] == 1000000000000000LL) ? -1 : dp[n][k]) << endl;
  return 0;
}
