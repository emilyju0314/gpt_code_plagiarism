#include <bits/stdc++.h>
using namespace std;
const int N = 305;
const int MOD = 1e9 + 7;
int n, tot, m;
int a[N], f[N][N], fac[N], C[N][N], cnt[N];
bool vis[N];
inline void prepare() {
  for (int i = (0); i <= (N - 1); i++) C[i][0] = 1;
  for (int i = (1); i <= (N - 1); i++)
    for (int j = (1); j <= (i); j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
  fac[0] = 1;
  for (int i = (1); i <= (N - 1); i++) fac[i] = 1LL * fac[i - 1] * i % MOD;
}
inline bool check(long long x) { return floor(sqrt(x)) == sqrt(x); }
int main() {
  scanf("%d", &n);
  prepare();
  for (int i = (1); i <= (n); i++) scanf("%d", &a[i]);
  for (int i = (1); i <= (n); i++) {
    if (vis[i]) continue;
    vis[i] = 1;
    cnt[++tot] = 1;
    for (int j = (i + 1); j <= (n); j++)
      if (check(1LL * a[i] * a[j])) vis[j] = 1, cnt[tot]++;
  }
  f[1][cnt[1] - 1] = 1;
  m = cnt[1];
  for (int i = (2); i <= (tot); i++) {
    for (int j = (0); j <= (m - 1); j++)
      for (int k = (1); k <= (cnt[i]); k++)
        for (int p = (0); p <= (k); p++) {
          if (p > j) break;
          f[i][j + cnt[i] - k - p] += 1LL * f[i - 1][j] * C[cnt[i] - 1][k - 1] %
                                      MOD * C[j][p] % MOD *
                                      C[m - 1 - j + 2][k - p] % MOD;
          f[i][j + cnt[i] - k - p] %= MOD;
        }
    m += cnt[i];
  }
  int ans = f[tot][0];
  for (int i = (1); i <= (tot); i++) ans = 1LL * ans * fac[cnt[i]] % MOD;
  printf("%d\n", ans);
  return 0;
}
