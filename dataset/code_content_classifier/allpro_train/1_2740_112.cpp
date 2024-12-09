#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f * x;
}
int n, s, _x, _y;
struct info {
  int size, l, r, _l, _r, s, ls, rs, lt, rt;
  info operator+(const info &o) {
    info f;
    f.size = size + o.size;
    if (size == 0) {
      if (o.size == 0) return f;
      return o;
    }
    if (o.size == 0) return *this;
    f.l = l;
    f.r = r;
    f.s = s;
    if (rt == o.lt && f.s < o.ls + rs) f.l = _r, f.r = o._l, f.s = o.ls + rs;
    if (o.s > f.s) f.l = o.l, f.r = o.r, f.s = o.s;
    f._l = _l;
    f._r = o._r;
    f.lt = lt;
    f.rt = o.rt;
    f.ls = ls;
    f.rs = o.rs;
    if (_l >= _r && lt == o.lt) f._l = o._l, f.ls += o.ls;
    if (o._l >= o._r && o.rt == rt) f._r = _r, f.rs += rs;
    return f;
  }
} T[4 * 200005];
void build(int i, int x, int y) {
  int t = x + y >> 1;
  if (x == y) {
    T[i].size = T[i].s = T[i].ls = T[i].rs = 1;
    T[i].l = T[i].r = T[i]._l = T[i]._r = x;
    T[i].lt = T[i].rt = read();
    return;
  }
  build(i << 1, x, t);
  build(i << 1 | 1, t + 1, y);
  T[i] = T[i << 1] + T[i << 1 | 1];
}
void mod(int i, int x, int y) {
  int t = x + y >> 1;
  if (y < _x || _y < x || !T[i].size) return;
  if (_x <= x && y <= _y) {
    T[i].size = 0;
    return;
  }
  mod(i << 1, x, t);
  mod(i << 1 | 1, t + 1, y);
  T[i] = T[i << 1] + T[i << 1 | 1];
}
int main() {
  n = read();
  build(1, 1, n);
  while (T[1].size) {
    _x = T[1].l;
    _y = T[1].r;
    mod(1, 1, n);
    s++;
  }
  printf("%d\n", s);
  return 0;
}
