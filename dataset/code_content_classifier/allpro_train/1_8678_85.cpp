#include <bits/stdc++.h>
const int aa[10][2] = {{0, 0},  {2, 1},  {1, 2},   {-1, 2}, {-2, 1},
                       {1, -2}, {2, -1}, {-1, -2}, {-2, -1}};
int n, m, ans, a[100][100], b[110][110], f[1100];
int main() {
  for (int i = 2;; i += 4) {
    f[++f[0]] = i;
    f[++f[0]] = i + 2;
    f[++f[0]] = i + 2;
    f[++f[0]] = i + 2;
    if (f[0] > 1000) break;
  }
  scanf("%d%d", &n, &m);
  if (n == 1) {
    printf("%d\n", m);
    return 0;
  }
  if (m == 1) {
    printf("%d\n", n);
    return 0;
  }
  if (n == 2) {
    printf("%d\n", f[m]);
    return 0;
  }
  if (m == 2) {
    printf("%d\n", f[n]);
    return 0;
  }
  printf("%d\n", (n * m + 1) / 2);
  return 0;
}
