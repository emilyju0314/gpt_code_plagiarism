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
long long n, ans;
long long cnt[280010], fib[280010], f[25][280010], g[25][280010], a[280010],
    b[280010], c[280010];
void FWT_or(long long *a, int type) {
  for (int len = 1; len < (1 << 17); len <<= 1)
    for (int i = 0; i < (1 << 17); i += len << 1)
      for (int j = i; j < i + len; ++j)
        a[j + len] = (a[j + len] + a[j] * type + 1000000007) % 1000000007;
}
void FWT_and(long long *a, int type) {
  for (int len = 1; len < (1 << 17); len <<= 1)
    for (int i = 0; i < (1 << 17); i += len << 1)
      for (int j = i; j < i + len; ++j)
        a[j] = (a[j] + a[j + len] * type + 1000000007) % 1000000007;
}
void FWT_xor(long long *a, int type) {
  for (int len = 1; len < (1 << 17); len <<= 1) {
    for (int i = 0; i < (1 << 17); i += len << 1) {
      for (int j = i; j < i + len; ++j) {
        long long x = a[j], y = a[j + len];
        a[j] = (x + y) % 1000000007,
        a[j + len] = (x - y + 1000000007) % 1000000007;
        if (type != 1)
          a[j] = a[j] * 500000004 % 1000000007,
          a[j + len] = a[j + len] * 500000004 % 1000000007;
      }
    }
  }
}
void init() {
  fib[1] = 1;
  for (int i = 2; i < (1 << 17); ++i)
    fib[i] = (fib[i - 1] + fib[i - 2]) % 1000000007;
  for (int i = 1; i < (1 << 17); ++i) cnt[i] = cnt[i - (i & (-i))] + 1;
}
int main() {
  init(), read(n);
  for (int i = 1; i <= n; ++i) {
    long long x;
    read(x);
    g[cnt[x]][x]++, b[x]++, c[x]++;
  }
  for (int i = 0; i <= 17; ++i) FWT_or(g[i], 1);
  for (int i = 0; i <= 17; ++i)
    for (int j = 0; j <= i; ++j)
      for (int s = 0; s < (1 << 17); ++s)
        f[i][s] = (f[i][s] + g[i - j][s] * g[j][s] % 1000000007) % 1000000007;
  for (int i = 0; i <= 17; ++i) FWT_or(f[i], -1);
  FWT_xor(c, 1);
  for (int i = 0; i < (1 << 17); ++i) c[i] = c[i] * c[i] % 1000000007;
  FWT_xor(c, -1);
  for (int i = 0; i < (1 << 17); ++i) {
    a[i] = fib[i] * f[cnt[i]][i] % 1000000007;
    b[i] = b[i] * fib[i] % 1000000007, c[i] = c[i] * fib[i] % 1000000007;
  }
  FWT_and(a, 1), FWT_and(b, 1), FWT_and(c, 1);
  for (int i = 0; i < (1 << 17); ++i)
    a[i] = a[i] * b[i] % 1000000007 * c[i] % 1000000007;
  FWT_and(a, -1);
  for (int i = 1; i < (1 << 17); i <<= 1) ans = (ans + a[i]) % 1000000007;
  printf("%lld", ans);
  return 0;
}
