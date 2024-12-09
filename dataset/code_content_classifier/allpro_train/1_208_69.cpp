#include <bits/stdc++.h>
struct point {
  int x, y;
};
inline bool cmp(const point &a, const point &b) {
  bool aflg = a.x <= 0, bflg = b.x <= 0;
  if (aflg ^ bflg) return aflg < bflg;
  if (!a.x) {
    if (a.y > 0) return true;
    return false;
  }
  if (!b.x) {
    if (b.y > 0) return false;
    return true;
  }
  return (long long)a.y * b.x < (long long)a.x * b.y;
}
char ibuf[7605000], *ip = ibuf;
inline void readi(int &n) {
  while (*ip < 49 || *ip > 57) ip++;
  n = *ip++ - 48;
  while (48 <= *ip && *ip <= 57) n = (n << 1) + (n << 3) + *ip++ - 48;
}
inline void readp(const int &n, const int c, const int d, point *p) {
  int x, y, i = 0;
  while (i < n) {
    readi(x);
    readi(y);
    x -= c;
    y -= d;
    p[i++] = (point){x, y};
  }
  std::sort(p, p + n, cmp);
}
point p[345679];
int s[345678], stp[345678], us[345678];
int main() {
  fread(ibuf, 7605000, 1, stdin);
  int c, d;
  readi(c);
  const int n = c;
  readi(c);
  readi(d);
  readp(n, c, d, p);
  d = 0;
  while (d < n && p[d].x > 0) d++;
  if (d == n) {
    putchar(48);
    return 0;
  }
  int nm;
  const int nd = d;
  for (c = 0; c < n; c++) {
    while (d < n && (long long)p[c].x * p[d].y - (long long)p[d].x * p[c].y > 0)
      d++;
    s[c] = d - nd;
    nm = d;
    while (nm < n &&
           (long long)p[c].x * p[nm].y - (long long)p[nm].x * p[c].y == 0)
      nm++;
    us[c] = nm - nd;
    if (c < nd) stp[c] = d;
  }
  long long ans = 0, pre = 0;
  c = -1;
  d = 0;
  while (++c < nd) {
    while (d < stp[c]) pre += s[d++];
    pre -= s[c];
    nm = 1;
    while (c + 1 < nd &&
           (long long)p[c].x * p[c + 1].y - (long long)p[c].y * p[c + 1].x == 0)
      nm++, pre -= s[++c];
    ans += (pre - (long long)(d - c - 1) * us[c]) * nm;
  }
  printf("%I64d", ans);
  return 0;
}
