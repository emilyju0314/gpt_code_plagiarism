#include <bits/stdc++.h>
using namespace std;
int v[200005], l[200005], r[200005], op[200005];
int main() {
  FILE* fin = stdin;
  int n, q, m, i, j, k, x;
  fscanf(fin, "%d%d%d", &n, &q, &m);
  for (i = 1; i <= n; i++) fscanf(fin, "%d", &v[i]);
  for (i = 1; i <= q; i++) fscanf(fin, "%d%d%d", &op[i], &l[i], &r[i]);
  for (i = 1; i <= m; i++) {
    fscanf(fin, "%d", &x);
    for (j = q; j >= 1; j--) {
      if (l[j] <= x && x <= r[j]) {
        if (op[j] == 1) {
          if (x == l[j])
            x = r[j];
          else
            x--;
        } else
          x = r[j] - (x - l[j]);
      }
    }
    printf("%d ", v[x]);
  }
  return 0;
}
