#include <bits/stdc++.h>
using namespace std;
inline int read() {
  register int res = 0;
  register char c = getchar(), f = 1;
  while (c < 48 || c > 57) {
    if (c == '-') f = 0;
    c = getchar();
  }
  while (c >= 48 && c <= 57)
    res = (res << 3) + (res << 1) + (c & 15), c = getchar();
  return f ? res : -res;
}
inline void write(long long x) {
  register char c[21], len = 0;
  if (!x) return putchar('0'), void();
  if (x < 0) x = -x, putchar('-');
  while (x) c[++len] = x % 10, x /= 10;
  while (len) putchar(c[len--] + 48);
}
const int N = 2e5 + 10;
int n, m, a[N], k, op, l, r;
long long x, s[N], fac[15];
bool vis[15];
void getp(long long x) {
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= k; ++i) {
    int t = x / fac[k - i] + 1;
    x %= fac[k - i];
    for (int j = 1; j <= k; ++j)
      if (!vis[j])
        if (!--t) {
          a[i] = j, vis[j] = 1;
          break;
        }
  }
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + i;
  k = min(n, 14);
  fac[0] = 1;
  for (int i = 1; i <= k; ++i) fac[i] = fac[i - 1] * i;
  while (m--) {
    op = read();
    if (op == 1) {
      l = read(), r = read();
      write(s[r] - s[l - 1]), putchar('\n');
    } else {
      x += read();
      getp(x);
      for (int i = n - k + 1; i <= n; ++i)
        s[i] = s[i - 1] + a[i + k - n] + (n - k);
    }
  }
}
