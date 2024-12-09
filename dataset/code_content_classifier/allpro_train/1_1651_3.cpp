#include <bits/stdc++.h>
using namespace std;
long long n, l, r, tot, x, y, d, rd, ans = -1;
inline long long gt(long long x, long long y) {
  if (x == 0) return 0;
  return x > 0 ? ((x - 1) / y + 1) : (x / y);
}
inline long long ft(long long x, long long y) {
  if (x == 0) return 0;
  return x > 0 ? (x / y) : ((x + 1) / y - 1);
}
int main() {
  long long i, j, res, sum;
  scanf("%I64d%I64d%I64d%I64d", &n, &l, &r, &tot);
  d = l <= r ? (r - l + 1) : (r + n - l + 1);
  rd = n - d;
  if (n <= 5000) {
    for (i = 0; i <= d; ++i)
      for (j = 0; j <= rd; ++j) {
        sum = n + i + j;
        res = (tot - 1) % sum + 1;
        if (res == d + i)
          ans = max(ans, i + j);
        else if (i && res == d + i - 1)
          ans = max(ans, i + j);
      }
  } else {
    long long lim = tot / n, dd = d << 1, mn, mx;
    if (tot + 1 >= d && tot + 1 <= dd)
      ans = max(ans, tot + 1 - d + rd);
    else if (tot >= d && tot <= dd)
      ans = max(ans, tot - d + rd);
    for (i = 1; i <= lim; ++i) {
      res = tot - (i + 1) * d - i * rd;
      if (res >= 0) {
        x = res % i;
        y = res / i - x;
        mx = min(ft(x, i), ft(rd - y, i + 1));
        mn = max(gt(x - d, i), gt(-y, i + 1));
        if (mn <= mx) ans = max(ans, (res - x) / i + mx);
      }
      res++;
      if (res >= 0) {
        x = res % i;
        y = res / i - x;
        mx = min(ft(x - 1, i), ft(rd - y, i + 1));
        mn = max(gt(x - d, i), gt(-y, i + 1));
        if (mn <= mx) ans = max(ans, (res - x) / i + mx);
      }
    }
  }
  printf("%I64d", ans);
  return 0;
}
