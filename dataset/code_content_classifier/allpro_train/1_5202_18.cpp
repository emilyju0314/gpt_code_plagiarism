#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5005;
const ll mod = 998244353;
int n, m, a[N], num[N];
ll ans, inv[N], f[N][N];
int main() {
  inv[1] = 1;
  for (int i = 2; i <= 5000; ++i) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i), ++num[a[i]];
  sort(a + 1, a + 1 + n);
  m = unique(a + 1, a + 1 + n) - a - 1;
  for (int j = 0; j < m; ++j) f[0][j] = 1;
  for (int i = 1; i <= m; ++i)
    for (int j = i; j <= m; ++j) {
      f[i][j] = f[i - 1][j - 1] * inv[n - i + 1] % mod * num[a[j]] % mod;
      (ans += f[i][j] * inv[n - i] % mod * (num[a[j]] - 1) % mod) %= mod;
      (f[i][j] += f[i][j - 1]) %= mod;
    }
  printf("%lld\n", ans);
  return 0;
}
