#include <bits/stdc++.h>
using namespace std;
long long n, m, ans, u, v, sum;
long long a[100005], s[100005];
long long gcd(long long xx, long long yy) {
  long long r = xx % yy;
  if (r == 0)
    return yy;
  else
    return gcd(yy, r);
}
void solve() {
  long long i, j, g;
  u = 0;
  s[1] = 0;
  for (i = 2; i <= n; i++) {
    s[i] = s[i - 1] + (i - 1) * fabs(a[i] * 1.0 - a[i - 1]);
    u += s[i];
  }
  u = 2 * u + sum;
  v = n;
  g = gcd(u, v);
  u /= g;
  v /= g;
}
int main() {
  long long i, j;
  while (~scanf("%I64d", &n)) {
    sum = 0;
    for (i = 1; i <= n; i++) {
      scanf("%I64d", &a[i]);
      sum += a[i];
    }
    sort(a + 1, a + n + 1);
    solve();
    printf("%I64d %I64d\n", u, v);
  }
  return 0;
}
