#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[1 << 12], *p1 = buf, *p2 = buf;
  return (p1 == p2) &&
                 (p2 = (p1 = buf) + fread(buf, 1, 1 << 12, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline void read(long long& x) {
  x = 0;
  long long c = gc();
  bool f = false;
  for (; !isdigit(c); c = gc())
    if (c == '-') f = true;
  for (; isdigit(c); c = gc()) x = (x << 1) + (x << 3) + (c ^ 48);
  if (f) x = -x;
}
const long long maxn = 1000005;
const long long maxm = 255;
long long kan[maxn];
long long n, m;
struct Point {
  long long x, y;
  inline bool operator==(const Point& o) const { return x == o.x && y == o.y; }
} p[maxm];
inline long long gcd(long long a, long long b) {
  while (b) a %= b, swap(a, b);
  return a;
}
struct FS {
  long long a, b;
  FS(long long x, long long y) {
    long long g = gcd(x, y);
    if (g) {
      x /= g;
      y /= g;
      a = x;
      b = y;
      if (b < 0) a = -a, b = -b;
    } else
      a = b = 0;
  }
  bool operator==(const FS& o) const { return a == o.a && b == o.b; }
  FS() {}
} Tmp[maxm][maxm];
inline long long getk(Point a, Point b) {
  if (a.x == b.x) return (a.x < 0 || a.x > n) ? 0 : a.x;
  long long K1 = (long long)b.x * a.y - (long long)a.x * b.y;
  long long K2 = a.y - b.y;
  long long tmp;
  if (!K2 || K1 % K2 || (tmp = K1 / K2) > n || tmp < 0)
    return 0;
  else
    return tmp;
}
inline bool Pan(long long a, long long b, long long c) {
  if (p[a] == p[c] || p[b] == p[c]) return true;
  return Tmp[a][b] == Tmp[b][c];
}
signed main() {
  read(n), read(m);
  for (register long long i = 1; i <= m; ++i) read(p[i].x), read(p[i].y);
  for (register long long i = 1; i <= m; ++i)
    for (register long long j = 1; j <= m; ++j)
      Tmp[i][j] = FS(p[i].x - p[j].x, p[i].y - p[j].y);
  for (register long long i = 1; i <= m; ++i) {
    for (register long long j = i + 1; j <= m; ++j) {
      long long tmp = getk(p[i], p[j]);
      if (tmp) {
        long long anss = 2;
        for (register long long k = 1; k <= m; ++k)
          if (k != i && k != j) anss += Pan(i, j, k);
        kan[tmp] = max(kan[tmp], anss);
      }
    }
  }
  long long ans = 0;
  for (long long i = 1; i <= n; ++i) ans += max(1LL, kan[i]);
  printf("%lld\n", ans);
  return 0;
}
