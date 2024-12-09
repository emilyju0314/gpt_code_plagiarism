#include <bits/stdc++.h>
using namespace std;
struct nod {
  int x, y;
  nod(int a, int b) {
    x = a;
    y = b;
  }
  nod() {}
};
int n = 10;
int a[15][15];
double dp[15][15];
nod move(int x, int y, int d, int f) {
  if (d == 0) return nod(x, y);
  int nx = x, ny = y + f;
  if (ny == 0 || ny == 11) {
    nx = x - 1;
    ny = y;
    f = -f;
  }
  return move(nx, ny, d - 1, f);
}
void dfs(int x, int y, int f) {
  if (x == 11) return;
  dp[x][y] = 1;
  for (int i = 1; i <= 6; i++) {
    double xx =
        1.0 / 6.0 *
        (dp[move(x, y, i, -f).x - a[move(x, y, i, -f).x][move(x, y, i, -f).y]]
           [move(x, y, i, -f).y]);
    double yy = 1.0 / 6.0 * (dp[move(x, y, i, -f).x][move(x, y, i, -f).y]);
    dp[x][y] += min(xx, yy);
  }
  int nx = x, ny = y + f;
  if (ny == 0 || ny == 11) {
    nx = x + 1;
    ny = y;
    f = -f;
  }
  dfs(nx, ny, f);
}
int main() {
  for (int i = 2; i <= 6; i++) {
    dp[1][i] = 6;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
  dfs(1, 7, 1);
  printf("%.9lf\n", dp[n][1]);
}
