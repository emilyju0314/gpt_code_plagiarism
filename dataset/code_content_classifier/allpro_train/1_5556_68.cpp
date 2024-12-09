#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long Pow(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = res * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return res;
}
long long p[200010], pp[200010], sum[200010];
bool val[200010];
set<int> se;
long long solve(int l, int r) {
  return (sum[r - 1] - sum[l - 2] + MOD) * Pow(pp[r], MOD - 2) % MOD;
}
int main() {
  const long long P100 = Pow(100, MOD - 2);
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &p[i]);
    p[i] = p[i] * P100 % MOD;
  }
  p[0] = pp[0] = sum[0] = 1;
  for (int i = 1; i <= n; i++) {
    pp[i] = pp[i - 1] * p[i] % MOD;
    sum[i] = sum[i - 1] + pp[i];
    if (sum[i] >= MOD) sum[i] -= MOD;
  }
  se.clear();
  se.insert(1);
  se.insert(n + 1);
  long long res = solve(1, n);
  while (q--) {
    int x;
    scanf("%d", &x);
    if (val[x]) {
      se.erase(x);
      auto r = se.upper_bound(x);
      auto l = r;
      l--;
      val[x] = 0;
      res = (res - solve(*l, x - 1) + MOD - solve(x, (*r) - 1) + MOD +
             solve(*l, (*r) - 1)) %
            MOD;
    } else {
      auto r = se.upper_bound(x);
      auto l = r;
      l--;
      val[x] = 1;
      res = (res - solve(*l, (*r) - 1) + MOD + solve(*l, x - 1) +
             solve(x, (*r) - 1)) %
            MOD;
      se.insert(x);
    }
    printf("%lld\n", res);
  }
}
