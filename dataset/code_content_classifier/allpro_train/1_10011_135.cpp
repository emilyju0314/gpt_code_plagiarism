#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool upmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
inline bool upmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
const long double eps = 1e-11;
const long double pi = acos(-1);
const long long oo = 1 << 30;
const long long loo = 1ll << 62;
const long long mods = 998244353;
const long long MAXN = 5000005;
const long long INF = 0x3f3f3f3f;
inline long long read() {
  long long f = 1, x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
long long f[20][20], C[20][20], g[20], cnt[20];
void print(long long c) {
  if (c < 10)
    putchar(c + '0');
  else
    putchar(c + 'a' - 10);
}
void Init(long long k) {
  for (long long i = 0; i < 20; i++) C[i][i] = C[i][0] = 1;
  for (long long i = 2; i < 20; i++)
    for (long long j = 1; j < i; j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
}
long long get(long long n) {
  if (n < 0) return 0;
  for (long long i = 1; i <= 16; i++)
    if (cnt[i] < 0) return 0;
  memset(f, 0, sizeof f), f[0][0] = 1;
  for (long long i = 0; i <= n; i++)
    for (long long j = 1; j <= 16; j++)
      for (long long t = 0; t <= min(cnt[j], i); t++)
        f[i][j] += f[i - t][j - 1] * C[i][t];
  return f[n][16];
}
long long _get(long long n) {
  if (n <= 0) return 0;
  long long sum = 0;
  for (long long p = 2; p <= 16; p++)
    if (cnt[p]) {
      cnt[p]--;
      memset(f, 0, sizeof f), f[0][0] = 1;
      for (long long i = 0; i < n; i++)
        for (long long j = 1; j <= 16; j++)
          for (long long t = 0; t <= min(cnt[j], i); t++)
            f[i][j] += f[i - t][j - 1] * C[i][t];
      sum += f[n - 1][16];
      cnt[p]++;
    }
  return sum;
}
signed main() {
  long long n = read(), k = read(), mx = 0;
  Init(k);
  for (long long i = 1; i <= 16; i++) cnt[i] = k;
  for (long long i = 0; i <= 9; i++) {
    long long t = _get(i);
    if (n - t <= 0) {
      mx = i - 1;
      break;
    }
    n -= t;
  }
  for (long long i = mx; i >= 0; i--) {
    long long t = (i == mx ? 2 : 1);
    for (long long j = (i == mx ? 2 : 1), p; j <= 16; j++) {
      cnt[j]--, p = get(i), cnt[j]++;
      if (n > p)
        t = j + 1, n -= p;
      else {
        if (!i && p == n) t = j, n -= p;
        break;
      }
    }
    cnt[t]--;
    print(t - 1);
  }
  return 0;
}
