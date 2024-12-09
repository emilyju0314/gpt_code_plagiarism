#include <bits/stdc++.h>
using namespace std;
long long n, m, t, ans, a, b, c, h[100005], s[100005], adv, tmp;
signed main() {
  scanf("%lld%lld%lld%lld", &n, &a, &b, &c);
  for (long long i = 1; i <= n; i++) scanf("%lld", h + i);
  sort(h + 1, h + n + 1), ans = 0;
  for (long long i = 1; i <= n; i++) s[i] = s[i - 1] + h[i];
  adv = s[n] / n;
  for (long long i = 1; i <= n; i++)
    if (h[i] <= adv) ans += adv - h[i];
  ans *= c, ans += (s[n] - adv * n) * b, tmp = ans, ans = 0, adv++;
  for (long long i = 1; i <= n; i++)
    if (h[i] >= adv) ans += h[i] - adv;
  ans *= c, ans += (adv * n - s[n]) * a, ans = min(ans, tmp), tmp = 0;
  for (long long i = 1; i <= n; i++) {
    long long l = h[i] * (i - 1) - s[i - 1], r = s[n] - s[i] - h[i] * (n - i);
    if (l < r)
      ans = min(ans, l * c + (r - l) * b);
    else
      ans = min(ans, r * c + (l - r) * a);
  }
  for (long long i = 1; i <= n; i++) tmp += h[n] - h[i];
  ans = min(ans, tmp * a), tmp = 0;
  for (long long i = 1; i <= n; i++) tmp += h[i] - h[1];
  ans = min(ans, tmp * b);
  for (long long i = 1; i <= n; i++) {
    long long l = h[i] * (i - 1) - s[i - 1], r = s[n] - s[i] - h[i] * (n - i);
    ans = min(ans, l * a + r * b);
  }
  return printf("%lld\n", ans), 0;
}
