#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  bool flag = false;
  while (!isdigit(c)) {
    if (c == '-') flag = true;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  if (flag) x = -x;
}
long long n, m, t, p;
long long cnt[1200010], f[1200010], g[1200010], h[1200010];
long long mul(long long x, long long y) {
  long long c = (long double)x * y / p + 0.5;
  c = x * y - c * p;
  return c < 0 ? c + p : c;
}
void FWT(long long *a, int type) {
  for (int len = 1; len < n; len <<= 1) {
    for (int i = 0; i < n; i += len << 1) {
      for (int j = i; j < i + len; ++j) {
        long long x = a[j], y = a[j + len];
        a[j] = (x + y) % p, a[j + len] = (x - y + p) % p;
      }
    }
  }
  if (type == 1) return;
  for (int i = 0; i < n; ++i) a[i] /= n;
}
int main() {
  read(m), read(t), read(p), n = 1 << m, p *= n;
  for (int i = 1; i < n; ++i) cnt[i] = cnt[i - (i & (-i))] + 1;
  for (int i = 0; i < n; ++i) read(f[i]);
  for (int i = 0; i <= m; ++i) read(h[i]);
  if (!t) {
    for (int i = 0; i < n; ++i) printf("%lld\n", f[i]);
    return 0;
  }
  for (int i = 0; i < n; ++i) g[i] = h[cnt[i]];
  for (int i = 0; i < n; ++i) h[i] = g[i];
  FWT(f, 1), FWT(g, 1), FWT(h, 1), t--;
  while (t) {
    if (t & 1)
      for (int i = 0; i < n; ++i) g[i] = mul(g[i], h[i]);
    for (int i = 0; i < n; ++i) h[i] = mul(h[i], h[i]);
    t >>= 1;
  }
  for (int i = 0; i < n; ++i) f[i] = mul(f[i], g[i]);
  FWT(f, -1);
  for (int i = 0; i < n; ++i) printf("%lld\n", f[i]);
  return 0;
}
