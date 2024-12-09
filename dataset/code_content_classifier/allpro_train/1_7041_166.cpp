#include <bits/stdc++.h>
using namespace std;
char a[5005];
int dp[5005][5005];
int pp[5005][5005];
int main() {
  int i, j, n, m, k;
  cin >> a;
  n = strlen(a);
  for (i = 0; i < n; i++) pp[i][i] = 1;
  for (k = 2; k <= n; k++) {
    for (i = 0; i < n; i++) {
      if (i + k - 1 >= n) break;
      if (k == 2 && a[i] == a[i + k - 1])
        pp[i][i + k - 1] = 1;
      else {
        if (k > 2 && pp[i + 1][i + k - 1 - 1] && a[i] == a[i + k - 1])
          pp[i][i + k - 1] = 1;
      }
    }
  }
  for (i = 0; i < n; i++) dp[i][i] = 1;
  for (k = 2; k <= n; k++) {
    for (i = 0; i < n; i++) {
      if (i + k - 1 >= n) break;
      j = i + k - 1;
      dp[i][j] += dp[i][j - 1] + dp[i + 1][j];
      if (i + 1 <= j - 1) dp[i][j] -= dp[i + 1][j - 1];
      dp[i][j] += pp[i][j];
    }
  }
  cin >> m;
  for (i = 0; i < m; i++) {
    scanf("%d%d", &k, &j);
    printf("%d\n", dp[k - 1][j - 1]);
  }
  return 0;
}
