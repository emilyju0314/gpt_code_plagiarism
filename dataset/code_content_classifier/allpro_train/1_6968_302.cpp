#include <bits/stdc++.h>
using namespace std;
const int N = 505, M = 1e5 + 10;
char s[M];
int x, y, tx, ty, nx, ny, vis[N][N], res[M];
int main() {
  while (~scanf("%d%d%d%d", &x, &y, &tx, &ty)) {
    scanf("%s", s + 1);
    memset(vis, 0, sizeof(vis));
    memset(res, 0, sizeof(res));
    int cnt = 1, len = strlen(s + 1);
    res[0] = 1, vis[tx][ty] = 1;
    for (int i = 1; i <= len; i++) {
      if (s[i] == 'L')
        nx = tx, ny = ty - 1;
      else if (s[i] == 'R')
        nx = tx, ny = ty + 1;
      else if (s[i] == 'U')
        nx = tx - 1, ny = ty;
      else
        nx = tx + 1, ny = ty;
      if (nx < 1 || nx > x || ny < 1 || ny > y) nx = tx, ny = ty;
      if (vis[nx][ny]) {
        res[i] = 0;
      } else {
        if (nx == tx && ny == ty)
          res[i] = 0;
        else
          res[i] = 1;
        vis[nx][ny] = 1;
        cnt++;
        if (i == len) cnt--;
      }
      tx = nx, ty = ny;
    }
    printf("%d", res[0]);
    for (int i = 1; i < len; i++) printf(" %d", res[i]);
    printf(" %d\n", x * y - cnt);
  }
  return 0;
}
