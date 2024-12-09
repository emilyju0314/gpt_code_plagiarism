#include <bits/stdc++.h>
using namespace std;
int nhang, ncot, n, m;
int a[510][510], b[510][510];
int x, y, z;
int kq;
void khoitri() {
  int i, j;
  for (i = 1; i <= nhang; i++) {
    for (j = 1; j <= ncot; j++) {
      a[i][j] = 2147483647;
    }
  }
}
void xetdoc() {
  int i, j, k;
  int maxx;
  for (i = 1; i <= ncot; i++) {
    for (j = 1; j <= nhang - n + 1; j++) {
      maxx = -1;
      for (k = j; k < j + n; k++) {
        if (a[k][i] > maxx) {
          maxx = a[k][i];
        }
      }
      b[j][i] = maxx;
    }
  }
}
void xetngang() {
  int i, j, k;
  int maxx;
  kq = 2147483647;
  for (i = 1; i <= nhang - n + 1; i++) {
    for (j = 1; j <= ncot - n + 1; j++) {
      maxx = -1;
      for (k = j; k < j + n; k++) {
        if (b[i][k] > maxx) {
          maxx = b[i][k];
        }
      }
      kq = min(kq, maxx);
    }
  }
}
void solve() {
  xetdoc();
  xetngang();
}
void output() {
  if (kq == 2147483647) {
    kq = -1;
  }
  printf("%d\n", kq);
}
int main() {
  int i;
  while (scanf("%d %d %d %d", &nhang, &ncot, &n, &m) > 0) {
    khoitri();
    for (i = 0; i < m; i++) {
      scanf("%d %d %d", &x, &y, &z);
      a[x][y] = min(a[x][y], z);
    }
    solve();
    output();
  }
  return 0;
}
