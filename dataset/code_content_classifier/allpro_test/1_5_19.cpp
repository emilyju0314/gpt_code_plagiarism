#include <bits/stdc++.h>
constexpr int Maxn = 1e5 + 7;
constexpr int Mod = 1e9 + 7;
int fac[Maxn], ifac[Maxn];
inline int fpm(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1LL * res * a % Mod;
    a = 1LL * a * a % Mod;
    b >>= 1;
  }
  return res;
}
inline int C(int n, int m) {
  if (n < 0 || m < 0 || n < m) return 0;
  return 1LL * fac[n] * ifac[m] % Mod * ifac[n - m] % Mod;
}
std::unordered_map<int, int> cnt, mp;
int n, m, k, f[Maxn], p[Maxn], s[Maxn];
int solve(int x) {
  if (mp.count(x)) return mp[x];
  int res = 0;
  for (int i = 0; i <= m; ++i) res = (res + 1LL * p[i] * s[i + x] % Mod) % Mod;
  return mp[x] = res;
}
int main() {
  scanf("%d%d", &n, &k);
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = 1LL * i * fac[i - 1] % Mod;
  ifac[n] = fpm(fac[n], Mod - 2);
  for (int i = n - 1; i >= 0; --i) ifac[i] = 1LL * (i + 1) * ifac[i + 1] % Mod;
  for (int i = 1, x; i <= n; ++i) {
    scanf("%d", &x);
    ++cnt[x];
  }
  f[0] = k - 1;
  for (int i = 1; i < n; ++i) {
    int p = 1LL * i * fpm(n, Mod - 2) % Mod;
    int q = 1LL * (n - i) * fpm(n, Mod - 2) % Mod * fpm(k - 1, Mod - 2) % Mod;
    f[i] = (1LL * p * f[i - 1] % Mod + 1) * fpm(q, Mod - 2) % Mod;
  }
  for (int i = n; i; --i) s[i - 1] = (s[i] + f[i - 1]) % Mod;
  m = cnt[-1];
  for (int i = 0; i <= m; ++i)
    p[i] =
        1LL * C(m, i) * fpm(k - 1, m - i) % Mod * fpm(fpm(k, m), Mod - 2) % Mod;
  int res = 0, tot = k;
  for (auto x : cnt)
    if (x.first != -1) {
      res = (res + solve(x.second)) % Mod;
      --tot;
    }
  res = (res + 1LL * tot * solve(0) % Mod) % Mod;
  res = (res - 1LL * (k - 1) * s[0] % Mod + Mod) % Mod;
  printf("%d\n", 1LL * res * fpm(k - 1, Mod - 2) % Mod);
}
