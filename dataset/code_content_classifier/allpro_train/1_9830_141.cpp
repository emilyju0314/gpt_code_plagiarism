#include <bits/stdc++.h>
using namespace std;
int m, n, i, j, a[110][110], b[110][110], k;
int main() {
  scanf("%d%d", &m, &n);
  for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++) {
      a[i][j] = 1;
      scanf("%d", &b[i][j]);
    }
  for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++) {
      if (b[i][j] == 0) {
        for (k = 1; k <= n; k++) a[i][k] = 0;
        for (k = 1; k <= m; k++) a[k][j] = 0;
      }
    }
  for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++) {
      int tmp = 0;
      for (k = 1; k <= n; k++) tmp |= a[i][k];
      for (k = 1; k <= m; k++) tmp |= a[k][j];
      if (tmp != b[i][j]) {
        printf("NO\n");
        return 0;
      }
    }
  printf("YES\n");
  for (i = 1; i <= m; i++) {
    for (j = 1; j < n; j++) printf("%d ", a[i][j]);
    printf("%d\n", a[i][n]);
  }
}
