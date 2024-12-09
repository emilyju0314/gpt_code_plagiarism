#include <bits/stdc++.h>
int n, m, c[1000 + 10][1000 + 10], ci[1000 + 10][1000 + 10],
    cj[1000 + 10][1000 + 10], cij[1000 + 10][1000 + 10];
void Read(int &x) {
  char c;
  while (c = getchar(), c != EOF)
    if (c >= '0' && c <= '9') {
      x = c - '0';
      while (c = getchar(), c >= '0' && c <= '9') x = x * 10 + c - '0';
      ungetc(c, stdin);
      return;
    }
}
inline int lowbit(int x) { return x & -x; }
void update(int c[][1000 + 10], int x, int y, int d) {
  int j;
  for (; x <= n; x += lowbit(x))
    for (j = y; j <= n; j += lowbit(j)) c[x][j] ^= d;
}
int getsum(int c[][1000 + 10], int x, int y) {
  int j, ret = 0;
  for (; x; x -= lowbit(x))
    for (j = y; j; j -= lowbit(j)) ret ^= c[x][j];
  return ret;
}
int main() {
  Read(n), Read(m);
  int p, x1, y1, x0, y0, v, a1, a2, a3, a4;
  while (m--) {
    Read(p);
    if (p == 2) {
      Read(x0), Read(y0), Read(x1), Read(y1), Read(v);
      update(c, x0, y0, v);
      update(ci, x0, y0, x0 & 1 ? v : 0);
      update(cj, x0, y0, y0 & 1 ? v : 0);
      update(cij, x0, y0, (x0 * y0) & 1 ? v : 0);
      update(c, x0, y1 + 1, v);
      update(ci, x0, y1 + 1, x0 & 1 ? v : 0);
      update(cj, x0, y1 + 1, (y1 + 1) & 1 ? v : 0);
      update(cij, x0, y1 + 1, (x0 * (y1 + 1)) & 1 ? v : 0);
      update(c, x1 + 1, y0, v);
      update(ci, x1 + 1, y0, (x1 + 1) & 1 ? v : 0);
      update(cj, x1 + 1, y0, y0 & 1 ? v : 0);
      update(cij, x1 + 1, y0, ((x1 + 1) * y0) & 1 ? v : 0);
      update(c, x1 + 1, y1 + 1, v);
      update(ci, x1 + 1, y1 + 1, (x1 + 1) & 1 ? v : 0);
      update(cj, x1 + 1, y1 + 1, (y1 + 1) & 1 ? v : 0);
      update(cij, x1 + 1, y1 + 1, ((x1 + 1) * (y1 + 1)) & 1 ? v : 0);
    } else {
      Read(x0), Read(y0), Read(x1), Read(y1);
      a1 = (((x1 + 1) * (y1 + 1)) & 1 ? getsum(c, x1, y1) : 0) ^
           ((y1 + 1) & 1 ? getsum(ci, x1, y1) : 0) ^
           ((x1 + 1) & 1 ? getsum(cj, x1, y1) : 0) ^ getsum(cij, x1, y1);
      a2 = ((x0 * (y1 + 1)) & 1 ? getsum(c, x0 - 1, y1) : 0) ^
           ((y1 + 1) & 1 ? getsum(ci, x0 - 1, y1) : 0) ^
           (x0 & 1 ? getsum(cj, x0 - 1, y1) : 0) ^ getsum(cij, x0 - 1, y1);
      a3 = (((x1 + 1) * y0) & 1 ? getsum(c, x1, y0 - 1) : 0) ^
           (y0 & 1 ? getsum(ci, x1, y0 - 1) : 0) ^
           ((x1 + 1) & 1 ? getsum(cj, x1, y0 - 1) : 0) ^
           getsum(cij, x1, y0 - 1);
      a4 = ((x0 * y0) & 1 ? getsum(c, x0 - 1, y0 - 1) : 0) ^
           (y0 & 1 ? getsum(ci, x0 - 1, y0 - 1) : 0) ^
           (x0 & 1 ? getsum(cj, x0 - 1, y0 - 1) : 0) ^
           getsum(cij, x0 - 1, y0 - 1);
      printf("%d\n", a1 ^ a2 ^ a3 ^ a4);
    }
  }
}
