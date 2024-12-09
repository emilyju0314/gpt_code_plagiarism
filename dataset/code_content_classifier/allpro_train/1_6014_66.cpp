#include <bits/stdc++.h>
using namespace std;
int a[505][505];
int sum[505];
int main() {
  int i, j;
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (i = 1; i <= n; i++) {
    int t = 0;
    for (j = 1; j <= m; j++) {
      t += a[i][j];
      sum[i] = max(sum[i], t);
      if (a[i][j] == 0) t = 0;
    }
  }
  while (q--) {
    int u, v;
    scanf("%d%d", &u, &v);
    a[u][v] = !a[u][v];
    int t = 0;
    sum[u] = 0;
    for (i = 1; i <= m; i++) {
      t += a[u][i];
      sum[u] = max(sum[u], t);
      if (a[u][i] == 0) t = 0;
    }
    int mx = 0;
    for (i = 1; i <= n; i++) {
      mx = max(mx, sum[i]);
    }
    printf("%d\n", mx);
  }
}
