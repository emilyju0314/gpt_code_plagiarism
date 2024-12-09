#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int mod = 998244353;
const int G = 3;
const int iG = (mod + 1) / 3;
inline int ksm(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = 1ll * res * x % mod;
    x = 1ll * x * x % mod;
    y >>= 1;
  }
  return res;
}
int n, m, len = 1, tr[maxn];
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * f;
}
inline void ntt(int *f, int len, int flag) {
  for (int i = 0; i < len; i++)
    if (i < tr[i]) swap(f[i], f[tr[i]]);
  for (int p = 2; p <= len; p <<= 1) {
    int l = p >> 1, w = ksm(flag ? G : iG, (mod - 1) / p);
    for (int i = 0; i < len; i += p) {
      int wi = 1;
      for (int j = i; j < i + l; j++) {
        int t = 1ll * wi * f[j + l] % mod;
        f[j + l] = (f[j] - t + mod) % mod;
        f[j] = (f[j] + t) % mod;
        wi = 1ll * w * wi % mod;
      }
    }
  }
  if (!flag) {
    int iv = ksm(len, mod - 2);
    for (int i = 0; i < len; i++) f[i] = 1ll * f[i] * iv % mod;
  }
}
int f[3][maxn], g[5][maxn];
inline void shift() {
  ntt(f[0], len, 1), ntt(f[1], len, 1), ntt(f[2], len, 1);
  for (int i = 0; i < len; i++) {
    g[0][i] = 1ll * f[0][i] * f[0][i] % mod;
    g[1][i] = 1ll * f[1][i] * f[1][i] % mod;
    g[2][i] = 1ll * f[2][i] * f[2][i] % mod;
    g[3][i] = 1ll * f[0][i] * f[1][i] % mod;
    g[4][i] = 1ll * f[1][i] * f[2][i] % mod;
  }
  ntt(g[0], len, 0), ntt(g[1], len, 0), ntt(g[2], len, 0);
  ntt(g[3], len, 0), ntt(g[4], len, 0);
  f[0][0] = g[0][0];
  f[1][0] = g[3][0];
  f[2][0] = g[1][0];
  for (int i = 1; i <= m; i++) {
    f[0][i] = (g[0][i] + g[1][i - 1]) % mod;
    f[1][i] = (g[3][i] + g[4][i - 1]) % mod;
    f[2][i] = (g[1][i] + g[2][i - 1]) % mod;
  }
  for (int i = m + 1; i < len; i++) f[0][i] = f[1][i] = f[2][i] = 0;
}
inline void setbit() {
  for (int i = 0; i <= m; i++) f[2][i] = f[1][i], f[1][i] = f[0][i];
  f[0][0] = 1;
  for (int i = 1; i <= m; i++)
    f[0][i] = ((f[1][i] + f[1][i - 1]) % mod + f[2][i - 1]) % mod;
}
int main() {
  n = read(), m = read();
  f[0][0] = f[0][1] = f[1][0] = 1;
  for (; len <= m + m + 10; len <<= 1)
    ;
  for (int i = 0; i < len; i++)
    tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? len >> 1 : 0);
  for (int i = log2(n) - 1; ~i; --i) {
    shift();
    if (n >> i & 1) setbit();
  }
  for (int i = 1; i <= m; i++) printf("%d ", f[0][i]);
  puts("");
  return 0;
}
