#include <bits/stdc++.h>
using namespace std;
template <class _T>
inline void rd(_T &_a) {
  int _f = 0, _ch = getchar();
  _a = 0;
  while (_ch < '0' || _ch > '9') {
    if (_ch == '-') _f = 1;
    _ch = getchar();
  }
  while (_ch >= '0' && _ch <= '9') _a = _a * 10 + _ch - '0', _ch = getchar();
  if (_f) _a = -_a;
}
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
const int N = 1e5 + 5;
struct ssr {
  double a, b;
} X;
struct tree {
  ssr s;
} t[N << 2];
int P, L, R, n, F;
double p[N];
ssr mg(ssr s1, ssr s2) { return (ssr){s1.a * s2.a, s1.b + s1.a * s2.b}; }
void Pu(int rt) { t[rt].s = mg(t[rt << 1].s, t[rt << 1 | 1].s); }
void Ch(int rt, double x) { t[rt].s.a = t[rt].s.b = 1 / x - 1; }
void Bd(int l, int r, int rt = 1) {
  if (l == r) return Ch(rt, p[l]);
  int m = l + r >> 1;
  Bd(l, m, rt << 1);
  Bd(m + 1, r, rt << 1 | 1);
  Pu(rt);
}
void Ud(int l, int r, int rt = 1) {
  if (l == r) return Ch(rt, p[l]);
  int m = l + r >> 1;
  if (P > m)
    Ud(m + 1, r, rt << 1 | 1);
  else
    Ud(l, m, rt << 1);
  Pu(rt);
}
void Qy(int l, int r, int rt = 1) {
  if (l >= L && r <= R) {
    X = mg(X, t[rt].s);
    return;
  }
  int m = l + r >> 1;
  if (L <= m) Qy(l, m, rt << 1);
  if (R > m) Qy(m + 1, r, rt << 1 | 1);
}
void pud(int u) {
  P = u;
  Ud(1, n);
}
void pqy(int l, int r) {
  X = (ssr){1, 0};
  L = l;
  R = r;
  Qy(1, n);
}
int main() {
  int m;
  rd(n);
  rd(m);
  for (int i = 1, x, y; i <= n; i++) rd(x), rd(y), p[i] = (double)x / y;
  Bd(1, n);
  for (int op, u, x, y; m; m--) {
    rd(op);
    rd(u);
    rd(x);
    if (op == 1)
      rd(y), p[u] = (double)x / y, pud(u);
    else
      pqy(u, x), printf("%.10f\n", X.b != X.b ? 0 : 1 / (1 + X.b)), F++;
  }
  return 0;
}
