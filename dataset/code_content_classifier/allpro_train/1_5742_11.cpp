#include <bits/stdc++.h>
using namespace std;
const int inf = 0x20202020;
const int mod = 1000000007;
template <class T>
inline void read(T& x) {
  bool fu = 0;
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') fu = 1, c = getchar();
  for (x = 0; c > 32; c = getchar()) x = x * 10 + c - '0';
  if (fu) x = -x;
};
template <class T>
inline void read(T& x, T& y) {
  read(x);
  read(y);
}
template <class T>
inline void read(T& x, T& y, T& z) {
  read(x);
  read(y);
  read(z);
}
template <class T>
inline void read(T& x, T& y, T& z, T& q) {
  read(x);
  read(y);
  read(z);
  read(q);
}
const int DX[] = {1, 0, -1, 0}, DY[] = {0, 1, 0, -1};
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long powmod(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
const int N = 2222, M = 111111;
int l, m, n, t, C, mu[N], a, b, c, f[N][N];
unsigned int count(int x, int y) {
  if (f[x][y]) return f[x][y];
  unsigned int ans = 0;
  for (int _tmp = x, i = 1; i <= _tmp; ++i)
    if (gcd(i, y) == 1) ans += x / i;
  return f[x][y] = ans;
}
int main() {
  scanf("%d%d%d", &a, &b, &c);
  mu[1] = 1;
  for (int _tmp = 2000, i = 2; i <= _tmp; ++i)
    for (int _tmp = i - 1, j = 1; j <= _tmp; ++j)
      if (i % j == 0) mu[i] -= mu[j];
  unsigned int ans = 0;
  for (int _tmp = a, i = 1; i <= _tmp; ++i)
    for (int _tmp = min(b, c), x = 1; x <= _tmp; ++x)
      if (gcd(i, x) == 1)
        ans += mu[x] * (a / i) * count(b / x, i) * count(c / x, i);
  printf("%u\n", ans % (1 << 30));
  return 0;
}
