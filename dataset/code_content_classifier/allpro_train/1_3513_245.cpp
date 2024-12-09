#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC target("avx")
using namespace std;
inline char gc() {
  static char buf[1 << 16], *p1 = buf, *p2 = buf;
  if (p1 == p2) {
    p2 = (p1 = buf) + fread(buf, 1, 1 << 16, stdin);
    if (p2 == p1) return EOF;
  }
  return *p1++;
}
template <class t>
inline t read(t &x) {
  char c = gc();
  bool f = 0;
  x = 0;
  while (!isdigit(c)) f |= c == '-', c = gc();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = gc();
  if (f) x = -x;
  return x;
}
template <class t>
inline void write(t x) {
  if (x < 0)
    putchar('-'), write(-x);
  else {
    if (x > 9) write(x / 10);
    putchar('0' + x % 10);
  }
}
const int N = 1e4 + 5;
int a[N], b[N], n, c;
long long f[2][N], ans = 1e18;
signed main() {
  read(n);
  read(c);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= n; i++) read(b[i]);
  for (int i = 1; i <= n; i++) {
    f[i & 1][0] = f[~i & 1][0] + a[i];
    for (int j = 1; j < i; j++)
      f[i & 1][j] =
          min(f[~i & 1][j] + a[i] + 1ll * c * j, f[~i & 1][j - 1] + b[i]);
    f[i & 1][i] = f[~i & 1][i - 1] + b[i];
  }
  for (int i = 0; i <= n; i++) ans = min(ans, f[n & 1][i]);
  write(ans);
}
