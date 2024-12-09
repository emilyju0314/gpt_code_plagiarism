#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 2e6 + 5, INF = 1e9;
int mod = 1e9 + 7;
const long long linf = 1e18;
const double eps = 1e-8, pi = acos(-1);
inline int gmin(int &a, int b) {
  if (a > b) a = b;
}
inline long long gmin(long long &a, long long b) {
  if (a > b) a = b;
}
inline int gmax(int &a, int b) {
  if (a < b) a = b;
}
inline long long gmax(long long &a, long long b) {
  if (a < b) a = b;
}
inline void read(long long &x) {
  long long f = 1, t = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    t = t * 10 + ch - '0';
    ch = getchar();
  }
  x = t * f;
}
inline long long read(long long &x, long long &y) {
  read(x);
  read(y);
}
inline void read(int &x) {
  int f = 1, t = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    t = t * 10 + ch - '0';
    ch = getchar();
  }
  x = t * f;
}
inline int read(int &x, int &y) {
  read(x);
  read(y);
}
inline void read(int &a, int &b, int &c) {
  read(a);
  read(b);
  read(c);
}
inline void read(long long &a, long long &b, long long &c) {
  read(a);
  read(b);
  read(c);
}
inline int read() {
  int x;
  read(x);
  return x;
}
inline long long qpow(long long a, long long b, long long p) {
  long long ret = 1;
  for (; b; b >>= 1, a = a * a % p)
    if (b & 1) ret = ret * a % p;
  return ret;
}
inline long long qpow(long long a, long long b) {
  long long ret = 1;
  for (; b; b >>= 1, a = a * a % mod)
    if (b & 1) ret = ret * a % mod;
  return ret;
}
inline long long qmul(long long a, long long b, long long p) {
  long long ret = 0;
  for (; b; b >>= 1, a = (a << 1) % p)
    if (b & 1) {
      ret = ret + a;
      if (ret >= p)
        ret -= p;
      else if (ret < 0)
        ret += p;
    };
  return ret;
}
inline long long qmul(long long a, long long b) {
  long long ret = 0;
  for (; b; b >>= 1, a = (a << 1) % mod)
    if (b & 1) {
      ret = ret + a;
      if (ret >= mod)
        ret -= mod;
      else if (ret < 0)
        ret += mod;
    };
  return ret;
}
inline void judge() {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
}
inline void gen() { freopen("data.in", "w", stdout); }
int n, bin[30] = {1}, mxv;
struct cp {
  double x, y;
  inline cp() {}
  inline cp(double x, double y) : x(x), y(y) {}
  inline cp operator+(const cp &o) { return cp(x + o.x, y + o.y); }
  inline cp operator-(const cp &o) { return cp(x - o.x, y - o.y); }
  inline cp operator*(const cp &o) {
    return cp(x * o.x - y * o.y, x * o.y + y * o.x);
  }
};
int m = 1, rev[N], ans, len;
cp W[17][N];
void fft(cp a[], int n, int opt) {
  int l = 0;
  for (int o = 1; o < n; o <<= 1) l++;
  for (int i = (0); i < (n); i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (l - 1));
  for (int i = (0); i < (n); i++)
    if (rev[i] < i) swap(a[i], a[rev[i]]);
  for (int i = 1, t = 1; i < n; i <<= 1, t++) {
    for (int j = 0; j < n; j += i + i) {
      for (int k = (0); k < (i); k++) {
        cp w = W[t][k];
        w.y *= opt;
        cp x = a[j + k], y = a[j + k + i] * w;
        a[j + k] = x + y;
        a[j + k + i] = x - y;
      }
    }
  }
  if (opt == -1)
    for (int i = (0); i < (n); i++) a[i].x /= n;
}
cp a[3][N], b[2][N];
long long f[2][N], g[2][N];
void calc(int mx) {
  f[0][0] = 1;
  for (int j = (30); j >= (0); j--)
    if ((1 << (j)) <= mx) {
      for (int p = (0); p < (2); p++)
        for (int i = (0); i < (m); i++) a[p][i] = cp(f[p][i], 0);
      for (int i = (0); i < (m); i++)
        a[2][i] = cp((f[0][i] + f[1][i]) % mod, 0);
      fft(a[0], m, 1);
      fft(a[1], m, 1);
      fft(a[2], m, 1);
      int tmp = (mx >> (j + 1)) & 1;
      for (int p = (0); p < (2); p++)
        for (int i = (0); i < (m); i++) b[p][i] = a[2][i] * a[p ^ tmp][i];
      fft(b[0], m, -1);
      fft(b[1], m, -1);
      for (int i = (0); i <= (n); i++) g[0][i] = f[0][i], g[1][i] = f[1][i];
      for (int i = (0); i <= (n); i++)
        f[0][i] = (long long)(b[0][i].x + 0.5) % mod,
        f[1][i] = (long long)(b[1][i].x + 0.5) % mod;
      for (int i = (0); i <= (n); i++)
        f[0][i] = (f[0][i] + g[0][i]) % mod,
        f[1][i] = (f[1][i] + g[1][i]) % mod;
      for (int i = (0); i <= (n); i++)
        f[tmp][i] = (f[tmp][i] + mod * 2 - (g[0][i] + g[1][i]) % mod) % mod;
      int tt = (mx >> j) & 1;
      if (tt)
        for (int i = (n); i >= (1); i--)
          (f[tt][i] += f[0][i - 1] + f[1][i - 1]) %= mod;
      for (int i = 1; i <= n; i += 2) ans = (ans + f[1][i]) % mod;
    }
}
int main() {
  read(n, mxv, mod);
  while (m <= n + n) m <<= 1;
  for (int i = 1, t = 1; i < m; i <<= 1, t++) {
    for (int j = (0); j < (i); j++)
      W[t][j] = cp(cos(pi * j / i), sin(pi * j / i));
  }
  calc(mxv >> 1);
  cout << ans << endl;
}
