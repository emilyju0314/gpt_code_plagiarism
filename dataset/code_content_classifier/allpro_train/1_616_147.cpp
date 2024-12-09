#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int v[110], vaz[110], d[110][110][110][2];
int main() {
  int n, par = 0, imp = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    vaz[v[i]] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (vaz[i] == 1) continue;
    if (i % 2 == 0)
      par++;
    else
      imp++;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= n; k++)
        for (int l = 0; l < 2; l++) d[i][j][k][l] = inf;
  d[0][0][0][0] = d[0][0][0][1] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= par; j++)
      for (int k = 0; k <= imp; k++) {
        if (v[i] > 0) {
          d[i][j][k][v[i] % 2] =
              min(d[i - 1][j][k][v[i] % 2], d[i - 1][j][k][1 - (v[i] % 2)] + 1);
        } else {
          if (j > 0)
            d[i][j][k][0] =
                min(d[i - 1][j - 1][k][0], d[i - 1][j - 1][k][1] + 1);
          if (k > 0)
            d[i][j][k][1] =
                min(d[i - 1][j][k - 1][1], d[i - 1][j][k - 1][0] + 1);
        }
      }
  printf("%d", min(d[n][par][imp][0], d[n][par][imp][1]));
  return 0;
}
