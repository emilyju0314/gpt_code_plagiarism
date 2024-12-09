#include <bits/stdc++.h>
using namespace std;
inline int rd() {
  register int x = 0;
  register char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return x;
}
int n, m, cn[100][100], a[6];
inline bool check() {
  int hv = 0;
  for (int i = 1; i <= 5; ++i)
    for (int j = i + 1; j <= 5; ++j)
      if (hv) {
        if (hv != cn[a[i]][a[j]] + 1) return 0;
      } else
        hv = cn[a[i]][a[j]] + 1;
  return 1;
}
inline void print() {
  for (int i = 1; i <= 5; ++i) printf("%d ", a[i]);
  putchar('\n');
}
int main() {
  n = rd(), m = rd();
  if (n > 50) n = 50;
  for (int i = 1, x, y; i <= m; ++i) {
    x = rd(), y = rd();
    if (x <= n && y <= n) cn[x][y] = cn[y][x] = 1;
  }
  for (a[1] = 1; a[1] <= n; ++a[1])
    for (a[2] = a[1] + 1; a[2] <= n; ++a[2])
      for (a[3] = a[2] + 1; a[3] <= n; ++a[3])
        for (a[4] = a[3] + 1; a[4] <= n; ++a[4])
          for (a[5] = a[4] + 1; a[5] <= n; ++a[5])
            if (check()) return print(), 0;
  puts("-1");
  return 0;
}
