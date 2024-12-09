#include <bits/stdc++.h>
using namespace std;
long long n, m, q, b[100010];
long long t[100010], suma = 0, ans;
int main() {
  long long i, x, l, r, pos;
  scanf("%lld%lld%lld", &n, &m, &q);
  for (i = 1; i <= n; i++) {
    scanf("%lld", &x);
    if (i & 1)
      suma += x;
    else
      suma -= x;
  }
  for (i = 1; i <= m; i++) scanf("%lld", &b[i]);
  for (i = 1; i <= n; i++)
    if (i & 1)
      t[0] += b[i];
    else
      t[0] -= b[i];
  for (i = 1; i <= m - n; i++)
    if (n & 1)
      t[i] = -(t[i - 1] - b[i]) + b[i + n];
    else
      t[i] = -(t[i - 1] - b[i]) - b[i + n];
  t[m - n + 1] = 999999999999999999LL;
  sort(t, t + m - n + 1);
  pos = lower_bound(t, t + m - n + 1, suma) - t;
  ans = abs(suma - t[pos]);
  if (pos) ans = min(ans, abs(suma - t[pos - 1]));
  printf("%lld\n", ans);
  for (long long times = 0; times < q; times++) {
    scanf("%lld%lld%lld", &l, &r, &x);
    if ((r - l + 1) & 1) {
      if (r & 1)
        suma += x;
      else
        suma -= x;
    }
    pos = lower_bound(t, t + m - n + 1, suma) - t;
    ans = abs(suma - t[pos]);
    if (pos) ans = min(ans, abs(suma - t[pos - 1]));
    printf("%lld\n", ans);
  }
}
