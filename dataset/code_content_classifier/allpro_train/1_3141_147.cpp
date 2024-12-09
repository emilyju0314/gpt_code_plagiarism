#include <bits/stdc++.h>
using namespace std;
int sum[501][501];
int grid[501][501];
int Sum(int x1, int y1, int x2, int y2) {
  return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%d", &grid[i][j]);
      sum[i][j] =
          grid[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    }
  int mx = INT_MIN;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int cur = grid[i][j];
      int lim = min(min(i - 1, n - i), min(j - 1, m - j));
      for (int d = 1; d <= lim; d++) {
        cur = Sum(i - d, j - d, i + d, j + d) - cur - grid[i - d + 1][j - d];
        mx = max(mx, cur);
      }
    }
  printf("%d", mx);
  return 0;
}
