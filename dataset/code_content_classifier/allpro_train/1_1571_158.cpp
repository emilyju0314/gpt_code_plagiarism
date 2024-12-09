#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
const int INF = 1e8;
int n, m;
int b[N];
int s[201][201];
bool vis[201][201][201];
int f[201][201], a[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      f[i][j] = INF;
    }
  }
  for (int i = 1; i <= n; i++) f[i][i] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%1d", &s[i][j]);
      if (s[i][j] == 1) f[i][j] = 1;
    }
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (f[i][j] > f[i][k] + f[k][j]) {
          memset(vis[i][j], false, sizeof(vis[i][j]));
          for (int p = 1; p <= n; p++)
            vis[i][j][p] = (vis[i][k][p] | vis[k][j][p]);
          vis[i][j][k] = true;
          f[i][j] = f[i][k] + f[k][j];
        } else if (f[i][j] == f[i][k] + f[k][j]) {
          for (int p = 1; p <= n; p++)
            vis[i][j][p] |= vis[i][k][p] | vis[k][j][p];
          vis[i][j][k] = true;
        }
  int m, cnt = 2;
  scanf("%d", &m);
  scanf("%d %d", &a[1], &a[2]);
  for (int i = 3; i <= m; i++) {
    int p;
    scanf("%d", &p);
    if (vis[a[cnt - 1]][p][a[cnt]])
      a[cnt] = p;
    else
      a[++cnt] = p;
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; i++) printf("%d ", a[i]);
  printf("\n");
  return 0;
}
