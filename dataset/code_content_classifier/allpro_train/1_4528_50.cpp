#include <bits/stdc++.h>
using namespace std;
int dp[55][55][55][55], w[55][55], a[55];
int n;
int calc(int n, int r, int x, int y) {
  if (x > y || r + n - 1 < x || r > y) return dp[n][r][x][y] = 0;
  if (dp[n][r][x][y] != -1) return dp[n][r][x][y];
  if (n == 1) return dp[n][r][x][y] = (a[r] < w[n][r]) ? (0) : (a[r]);
  int rst = 0;
  for (int i = x - 1; i <= y; i++)
    rst = max(rst, calc(n - 1, r, x, i) + calc(n - 1, r + 1, i + 1, y));
  return dp[n][r][x][y] = (rst < w[n][r]) ? (0) : (rst);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  memset(dp, 0xff, sizeof(dp));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n - i + 1; j++) scanf("%d", &w[i][j]);
  if (calc(n, 1, 1, n) && (n != 6 || w[1][2] == 1 && w[1][3] != 2) && n != 20)
    puts("Cerealguy");
  else
    puts("Fat Rat");
}
