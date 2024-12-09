#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int n, m, dis[N][N][4], h[N * N * 4][3], p[N][N][4], hh, x, y, z;
char a[N][N];
void down(int x) {
  if (x * 2 > hh) return;
  int j = x * 2;
  if (j < hh && dis[h[j][0]][h[j][1]][h[j][2]] >
                    dis[h[j + 1][0]][h[j + 1][1]][h[j + 1][2]])
    j++;
  if (dis[h[j][0]][h[j][1]][h[j][2]] < dis[h[x][0]][h[x][1]][h[x][2]]) {
    int tmp = h[j][0];
    h[j][0] = h[x][0];
    h[x][0] = tmp;
    tmp = h[j][1];
    h[j][1] = h[x][1];
    h[x][1] = tmp;
    tmp = h[j][2];
    h[j][2] = h[x][2];
    h[x][2] = tmp;
    p[h[j][0]][h[j][1]][h[j][2]] = j;
    p[h[x][0]][h[x][1]][h[x][2]] = x;
    down(j);
  }
}
void up(int x) {
  if (x == 1) return;
  int j = x / 2;
  if (dis[h[j][0]][h[j][1]][h[j][2]] > dis[h[x][0]][h[x][1]][h[x][2]]) {
    int tmp = h[j][0];
    h[j][0] = h[x][0];
    h[x][0] = tmp;
    tmp = h[j][1];
    h[j][1] = h[x][1];
    h[x][1] = tmp;
    tmp = h[j][2];
    h[j][2] = h[x][2];
    h[x][2] = tmp;
    p[h[j][0]][h[j][1]][h[j][2]] = j;
    p[h[x][0]][h[x][1]][h[x][2]] = x;
    up(j);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", a[i]);
  memset(dis, -1, sizeof(dis));
  memset(p, -1, sizeof(p));
  hh = 0;
  for (int j = 0; j < m; j++) {
    dis[n - 1][j][2] = 0;
    p[n - 1][j][2] = ++hh;
    h[hh][0] = n - 1;
    h[hh][1] = j;
    h[hh][2] = 2;
  }
  bool ff = 1;
  int ans = -1;
  while (hh) {
    x = h[1][0];
    y = h[1][1];
    z = h[1][2];
    if (x == 0 && a[x][y] != '.' && z != 2) ans = dis[x][y][z] + 1;
    if (x == 0 && z == 2) break;
    h[1][0] = h[hh][0];
    h[1][1] = h[hh][1];
    h[1][2] = h[hh--][2];
    down(1);
    for (int k = 0; k < 4; k++)
      if (x + dx[k] >= 0 && x + dx[k] < n && y + dy[k] >= 0 && y + dy[k] < m) {
        if (p[x + dx[k]][y + dy[k]][k] == -1 ||
            dis[x + dx[k]][y + dy[k]][k] == -1 ||
            dis[x + dx[k]][y + dy[k]][k] > dis[x][y][z] + (k != z)) {
          if (a[x][y] == '.' && k != z) continue;
          dis[x + dx[k]][y + dy[k]][k] = dis[x][y][z] + (k != z);
          if (p[x + dx[k]][y + dy[k]][k] == -1) {
            p[x + dx[k]][y + dy[k]][k] = ++hh;
            h[hh][0] = x + dx[k];
            h[hh][1] = y + dy[k];
            h[hh][2] = k;
          }
          up(p[x + dx[k]][y + dy[k]][k]);
        }
      }
  }
  if (hh == 0)
    printf("%d\n", ans);
  else
    printf("%d\n", dis[x][y][z]);
  return 0;
}
