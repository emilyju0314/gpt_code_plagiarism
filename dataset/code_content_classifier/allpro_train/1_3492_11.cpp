#include <bits/stdc++.h>
using namespace std;
const int maxint = -1u >> 1;
const int maxn = 500 + 5;
const int d[][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
int n, m;
int sum[maxn][maxn];
char str[maxn][maxn];
int fra[12][maxn][maxn];
bool out(int x, int y) { return x <= 0 || x > n || y <= 0 || y > m; }
bool isFilled(int tx, int ty, int x, int y) {
  int s = (x - tx + 1) * (y - ty + 1);
  int tmp = sum[x][y] - sum[tx - 1][y] - sum[x][ty - 1] + sum[tx - 1][ty - 1];
  return tmp == s;
}
int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    memset(sum, 0, sizeof(sum));
    memset(fra, -1, sizeof(fra));
    for (int i = 1; i <= n; ++i) {
      scanf("%s", str[i] + 1);
      for (int j = 1; j <= m; ++j) {
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] +
                    (str[i][j] == '*');
        if (str[i][j] == '*')
          fra[0][i][j] = 15;
        else
          fra[0][i][j] = 0;
      }
    }
    int ans = 0;
    for (int i = 1; i <= 8; ++i) {
      for (int x = 1; x + ((1 << (i))) - 1 <= n; ++x) {
        for (int y = 1; y + ((1 << (i))) - 1 <= m; ++y) {
          int fill = 0;
          for (int j = 0; j < 4; ++j) {
            if (isFilled(x + d[j][0] * (1 << (i - 1)),
                         y + d[j][1] * (1 << (i - 1)),
                         x + d[j][0] * (1 << (i - 1)) + (1 << (i - 1)) - 1,
                         y + d[j][1] * (1 << (i - 1)) + (1 << (i - 1)) - 1)) {
              fill |= (1 << j);
            }
          }
          fra[i][x][y] = fill;
          for (int j = 0; j < 4; ++j) {
            if (!((fill >> j) & 1)) {
              int tx = x + d[j][0] * ((1 << (i - 1))),
                  ty = y + d[j][1] * ((1 << (i - 1)));
              if (i > 1 && fra[i - 1][tx][ty] != fill) {
                fra[i][x][y] = -1;
                break;
              }
            }
          }
          if (fra[i][x][y] >= 0) {
            if (i > 1) {
              ++ans;
            }
          }
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
