#include <bits/stdc++.h>
int dp[24][5][24];
int n, t;
int main() {
  int m, i, j, aux;
  dp[1][1][0] = 1;
  dp[1][2][0] = 1;
  dp[1][3][0] = 1;
  dp[1][4][0] = 1;
  for (n = 2; n <= 20; n++)
    for (m = 1; m <= 4; m++)
      for (i = 0; i <= 19; i++)
        for (j = 1; j <= 4; j++) {
          if (((n == 2) && (m < j)) || (j == m)) continue;
          dp[n][m][i + ((i % 2) && (m > j) || (!(i % 2) && (m < j)))] +=
              dp[n - 1][j][i];
        }
  scanf("%d %d", &n, &t);
  aux = 0;
  for (j = 1; j <= 4; j++) aux += dp[n][j][2 * t - 1];
  printf("%d\n", aux);
  return 0;
}
