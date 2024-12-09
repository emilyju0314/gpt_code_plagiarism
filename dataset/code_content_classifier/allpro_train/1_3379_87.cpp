#include <bits/stdc++.h>
using namespace std;
const int N = 300005, M = 128;
char buf[1 << 21], *p1 = buf, *p2 = buf;
inline int read() {
  int x = 0, f = 1;
  char c =
      (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
           ? EOF
           : *p1++);
  for (; !isdigit(c);
       c = (p1 == p2 &&
                    (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
                ? EOF
                : *p1++))
    if (c == '-') f = -1;
  for (; isdigit(c);
       c = (p1 == p2 &&
                    (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
                ? EOF
                : *p1++))
    x = (x + (x << 2) << 1) + c - 48;
  return x * f;
}
int n, sf, m, cv, ans = N, a[N], d[N], p[N], pf[N], ct[M], f[M], pg[M];
int main() {
  for (int i = 2; i < N; ++i)
    if (!p[i])
      for (int j = i; j < N; j += i) p[j] = i;
  n = read();
  for (int j = 1, x, y; j <= n; ++j) {
    x = y = read();
    sf = 0;
    while (y > 1) {
      int cp = p[y];
      pf[sf++] = cp;
      while (p[y] == cp) y /= cp;
    }
    m = 1 << sf;
    for (int i = 0; i < m; ++i) {
      cv = 1;
      for (int j = 0; j < sf; ++j)
        if (i & (1 << j)) cv *= pf[j];
      ct[i] = d[cv];
    }
    for (int i = 1; i < m; i <<= 1)
      for (int j = 0; j < m; ++j)
        if (j & i) ct[j ^ i] -= ct[j];
    for (int i = 0; i < m; ++i) pg[i] = ct[m - 1 - i];
    for (int i = 1; i < m; i <<= 1)
      for (int j = 0; j < m; ++j)
        if (j & i) pg[j ^ i] |= pg[j];
    fill(f, f + m, N);
    f[0] = 0;
    for (int i = 1; i < m; ++i)
      for (int j = i; j; j = (j - 1) & i)
        if (pg[j]) f[i] = min(f[i], f[i - j] + 1);
    ans = min(ans, f[m - 1] + 1);
    for (int i = 1; i * i <= x; ++i)
      if (x % i == 0) {
        ++d[i];
        if (i * i != x) ++d[x / i];
      }
  }
  (ans > n) ? printf("-1") : printf("%d", ans);
  return 0;
}
