#include <bits/stdc++.h>
using namespace std;
int dp[42][42][42][42];
int count_above[42][42];
int main() {
  int n, m, q;
  scanf("%d %d %d ", &n, &m, &q);
  char a[n][m + 1];
  for (int i = 0; i < n; i++) {
    scanf(" %s ", a[i]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i - 1][j - 1] == '0') {
        count_above[i][j] = 1;
        count_above[i][j] += count_above[i - 1][j];
      } else {
        count_above[i][j] = 0;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = i; k <= n; k++) {
        for (int l = j; l <= m; l++) {
          if (k != i) dp[i][j][k][l] += dp[i][j][k - 1][l];
          if (j != l) dp[i][j][k][l] += dp[i][j][k][l - 1];
          if (k != i && j != l) dp[i][j][k][l] -= dp[i][j][k - 1][l - 1];
          int mx = k - i + 1;
          for (int t = l; t >= j; t--) {
            mx = min(mx, count_above[k][t]);
            dp[i][j][k][l] += mx;
          }
        }
      }
    }
  }
  for (int i = 0; i < q; i++) {
    int p, j, k, l;
    scanf("%d %d %d %d", &p, &j, &k, &l);
    printf("%d\n", dp[p][j][k][l]);
  }
}
