#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, N = 1e6 + 10;
long long n, a[N], pw2[N], g[N], ans;
void Add(long long &x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
}
long long add(long long x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
}
void Mul(long long &x, long long y) { x = x * y % mod; }
long long mul(long long x, long long y) { return x * y % mod; }
void Sub(long long &x, long long y) {
  x += mod - y;
  if (x >= mod) x -= mod;
}
long long sub(long long x, long long y) {
  x += mod - y;
  if (x >= mod) x -= mod;
  return x;
}
long long qpow(long long a, long long b) {
  long long ret = 1;
  for (; b; b >>= 1, Mul(a, a))
    if (b & 1) Mul(ret, a);
  return ret;
}
struct atom {
  long long x0, x1, x2;
  void init(long long x) { x0 = 1, x1 = x, x2 = mul(x, x); }
  friend atom operator*(atom a, atom b) {
    return (atom){a.x0 + b.x0, add(mul(a.x1, pw2[b.x0]), mul(b.x1, pw2[a.x0])),
                  add(add(mul(a.x2, pw2[b.x0]), mul(b.x2, pw2[a.x0])),
                      mul(add(a.x1, a.x1), b.x1))};
  }
} f[N];
void prework(int n) {
  pw2[0] = 1;
  for (int i = 1; i <= n; i++) pw2[i] = mul(pw2[i - 1], 2);
}
int main() {
  prework(1000000);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    atom tmp;
    tmp.init(a[i]);
    f[a[i]] = f[a[i]] * tmp;
  }
  int lg = 1;
  for (int k = 0; k <= 5; k++) {
    for (int i = 999999; i >= 0; i--)
      if ((i / lg) % 10 != 9) f[i] = f[i] * f[i + lg];
    lg *= 10;
  }
  for (int i = 0; i <= 999999; i++) g[i] = f[i].x2;
  lg = 1;
  for (int k = 0; k <= 5; k++) {
    for (int i = 0; i <= 999999; i++)
      if ((i / lg) % 10 != 9) Sub(g[i], g[i + lg]);
    lg *= 10;
  }
  for (int i = 0; i <= 999999; i++) ans ^= 1ll * i * g[i];
  printf("%lld\n", ans);
  return 0;
}
