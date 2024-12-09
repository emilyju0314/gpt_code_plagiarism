#include <bits/stdc++.h>
using namespace std;
const int N = 3010;
const int mod = 998244353;
int gi() {
  int x = 0, o = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
int n, c, a[N];
int qpow(int a, int b) {
  int ret = 1;
  while (b) {
    if (b & 1) ret = 1ll * ret * a % mod;
    a = 1ll * a * a % mod, b >>= 1;
  }
  return ret;
}
void inc(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
namespace T1 {
int f[N][N], s[N], ans[N], v[N], iv[N];
void solve() {
  for (int i = 0; i <= n; i++)
    v[i] = qpow(2, i) - 1, iv[i] = qpow(v[i], mod - 2);
  f[0][0] = 1;
  for (int i = 0; i <= n; i++) {
    memset(s, 0, sizeof(s));
    int all = v[n - i] + 1, prd = 1, tt = 0;
    for (int j = i + 1; j <= n; j++) {
      int x = ++s[a[j]];
      if (x > 1)
        prd = 1ll * prd * iv[x - 1] % mod * v[x] % mod;
      else
        ++tt;
      if (tt == c) {
        prd = 1ll * prd * iv[x] % mod;
        all = (all + 1ll * (mod - prd) * (v[n - j] + 1)) % mod;
        for (int k = 0; k <= i / c; k++)
          f[j][k + 1] = (f[j][k + 1] + 1ll * prd * f[i][k]) % mod;
        prd = 1ll * prd * v[x] % mod;
      }
    }
    for (int j = 0; j <= i / c; j++)
      ans[j] = (ans[j] + 1ll * f[i][j] * all) % mod;
  }
  ans[0] = (ans[0] - 1 + mod) % mod;
  for (int i = 0; i <= n; i++) cout << ans[i] << ' ';
}
}  // namespace T1
namespace T2 {
int f[2][N][1 << 12], m;
void solve() {
  f[0][0][0] = 1;
  m = (1 << c) - 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i / c; j++)
      for (int k = 0; k < m; k++) f[i & 1][j][k] = 0;
    for (int j = 0; j <= i / c; j++)
      for (int k = 0; k < m; k++) {
        if (!f[i & 1 ^ 1][j][k]) continue;
        inc(f[i & 1][j][k], f[i & 1 ^ 1][j][k]);
        int t = k | (1 << (a[i] - 1));
        inc(f[i & 1][j + (t == m)][t == m ? 0 : t], f[i & 1 ^ 1][j][k]);
      }
  }
  for (int j = 0; j <= n; j++) {
    int ans = 0;
    for (int k = 0; k < m; k++) ans = (ans + f[n & 1][j][k]) % mod;
    if (!j) ans = (ans - 1 + mod) % mod;
    cout << ans << ' ';
  }
}
}  // namespace T2
int main() {
  cin >> n >> c;
  for (int i = 1; i <= n; i++) a[i] = gi();
  if (c <= 12)
    T2::solve();
  else
    T1::solve();
  return 0;
}
