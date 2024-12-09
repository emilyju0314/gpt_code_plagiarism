#include <bits/stdc++.h>
using namespace std;
int const N = 1e6 + 41;
int const MOD = 1e9 + 7;
int n, m, f[N], invF[N], ans;
int bp(int x, int d) {
  if (!d) {
    return 1;
  }
  if (d & 1) {
    return x * 1LL * bp(x, d - 1) % MOD;
  }
  int r = bp(x, d / 2);
  return r * 1LL * r % MOD;
}
void fact() {
  f[0] = 1;
  invF[0] = 1;
  for (int i = 1; i < N; ++i) {
    f[i] = f[i - 1] * 1LL * i % MOD;
    invF[i] = bp(f[i], MOD - 2);
  }
}
int getC(int k, int n) {
  int fn = f[n];
  int fk = invF[k];
  int fnk = invF[n - k];
  return fn * 1LL * fk % MOD * 1LL * fnk % MOD;
}
int main() {
  fact();
  scanf("%d%d", &n, &m);
  int curC = 1;
  int lastC = 0;
  ans = bp(m, n);
  for (int i = 1; i <= n; ++i) {
    curC = lastC + getC(i - 1, n - 1);
    curC %= MOD;
    ans += curC * 1LL * bp(m, i) % MOD * 1LL * bp(m - 1, n - i) % MOD;
    ans %= MOD;
    lastC = getC(i - 1, n - 1);
  }
  printf("%d\n", ans);
  return 0;
}
