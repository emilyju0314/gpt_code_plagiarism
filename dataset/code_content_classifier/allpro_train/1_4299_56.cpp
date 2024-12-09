#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-10;
int dcmp(double x) {
  if (fabs(x) < eps)
    return 0;
  else
    return x < 0 ? -1 : 1;
}
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 5;
const long long MOD = 1e9 + 7;
long long a[N], b[N], fac[N];
long long quick_pow(long long n, long long m) {
  long long ret = 1;
  while (m) {
    if (m & 1) ret = ret * n % MOD;
    n = n * n % MOD;
    m >>= 1;
  }
  return ret;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%I64d", &a[i]), b[i] = a[i];
  if (n == 1) {
    printf("%I64d\n", a[0]);
    return 0;
  }
  if (n & 1) {
    n--;
    int op = 0;
    for (int i = 0; i < n; i++) {
      if (!op)
        a[i] = (b[i] + b[i + 1]) % MOD;
      else
        a[i] = (b[i] - b[i + 1] + MOD) % MOD;
      op ^= 1;
    }
  }
  n = n / 2 - 1;
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * (long long)i % MOD;
  long long ans1 = 0, ans2 = 0;
  for (int i = 0; i <= n; i++) {
    long long tmp =
        fac[n] * quick_pow(fac[i] * fac[n - i] % MOD, MOD - 2) % MOD;
    (ans1 += tmp * a[i * 2] % MOD) %= MOD;
    (ans2 += tmp * a[i * 2 + 1] % MOD) %= MOD;
  }
  if (n % 2)
    ans1 = (ans1 - ans2 + MOD) % MOD;
  else
    ans1 = (ans1 + ans2) % MOD;
  cout << ans1 << endl;
  return 0;
}
