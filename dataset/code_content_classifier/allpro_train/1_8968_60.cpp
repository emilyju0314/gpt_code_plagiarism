#include <bits/stdc++.h>
using namespace std;
const int nmax = 3e5;
long long h[nmax + 1];
struct str {
  int mx, xj, yj, a, b;
  long long v1, v2, lazy;
} aint[4 * nmax + 1];
str uneste(str x, str y, int lg1, int lg2) {
  str ans;
  x.v1 += x.lazy;
  x.v2 += x.lazy;
  y.v1 += y.lazy;
  y.v2 += y.lazy;
  ans.v1 = x.v1;
  ans.v2 = y.v2;
  ans.lazy = 0;
  ans.mx = max(x.mx, y.mx);
  if (x.v2 < y.v1 && x.yj + y.a > ans.mx) ans.mx = x.yj + y.a;
  if (x.v2 > y.v1 && x.b + y.xj > ans.mx) ans.mx = x.b + y.xj;
  ans.yj = y.yj;
  ans.xj = x.xj;
  if (y.yj == lg2 && y.v1 > x.v2) ans.yj = max(ans.yj, y.yj + x.yj);
  if (x.xj == lg1 && x.v2 > y.v1) ans.xj = max(ans.xj, x.xj + y.xj);
  ans.a = max(x.a, ans.xj);
  ans.b = max(y.b, ans.yj);
  if (x.a == lg1 && x.v2 > y.v1) ans.a = max(ans.a, x.a + y.xj);
  if (x.yj == lg1 && x.v2 < y.v1) ans.a = max(ans.a, x.yj + y.a);
  if (y.b == lg2 && y.v1 > x.v2) ans.b = max(ans.b, y.b + x.yj);
  if (y.xj == lg2 && y.v1 < x.v2) ans.b = max(ans.b, y.xj + x.b);
  return ans;
}
void build(int nod, int x, int y) {
  if (x == y) {
    aint[nod].v1 = aint[nod].v2 = h[x];
    aint[nod].xj = aint[nod].yj = 1;
    aint[nod].a = aint[nod].b = 1;
    aint[nod].mx = 1;
    aint[nod].lazy = 0;
    return;
  }
  int mij = (x + y) / 2;
  build(2 * nod, x, mij);
  build(2 * nod + 1, mij + 1, y);
  aint[nod] = uneste(aint[2 * nod], aint[2 * nod + 1], mij - x + 1, y - mij);
}
inline void propaga(int nod) {
  aint[2 * nod].lazy += aint[nod].lazy;
  aint[2 * nod + 1].lazy += aint[nod].lazy;
  aint[nod].v1 += aint[nod].lazy;
  aint[nod].v2 += aint[nod].lazy;
  aint[nod].lazy = 0;
}
void update(int nod, int x, int y, int st, int dr, long long val) {
  if (st <= x && y <= dr) {
    aint[nod].lazy += val;
    return;
  }
  propaga(nod);
  int mij = (x + y) / 2;
  if (st <= mij) update(2 * nod, x, mij, st, dr, val);
  if (mij < dr) update(2 * nod + 1, mij + 1, y, st, dr, val);
  aint[nod] = uneste(aint[2 * nod], aint[2 * nod + 1], mij - x + 1, y - mij);
}
int main() {
  int n, m;
  fscanf(stdin, "%d", &n);
  for (int i = 1; i <= n; ++i) {
    fscanf(stdin, "%I64d", &h[i]);
  }
  build(1, 1, n);
  fscanf(stdin, "%d", &m);
  for (int i = 1; i <= m; ++i) {
    int x, y;
    long long val;
    fscanf(stdin, "%d%d%I64d", &x, &y, &val);
    update(1, 1, n, x, y, val);
    int aux = aint[1].mx;
    fprintf(stdout, "%d\n", aux);
  }
  return 0;
}
