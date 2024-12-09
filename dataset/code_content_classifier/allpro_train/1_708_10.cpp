#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, ori[300][300], mat[300][300], mr[300], mc[300], vis[100000],
      l[100000], r[100000];
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &ori[i][j]);
  for (int i = 1; i <= n; i++) mr[i] = 0;
  for (int i = 1; i <= m; i++) mc[i] = 0;
  for (int i = 1; i < 1000; i++) vis[i] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      mr[i] = max(mr[i], ori[i][j]);
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      mc[i] = max(mc[i], ori[j][i]);
    }
  }
  for (int i = 1; i <= n; i++) vis[mr[i]] = 1;
  for (int i = 1; i <= m; i++) {
    if (!vis[mc[i]])
      vis[mc[i]] = 2;
    else
      vis[mc[i]] = 3;
  }
  int x = 0, y = 0;
  for (int k = n * m; k >= 1; k--) {
    if (vis[k] == 3) {
      mat[++x][++y] = k;
      l[x] = r[x] = y;
    } else if (vis[k] == 2) {
      mat[x][++y] = k;
      l[x] = r[x] = y;
    } else if (vis[k] == 1) {
      mat[++x][y] = k;
      l[x] = r[x] = y;
    } else {
      for (int i = 1; i <= x; i++) {
        int flag = 0;
        for (int j = l[i] - 1; j >= 1; j--) {
          if (!mat[i][j] && mat[i - 1][j]) {
            flag = 1;
            mat[i][j] = k;
            l[i] = j;
            break;
          }
        }
        if (flag) break;
        for (int j = r[i] + 1; j <= y; j++) {
          if (!mat[i][j] && mat[i + 1][j]) {
            flag = 1;
            mat[i][j] = k;
            r[i] = j;
            break;
          }
        }
        if (flag) break;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%d ", mat[i][j]);
    printf("\n");
  }
  return 0;
}
