#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000005;
const int MOD = 1000000007;
int modexpo(long long b, int e, int m) {
  long long ans = 1;
  for (; e; e /= 2, b = (b * b) % m) {
    if (e & 1) {
      ans = (ans * b) % m;
    }
  }
  return ans;
}
int f[MAX], fac[MAX], ifac[MAX];
int c(int n, int k) {
  long long ans = fac[n];
  long long den = ((long long)ifac[k] * (long long)ifac[n - k]) % MOD;
  return (ans * den) % MOD;
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  fac[0] = 1;
  for (int i = 1; i < MAX; i++) {
    fac[i] = ((long long)fac[i - 1] * (long long)i) % MOD;
  }
  ifac[MAX - 1] = modexpo(fac[MAX - 1], MOD - 2, MOD);
  for (int i = MAX - 2; ~i; i--) {
    ifac[i] = ((long long)ifac[i + 1] * (long long)(i + 1)) % MOD;
  }
  for (int i = k + 1; i <= n; i++) {
    long long end_before_i = ((long long)i * (long long)f[i - 1]) % MOD;
    long long end_after_0 = (fac[i - k - 1] - f[i - k - 1] + MOD) % MOD;
    long long end_after_1 =
        ((long long)c(i - 1, i - k - 1) * (long long)fac[k]) % MOD;
    f[i] = (end_before_i + (end_after_0 * end_after_1)) % MOD;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    long long part = (long long)f[i - 1] * (long long)c(n - 1, i - 1);
    part %= MOD;
    ans += (long long)part * (long long)fac[n - i];
    ans %= MOD;
  }
  printf("%d\n", (int)ans);
}
