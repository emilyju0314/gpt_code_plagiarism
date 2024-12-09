#include <bits/stdc++.h>
using namespace std;
const int N = 2.5e5 + 5;
int n, k, p;
long long ans = 1;
int f[N][27], fac[N], inv[N];
inline long long qpow(long long a, long long b) {
  long long res = 1;
  for (; b; b >>= 1, a = a * a % p)
    if (b & 1) res = res * a % p;
  return res;
}
inline void add(int &x, int y) {
  x += y;
  if (x >= p) x -= p;
}
inline void init() {
  fac[0] = 1;
  for (int i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % p;
  inv[N - 1] = qpow(fac[N - 1], p - 2);
  for (int i = N - 2; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % p;
}
int dfs(int S, int c) {
  if (c < 0) return 0;
  if (f[S][c] != -1) return f[S][c];
  if (!S) {
    return f[S][c] = 1ll * fac[k] * inv[c] % p;
  }
  f[S][c] = 0;
  int s = S - (S & -S);
  for (int T = s;; T = (T - 1) & s) {
    add(f[S][c], 1ll * inv[S - T] * dfs(T, c - 1) % p);
    if (!T) break;
  }
  return f[S][c];
}
int main() {
  scanf("%d%d%d", &n, &k, &p);
  ans = qpow(k, n);
  if (n % 2 == 1) {
    printf("%lld", ans);
    return 0;
  }
  init();
  memset(f, -1, sizeof(f));
  ans = (ans - 1ll * dfs(n, k) * fac[n] % p + p) % p;
  printf("%lld", ans);
  return 0;
}
