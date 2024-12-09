#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e6 + 3;
long long a[20][20], n = 10;
long long fpow(long long x, long long y, long long p) {
  long long res = 1;
  while (y) {
    if (y & 1) res = (res * x) % p;
    x = (x * x) % p;
    y >>= 1;
  }
  return res;
}
void gao() {
  for (int i = 0; i <= n - 1; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (a[j][i]) {
        swap(a[i], a[j]);
        break;
      }
    }
    if (!a[i][i]) continue;
    long long inv = fpow(a[i][i], MOD - 2, MOD);
    for (int j = i + 1; j <= n; j++) {
      if (!a[j][i]) continue;
      int p = a[j][i] * inv % MOD;
      for (int k = i; k <= n + 1; k++) {
        a[j][k] -= a[i][k] * p % MOD;
        a[j][k] = (((a[j][k] % MOD) + MOD) % MOD);
      }
    }
  }
  for (int i = n; i > 0; i--) {
    a[i][n + 1] = a[i][n + 1] * fpow(a[i][i], MOD - 2, MOD) % MOD;
    a[i][i] = 1;
    for (int j = i - 1; j >= 0; j--) {
      if (!a[j][i]) continue;
      long long p = a[j][i];
      a[j][i] -= p;
      a[j][n + 1] -= 1LL * a[i][n + 1] * p % MOD;
      a[j][n + 1] = (((a[j][n + 1] % MOD) + MOD) % MOD);
      a[j][i] = (a[j][i] % MOD + MOD) % MOD;
    }
  }
}
bool ok(int x) {
  long long res = 0, tmp = 1;
  for (int i = 0; i <= n; i++) {
    res += tmp * a[i][n + 1] % MOD;
    res %= MOD;
    tmp = tmp * (1LL * x) % MOD;
  }
  return res == 0;
}
int main() {
  for (int i = 0; i <= n; i++) {
    printf("? %d \n", i);
    fflush(stdout);
    scanf("%lld", &a[i][n + 1]);
    a[i][0] = 1;
    for (int j = 1; j <= n; j++) a[i][j] = (a[i][j - 1] * i) % MOD;
  }
  gao();
  int ans = -1;
  for (int i = 0; i <= MOD - 1; i++) {
    if (ok(i)) {
      ans = i;
      break;
    }
  }
  printf("! %d \n", ans);
  fflush(stdout);
}
