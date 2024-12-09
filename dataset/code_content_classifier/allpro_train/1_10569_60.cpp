#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  bool f = 1;
  char s = getchar();
  while ((s < '0' || s > '9') && s > 0) {
    if (s == '-') f ^= 1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') x = (x << 1) + (x << 3) + s - '0', s = getchar();
  return f ? x : -x;
}
inline void FMTOR(long long* a, int n, int inv) {
  for (int k = 1; k < n; k <<= 1)
    for (int i = 0; i < n; i++)
      if (~i & k) a[i | k] += a[i] * inv;
}
inline void FWTOR(long long* a, int n, int inv) {
  for (int k = 2; k <= n; k <<= 1)
    for (int i = 0; i < n; i += k)
      for (int j = i; j < i + (k >> 1); j++) a[j + (k >> 1)] += a[j] * inv;
}
int n;
long long f[2097160], a[2097160], b[2097160];
signed main() {
  n = (1 << read());
  f[0] = 1;
  for (int i = 1; i < n; i++) f[i] = f[i >> 1] * ((i & 1) ? 4 : 1);
  for (int i = 0; i < n; i++) a[i] = 1ll * (getchar() - '0') * f[i];
  getchar();
  for (int i = 0; i < n; i++) b[i] = 1ll * (getchar() - '0') * f[i];
  FWTOR(a, n, 1), FWTOR(b, n, 1);
  for (int i = 0; i < n; i++) a[i] = a[i] * b[i];
  FWTOR(a, n, -1);
  for (int i = 0; i < n; i++) printf("%lld", (a[i] / f[i]) & 3);
  return 0;
}
