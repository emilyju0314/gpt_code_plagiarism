#include <bits/stdc++.h>
using namespace std;
void read(long long &x) {
  x = 0;
  long long f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -f;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  x *= f;
}
void print(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (!x) return;
  print(x / 10), putchar(x % 10 + 48);
}
void write(long long x) {
  if (!x)
    putchar('0');
  else
    print(x);
  putchar('\n');
}
const long long maxn = 1e6 + 10;
const long long inf = 1e9;
const double eps = 1e-8;
const long long mod = 1e9 + 7;
long long n, pw[maxn][7];
long long qpow(long long a, long long x) {
  long long res = 1;
  for (; x; x >>= 1, a = a * a % mod)
    if (x & 1) res = res * a % mod;
  return res;
}
signed main() {
  read(n);
  long long m = sqrt(n), ans = 0;
  for (long long i = 2; i <= 6; i += 2)
    for (long long j = 1; j <= m; j++)
      pw[j][i] = (pw[j - 1][i] + 2 * qpow(j, i)) % mod;
  for (long long x = -m; x <= m; x++) {
    long long t = sqrt(n - x * x);
    long long a = n % mod, p = t * 2 + 1;
    ans += a * (a + 1) % mod * (a + 2) % mod * p % mod;
    ans += 2 * qpow(x, 6) % mod * p % mod;
    ans += 6 * qpow(x, 4) * pw[t][2] % mod;
    ans += 6 * qpow(x, 2) * pw[t][4] % mod;
    ans += 2 * pw[t][6] % mod;
    ans -= 3 * (a + 2) *
           (qpow(x, 4) * p % mod + 2 * qpow(x, 2) * pw[t][2] % mod + pw[t][4]) %
           mod;
    ans += (3 * a + 4) * (qpow(x, 2) * p % mod + pw[t][2]) % mod;
  }
  write((ans + mod) % mod * qpow(6, mod - 2) % mod);
  return 0;
}
