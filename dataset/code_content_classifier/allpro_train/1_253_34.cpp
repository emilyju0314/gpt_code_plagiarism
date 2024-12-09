#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return f == 1 ? x : ~x + 1;
}
const long long inf = 1e18;
long long n, t, K;
long long a[210], b[210], c[210];
long long sa[210], sb[210];
long long f[210][210][2], g[210][210][2];
void chkmin(long long &x, long long y) { x = (x <= y ? x : y); }
signed main() {
  n = read(), t = read(), K = read();
  ++n;
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 0; j <= t; ++j) {
      for (long long k = 0; k <= 1; ++k) {
        f[i][j][k] = g[i][j][k] = inf;
      }
    }
  }
  for (long long i = 1; i <= n - 1; ++i) {
    a[i] = read(), b[i] = read(), c[i] = read();
    sa[i] = sa[i - 1] + a[i], sb[i] = sb[i - 1] + b[i];
  }
  a[n] = c[n] = inf;
  b[n] = 0;
  sa[n] = sa[n - 1] + a[n];
  sb[n] = sb[n - 1];
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 0; j <= t; ++j) {
      for (long long k = 0; k <= 1; ++k) {
        if (f[i - 1][j][k] != inf && a[i] * k + b[i] * j <= c[i]) {
          f[i][j][k] = f[i - 1][j][k];
          long long cnt = sa[i - 1] * k + sb[i - 1] * j - f[i - 1][j][k] * K;
          long long cost = (cnt + K - 1) / K;
          if (cost * K <= cnt + a[i] * k + b[i] * j) {
            g[i][j][k] = f[i - 1][j][k] + cost;
          }
        }
        for (long long l = 0; l < j; ++l) {
          if (g[i][l][k] != inf && f[i - 1][j - l][0] != inf) {
            long long m = sa[i] * k + sb[i] * l - g[i][l][k] * K;
            long long cst = max(0ll, (m + b[i] * (j - l) - c[i] + K - 1) / K);
            if (cst * K <= m) {
              chkmin(f[i][j][k], g[i][l][k] + cst + f[i - 1][j - l][0]);
              long long tmp =
                  (sb[i - 1] * (j - l) - f[i - 1][j - l][0] * K + K - 1) / K;
              if (tmp * K - sb[i - 1] * (j - l) + f[i - 1][j - l][0] * K <=
                  m + b[i] * (j - l) - cst * K) {
                chkmin(g[i][j][k], g[i][l][k] + cst + f[i - 1][j - l][0] + tmp);
              }
            }
          }
        }
      }
    }
  }
  printf("%lld\n", f[n][t][1]);
}
