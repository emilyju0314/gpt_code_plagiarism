#include <bits/stdc++.h>
using namespace std;
const int lim = 2e3 + 10, inf = 2e9;
char a[lim], b[lim];
int f[lim][lim];
int pos[lim], res[lim];
int ans[lim];
int main() {
  scanf("%s", a + 1);
  scanf("%s", b + 1);
  int n = strlen(a + 1), m = strlen(b + 1);
  for (int i = 1; i <= n; i++)
    if (a[i] == b[1]) {
      int k = 1;
      for (int j = i; j <= n; j++) {
        if (a[j] == b[k]) {
          k++;
          if (k == m + 1) {
            pos[i] = j;
            break;
          }
        } else
          res[i]++;
      }
    }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      f[i][j] = -inf;
    }
  }
  f[0][0] = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++)
      if (f[i][j] != -inf) {
        f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j]);
        f[i + 1][j] = max(f[i + 1][j], f[i][j]);
        if (pos[i + 1]) {
          f[pos[i + 1]][j + res[i + 1]] =
              max(f[pos[i + 1]][j + res[i + 1]], f[i][j] + 1);
        }
      }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) ans[j] = max(ans[j], f[i][j]);
  }
  for (int i = 0; i < n; i++) printf("%d ", ans[i]);
  printf("%d\n", ans[n]);
  return 0;
}
