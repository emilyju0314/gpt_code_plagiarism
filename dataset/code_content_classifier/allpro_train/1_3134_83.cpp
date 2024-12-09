#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, conl[25], conr[25];
long long a[300010], c[300010][41], fac[300010], inv[300010], ans, s[300010],
    t[300010];
inline long long C(int n, int m) {
  if (n < 0 || m < 0 || n > m) return 0;
  return fac[m] * inv[n] % 998244353 * inv[m - n] % 998244353;
}
inline long long ksm(long long x, int y) {
  long long res = 1;
  while (y) {
    if (y & 1) res *= x, res %= 998244353;
    x *= x, x %= 998244353;
    y >>= 1;
  }
  return res;
}
inline void init() {
  fac[0] = fac[1] = 1;
  for (register int i = 2; i <= n; ++i)
    fac[i] = 1ll * i * fac[i - 1] % 998244353;
  for (register int i = 0; i <= n; ++i) inv[i] = ksm(fac[i], 998244353 - 2);
}
int main() {
  cin >> n >> m;
  init();
  for (register int i = 1; i <= n; ++i)
    cin >> s[i] >> t[i], a[s[i]]++, a[t[i] + 1]--;
  for (register int i = 1; i <= m; ++i) cin >> conl[i] >> conr[i];
  for (register int i = 1; i <= n; ++i) a[i] += a[i - 1];
  for (register int j = 0; j <= 2 * m; ++j) {
    for (register int i = 1; i <= n; ++i) {
      if (i >= j && a[i] >= j && a[i] >= i) c[i][j] = C(i - j, a[i] - j);
      c[i][j] += c[i - 1][j];
    }
  }
  for (register int i = 0; i < (1 << m); ++i) {
    long long boul = 1, bour = n;
    long long num = 0, cnt = 0;
    map<int, int> vis;
    for (register int j = 1; j <= m; ++j) {
      if (i & (1 << (j - 1))) {
        int l = conl[j], r = conr[j];
        if (vis.find(l) == vis.end())
          num++, boul = max(boul, s[l]), bour = min(bour, t[l]), vis[l] = 1;
        if (vis.find(r) == vis.end())
          num++, bour = min(bour, t[r]), boul = max(boul, s[r]), vis[r] = 1;
        cnt++;
      }
    }
    long long add = 0;
    if (boul <= bour)
      add = (c[bour][num] - c[boul - 1][num] + 998244353) % 998244353;
    if (cnt & 1)
      ans = (ans - add + 998244353) % 998244353;
    else
      ans = (ans + add) % 998244353;
  }
  cout << ans;
  return 0;
}
